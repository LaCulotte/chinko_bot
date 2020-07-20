#! /usr/bin/python

import json
import sys
import os
from datetime import datetime

# getattr(self, "")
write_method_to_type =          {"writeFloat" : "float", "writeUnsignedInt" : "uint32_t", "writeUTF" : "string", "writeVarLong" : "uint64_t", "writeVarInt" : "int", "writeInt" : "int","writeDouble" : "double", "writeBoolean" : "bool", "writeVarShort" : "int", "writeByte" : "int", "writeShort" : "int"}
write_method_to_serialize =     {"writeFloat" : "writeFloat", "writeUnsignedInt" : "writeInt", "writeUTF" : "writeUTF", "writeVarLong" : "writeVarInt64", "writeVarInt" : "writeVarInt", "writeInt" : "writeInt","writeDouble" : "writeDouble", "writeBoolean" : "writeBool", "writeShort" : "writeShort", "writeVarShort" : "writeVarShort", "writeByte" : "writeByte"}
write_method_to_deserialize =   {"writeFloat" : "readFloat", "writeUnsignedInt" : "readInt", "writeUTF" : "readUTF", "writeVarLong" : "readVarInt64", "writeVarInt" : "readVarInt", "writeInt" : "readInt","writeDouble" : "readDouble", "writeShort" : "readShort", "writeBoolean" : "readBool", "writeVarShort" : "readVarShort", "writeByte" : "readByte"}


messages_that_dont_end_with_Message = ["ProtocolRequired", "GameRolePlayArenaInvitationCandidatesAnswer"]
protocols_to_build = []
built_protocols = set()
nb_built_protocols = 0

class MacroFunctions:
    def defineName(protocol_dict):
        return protocol_dict["name"].upper()

    def include_super(protocol_dict):
        if(protocol_dict.get("super") is not None and len(protocol_dict["super"]) > 0):
            if protocol_dict["super"] != "NetworkMessage":
                return "#include \"" + protocol_dict["super"] + ".h\""
            else:
                return "#include \"PrefixedMessage.h\""
        
        return "#include \"NetworkType.h\""

    def include_fields(protocol_dict):
        ret = ""
        includedTypes = []
        includeNetworkTypeHandler = False

        for field in protocol_dict["fields"]:
            if(field.get("self_serialize_method") and field["type"] not in includedTypes):
                ret += "#include \"" + field["type"] + ".h\"\n"
                includedTypes.append(field["type"])

                if(field.get("prefixed_by_type_id")):
                    includeNetworkTypeHandler = True
        
        if includeNetworkTypeHandler:
            ret += "\n#include \"NetworkTypeHandler.h\"\n"

        if len(ret) > 0 and ret[-1] == '\n':
            ret = ret [:-1]

        return ret

    def nameAndImplement(protocol_dict):
        ret = protocol_dict["name"] + " : public "

        if(protocol_dict.get("super") is not None and len(protocol_dict["super"]) > 0):
            if protocol_dict["super"] != "NetworkMessage":
                ret += protocol_dict["super"]
            else:
                ret += "PrefixedMessage"
        else:
            ret += "NetworkType"

        return ret

    def serialize_definition_message(protocol_dict):
        ret = "\t// Turns the message's attributes into raw data\n\tvirtual bool serialize(shared_ptr<MessageDataBuffer> output) override"
        if(len(protocol_dict["fields"]) == 0):
            ret += " { "
            if(protocol_dict.get("super_serialize") and len(protocol_dict["super"]) > 0 and protocol_dict["super"] != "NetworkMessage"):
                ret += "return " +  protocol_dict["super"] + "::serialize(output);"
            else:
                ret += "return true;"
            ret += " }"
        ret += ";"
        return ret

    def deserialize_definition_message(protocol_dict):
        ret = "\t// Turns raw data into the usable data (message's attributes)\n\tvirtual bool deserialize(shared_ptr<MessageDataBuffer> input) override"
        if(len(protocol_dict["fields"]) == 0):
            ret += " { "
            if(protocol_dict.get("super_serialize") and len(protocol_dict["super"]) > 0 and protocol_dict["super"] != "NetworkMessage"):
                ret += "return " +  protocol_dict["super"] + "::deserialize(input);"
            else:
                ret += "return true;"
            ret += " }"
        ret += ";"
        return ret
    
    def serialize_definition_type(protocol_dict):
        ret = "\t// Turns the type's attributes into raw data\n\tvirtual bool serialize(shared_ptr<MessageDataBuffer> output) override"
        if(len(protocol_dict["fields"]) == 0):
            ret += " { "
            if(protocol_dict.get("super_serialize") and len(protocol_dict["super"]) > 0 and protocol_dict["super"] != "NetworkMessage"):
                ret += "return " +  protocol_dict["super"] + "::serialize(output);"
            else:
                ret += "return true;"
            ret += " }"
        ret += ";"
        return ret

    def deserialize_definition_type(protocol_dict):
        ret = "\t// Turns raw data into the usable data (type's attributes)\n\tvirtual bool deserialize(shared_ptr<MessageDataBuffer> input) override"
        if(len(protocol_dict["fields"]) == 0):
            ret += " { "
            if(protocol_dict.get("super_serialize") and len(protocol_dict["super"]) > 0 and protocol_dict["super"] != "NetworkMessage"):
                ret += "return " +  protocol_dict["super"] + "::deserialize(input);"
            else:
                ret += "return true;"
            ret += " }"
        ret += ";"
        return ret

    def define_fields(protocol_dict):
        ret = ""

        for field in protocol_dict["fields"]:
            fieldtype = ""
            if(field.get("write_method") is not None):
                fieldtype = write_method_to_type[field["write_method"]]
            elif field["type"] == "Boolean":
                fieldtype = "bool"
            else:
                fieldtype = field["type"]

            if field.get("prefixed_by_type_id") is not None:
                fieldtype = "sp<" + fieldtype + ">"
            if field.get("is_vector") == True:
                fieldtype = "vector<" + fieldtype + ">"
                 

            ret += "\t" + fieldtype + " " + field["name"]
            if(field.get("default_value") is not None):
                ret += " = " + field["default_value"]
            
            ret += ";\n"

        if len(ret) > 0 and ret[-1] == '\n':
            ret = ret [:-1]

        return ret

    def serialize_fields(protocol_dict):
        ret = ""

        if(protocol_dict.get("super_serialize") and len(protocol_dict["super"]) > 0 and protocol_dict["super"] != "NetworkMessage"):
            ret += "\t" + protocol_dict["super"] + "::serialize(output);\n\n"

        fields = protocol_dict["fields"]
        fields.sort(key=lambda f: f["position"])

        inFlags = False
        inFlagsPosition = -1

        for field in fields:
            if(field.get("use_boolean_byte_wrapper") is not None):
                if(inFlagsPosition != -1 and field["position"] != inFlagsPosition):
                    inFlags = False
                    ret = ret[:-3] + ";\n"
                    ret += "\toutput->writeByte(flags{});\n\n".format(inFlagsPosition)
                if(not inFlags):
                    ret += "\tint flags{} = ".format(field["position"])
                    inFlags = True
                    inFlagsPosition = field["position"]
                ret += "(" + field["name"] + "<<" + str(field["boolean_byte_wrapper_position"])+ ") | "
                continue
            elif inFlags:
                ret = ret[:-3] + ";\n"
                ret += "\toutput->writeByte(flags{});\n\n".format(inFlagsPosition)
                inFlags = False
                inFlagsPosition = -1

            if(field.get("is_vector")):
                ret += MacroFunctions.serialize_field_vector(field)
            else:
                ret += MacroFunctions.serialize_field(field)

        if inFlags:
            inFlags = False
            ret = ret[:-3] + ";\n"
            ret += "\toutput->writeByte(flags{});\n\n".format(inFlagsPosition)

        return ret

    def serialize_field_vector(field):
        ret = ""
        if(field.get("constant_length") is None):
            ret += "\toutput->" + write_method_to_serialize[field["write_length_method"]] + "(" + field["name"] + ".size());\n"

        ret += "\tfor(int i = 0; i < " + field["name"] + ".size(); i++) {\n"
        ret += "\t" + "\n\t".join(MacroFunctions.serialize_field(field, field["name"] + "[i]").split("\n"))      
        ret += "}\n"  

        return ret

    def serialize_field(field, name = None):
        if(name is None):
            name = field["name"]

        if(field.get("write_method") is not None):
            return "\toutput->" + write_method_to_serialize[field["write_method"]] + "(" + name + ");\n"
        
        # Obligé NetworkType pas type de base (int, byte, double, ...)
        if(field.get("write_type_id_method") is not None):
            ret = "\toutput->" + write_method_to_serialize[field["write_type_id_method"]] + "(" + name + "->getId());\n"
            ret += "\t" + name + "->serialize(output);\n"
            return ret

        return "\t" + name + ".serialize(output);\n"
        

    def deserialize_fields(protocol_dict):
        ret = ""

        if(protocol_dict.get("super_serialize") and len(protocol_dict["super"]) > 0 and protocol_dict["super"] != "NetworkMessage"):
            ret += "\t" + protocol_dict["super"] + "::deserialize(input);\n\n"

        fields = protocol_dict["fields"]
        fields.sort(key=lambda f: f["position"])

        inFlags = False
        inFlagsPosition = -1

        for field in fields:
            if(field.get("use_boolean_byte_wrapper") is not None):
                if(inFlagsPosition != -1 and field["position"] != inFlagsPosition):
                    inFlags = False
                    ret += "\n"
                if(not inFlags):
                    ret += "\tint flags{} = input->readByte();\n".format(field["position"])
                    inFlagsPosition = field["position"]
                    inFlags = True
                ret += "\t" + field["name"] + " = flags{} & (1 << ".format(field["position"]) + str(field["boolean_byte_wrapper_position"])+ ");\n"
                continue
            elif inFlags:
                inFlags = False
                inFlagsPosition = -1
                ret += "\n"

            if(field.get("is_vector")):
                ret += MacroFunctions.deserialize_field_vector(field)
            else:
                ret += MacroFunctions.deserialize_field(field)

        return ret

    def deserialize_field_vector(field):
        ret = ""
        if(field.get("constant_length") is None):
            ret += "\tint " + field["name"] + "_size = input->" + write_method_to_deserialize[field["write_length_method"]] + "();\n"
            ret += "\tfor(int i = 0; i < " + field["name"] + "_size; i++) {\n"
        else :
            ret += "\tfor(int i = 0; i < " + str(field["constant_length"]) + "; i++) {\n"

        accronym = field["name"][:-1]

        if(field.get("write_method") is not None):
            ret += "\t\t" + write_method_to_type[field["write_method"]] + " " + accronym + ";\n\n"
        elif(field.get("prefixed_by_type_id")):
            ret += "\t\tsp<" + field["type"] + "> " + accronym + "(new " + field["type"] + "());\n\n"
        else  :
            ret += "\t\t" + field["type"] + " " + accronym + ";\n\n"

        ret += "\t" + "\n\t".join(MacroFunctions.deserialize_field(field, accronym).split("\n")) 
        ret += "\t" + field["name"] + ".push_back(" + accronym + ");\n"     
        ret += "\t}\n"  

        return ret

    def deserialize_field(field, name = None):
        if(name is None):
            name = field["name"]

        if(field.get("write_method") is not None):
            return "\t" + name + " = input->" + write_method_to_deserialize[field["write_method"]] + "();\n"
        
        # Obligé NetworkType pas type de base (int, byte, double, ...)
        if(field.get("write_type_id_method") is not None):
            ret = "\tint " + name + "_TypeId = input->" + write_method_to_deserialize[field["write_type_id_method"]] + "();\n"
            ret += "\t" + name + " = dynamic_pointer_cast<" + field["type"] + ">(NetworkTypeHandler::getInstance()->getTypeById(" + name + "_TypeId));\n\n"
            ret += "\tif(!" + name + " || !" + name + "->deserialize(input))\n" 
            ret += "\t\treturn false;\n\n"
            return ret

        return "\tif(!" + name + ".deserialize(input))\n\t\treturn false;\n"


# Supposition : si len(fields) = 0 -> pas de cpp
class ProtocolBuilder:
    def __init__(self, output,
                 message_h_templatePath="templates/message/h_template.txt", message_cpp_templatePath="templates/message/cpp_template.txt",
                 type_h_templatePath="templates/type/h_template.txt", type_cpp_templatePath="templates/type/cpp_template.txt",
                 macros_path="templates/macros.json"):
        self.outputPath = output
        self.message_h_template = open(message_h_templatePath, 'r')
        self.message_cpp_template = open(message_cpp_templatePath, 'r')
        self.type_h_template = open(type_h_templatePath, 'r')
        self.type_cpp_template = open(type_cpp_templatePath, 'r')

        macros_file = open(macros_path, 'r')
        self.macros = json.load(macros_file)
        macros_file.close()

    def __del__(self):
        self.message_h_template.close()
        self.message_cpp_template.close()
        self.type_h_template.close()
        self.type_cpp_template.close()

    def get_protocol_dir_path(self, protocol_dict):
        protocol_dir = "/".join(protocol_dict["namespace"].split("."))
        if(protocol_dir.find("com/ankamagames/dofus/network/") == 0):
            protocol_dir = protocol_dir[len("com/ankamagames/dofus/network/"):]

        protocol_dir = self.outputPath + "/" + protocol_dir
        return protocol_dir


    def build_protocol(self, protocol_dict, h_template, cpp_template):
        h_template.seek(0)
        cpp_template.seek(0)

        # protocol_dir = "/".join(protocol_dict["namespace"].split("."))
        # if(protocol_dir.find("com/ankamagames/dofus/network/") == 0):
        #     protocol_dir = protocol_dir[len("com/ankamagames/dofus/network/"):]

        # protocol_dir = self.outputPath + "/" + protocol_dir

        protocol_dir = self.get_protocol_dir_path(protocol_dict)
        os.makedirs(protocol_dir, exist_ok=True)

        h_file = open(protocol_dir + "/" + protocol_dict["name"] + ".h", 'w')
        self.write_file(h_file, h_template, protocol_dict)
        h_file.close()

        if(len(protocol_dict["fields"]) > 0):
            cpp_file = open(protocol_dir + "/" + protocol_dict["name"] + ".cpp", 'w')
            self.write_file(cpp_file, cpp_template, protocol_dict)
            cpp_file.close()

    def write_file(self, curr_file, template, protocol_dict):
        for line in template:
            if(line[0] == '@'):
                macro = line[1:]
                if(macro[-1] == '\n'):
                    macro = macro[:-1]

                n_line = self.macro_to_string(macro, protocol_dict)
                if(len(n_line) > 0):
                    curr_file.write(n_line + "\n")
            else:
                curr_file.write(line)


    def macro_to_string(self, macro, protocol_dict):
        if(self.macros.get(macro) is None):
            print("{} is not a valid macro".format(macro))
            exit()

        format_pointers = self.macros[macro]["format"]
        format_strings = []

        for pointer in format_pointers:
            if(protocol_dict.get(pointer) is None):
                format_strings.append(getattr(MacroFunctions, pointer)(protocol_dict))
            else:
                format_strings.append(protocol_dict[pointer])

        return self.macros[macro]["string"].format(*format_strings)

    def build_message(self, protocol_dict):
        self.build_protocol(protocol_dict, self.message_h_template, self.message_cpp_template)

    def build_type(self, protocol_dict):
        self.build_protocol(protocol_dict, self.type_h_template, self.type_cpp_template)

def build_children(protocol_name, json_dict):
    global protocols_to_build
    add_childs_of = [protocol_name]
    added_childs = []
    
    while(len(add_childs_of) > 0):
        parent_name = add_childs_of[0]
        if(parent_name not in added_childs):
            for protocol in filter(lambda m : m["super"] == parent_name, json_dict["messages"]):
                protocols_to_build.append(protocol["name"])
                add_childs_of.append(protocol["name"])
            for protocol in filter(lambda m : m["super"] == parent_name, json_dict["types"]):
                protocols_to_build.append(protocol["name"])
                add_childs_of.append(protocol["name"])
            added_childs.append(parent_name)

        add_childs_of.pop(0)

def find_and_build(json_dict, protocol_name, builder):
    global nb_built_protocols
    if(protocol_name in built_protocols):
        return 

    protocol_dict = None
    isMessage = (len(protocol_name) > len("Message") and protocol_name[-len("Message"):] == "Message") or protocol_name in messages_that_dont_end_with_Message

    if (isMessage):
        protocol_dict = list(filter(lambda d : d["name"] == protocol_name, json_dict["messages"]))
    else :
        protocol_dict = list(filter(lambda d : d["name"] == protocol_name, json_dict["types"]))

    if(len(protocol_dict) <= 0):
        print(protocol_name + " is not a valid protocol.")
        return
    if(len(protocol_dict) > 1):
        print(protocol_name + " is designate multiple ({}) protocols.".format(len(protocol_dict)))
        print("Only the first one found will be built.")    
    
    protocol_dict = protocol_dict[0]

    protocol_path_h = builder.get_protocol_dir_path(protocol_dict) + "/" + protocol_name + ".h"    
    if(os.path.isfile(protocol_path_h)):
        print(protocol_name + " already exists, it will not be built.")
        return

    for field in protocol_dict["fields"]:
        if(field.get("type_namespace") != None):
            protocols_to_build.append(field["type"])
        if(field.get("write_type_id_method") is not None):
            build_children(field["type"], json_dict)
    
    if(protocol_dict["super"] not in ["NetworkMessage", ""]):
        protocols_to_build.append(protocol_dict["super"])

    print(protocol_name)
    if(isMessage):
        builder.build_message(protocol_dict)
    else:
        builder.build_type(protocol_dict)
    
    nb_built_protocols += 1
    return
    
if(len(sys.argv) != 4):
    print("usage : ./protocol_builder <protocolname> <filepath>.json <output-directory>")
    exit()

json_file = open(sys.argv[2], 'r')
# json_file = open("protocols.json", 'r')
json_dict = json.load(json_file)
json_file.close()

builder = ProtocolBuilder(sys.argv[3])

protocols_to_build.append(sys.argv[1])

while (len(protocols_to_build) > 0):
    find_and_build(json_dict, protocols_to_build[0], builder)
    built_protocols.add(protocols_to_build.pop(0))

dir_last_path = "./additionnal_strings/last/" 
dir_date_path = "./additionnal_strings/z_" + datetime.now().strftime("%d-%m-%Y_%H:%M:%S") + "/" 

os.makedirs(dir_date_path, exist_ok=True)
os.makedirs(dir_last_path, exist_ok=True)
includes_messages_file_last = open(dir_last_path + "DofusMessageTypeHandler_includes.txt", "w") 
includes_messages_file_date = open(dir_date_path + "DofusMessageTypeHandler_includes.txt", "w") 
map_messages_file_last = open(dir_last_path + "DofusMessageTypeHandler_map.txt", "w") 
map_messages_file_date = open(dir_date_path + "DofusMessageTypeHandler_map.txt", "w") 

includes_types_file_last = open(dir_last_path + "NetworkTypeHandler_includes.txt", "w") 
includes_types_file_date = open(dir_date_path + "NetworkTypeHandler_includes.txt", "w") 
map_types_file_last = open(dir_last_path + "NetworkTypeHandler_map.txt", "w") 
map_types_file_date = open(dir_date_path + "NetworkTypeHandler_map.txt", "w") 

includes_messages_list = []
map_messages_list = []
includes_types_list = []
map_types_list = []

for protocol_name in built_protocols:
    if((len(protocol_name) > len("Message") and protocol_name[-len("Message"):] == "Message") or protocol_name in messages_that_dont_end_with_Message):
        includes_messages_file_last.write("#include \"" + protocol_name + ".h\"\n")
        includes_messages_file_date.write("#include \"" + protocol_name + ".h\"\n")
        map_messages_file_last.write("\tid_to_builder[" + protocol_name + "::protocolId]\t= make_shared<" + protocol_name + ">;\n")
        map_messages_file_date.write("\tid_to_builder[" + protocol_name + "::protocolId]\t= make_shared<" + protocol_name + ">;\n")
        includes_messages_list.append("#include \"" + protocol_name + ".h\"")
        map_messages_list.append("\tid_to_builder[" + protocol_name + "::protocolId]\t= make_shared<" + protocol_name + ">;")
    else:
        includes_types_file_last.write("#include \"" + protocol_name + ".h\"\n")
        includes_types_file_date.write("#include \"" + protocol_name + ".h\"\n")
        map_types_file_last.write("\tid_to_builder[" + protocol_name + "::typeId]\t= make_shared<" + protocol_name + ">;\n")
        map_types_file_date.write("\tid_to_builder[" + protocol_name + "::typeId]\t= make_shared<" + protocol_name + ">;\n")
        includes_types_list.append("#include \"" + protocol_name + ".h\"")
        map_types_list.append("\tid_to_builder[" + protocol_name + "::typeId]\t= make_shared<" + protocol_name + ">;")

print("includes of MessageTypeHandler : ")
for s in includes_messages_list:
    print(s)
print("map of MessageTypeHandler : ")
for s in map_messages_list:
    print(s)

print("includes of NetworkTypeHandler : ")
for s in includes_types_list:
    print(s)
print("map of NetworkTypeHandler : ")
for s in map_types_list:
    print(s)

print("{} protocol built.".format(nb_built_protocols))