#! /usr/bin/python

import tkinter as tk
from tkinter import filedialog
from tkinter import font
from tkinter import ttk

className = input("type class name ?\n")
print(className)

parentName = input("Parent class (blank = NetworkType) ?\n")
if(parentName == ""):
    parentName = "NetworkType"
print(parentName)

type_id = input("Type id?\n")
print(type_id)

# with_serialize = input("With serialize/desirealize? (y/n) (blank = yes)\n")

attributes = []
is_continue = input("Attributes? (y/n) (blank = yes)\n")
while(is_continue == 'y' or is_continue == 'Y' or is_continue == ""):
    attributes.append(input("Type '<type> <attribute name> (blank = no more attributes)'\n"))
    if(attributes[-1] == ""):
        attributes.pop()
        break
    is_continue = input("Other attributes? (y/n) (blank = yes)\n")

root = tk.Tk()
root.option_add('*foreground', 'black')  # set all tk widgets' foreground to red
root.option_add('*activeForeground', 'black')  # set all tk widgets' foreground to red
root.withdraw()

f_config = open("NetworkTypeGenerator.config", 'r')
initial_dir = f_config.readline()
f_config.close()

file_path = filedialog.askdirectory(master=root, initialdir = initial_dir)

f_h = open(file_path + "/" + className + ".h", 'w')

f_h.write("#ifndef " + className.upper() + "_H\n")
f_h.write("#define " + className.upper() + "_H\n")
f_h.write("\n")
f_h.write("#include \"" + parentName + ".h\"\n")
f_h.write("\n")
f_h.write("class " + className + " : public " + parentName + " {\n")
f_h.write("public: \n")
f_h.write("\t// Constructor\n")
f_h.write("\t" + className + "() {};\n")
f_h.write("\t// Copy constructor\n")
f_h.write("\t" + className + "(const " + className + "& other) = default;\n")
f_h.write("\n")
f_h.write("\t// Copy operator\n")
f_h.write("\t" + className + "& operator=(const " + className + "& other) = default;\n")
f_h.write("\t// Destructor\n")
f_h.write("\t~" + className + "() = default;\n")
f_h.write("\n")
f_h.write("\t// Returns the type's id\n")
f_h.write("\tvirtual unsigned int getId() { return typeId; };\n")
f_h.write("\t// Type's id\n")
f_h.write("\tstatic const unsigned int typeId = " + type_id + ";\n")

# if(with_serialize != 'n' and with_serialize != 'N'):
if(parentName != ""):
    f_h.write("\t// Turns raw data into the usable data (type's attributes)\n")
    f_h.write("\tvirtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;\n")
    f_h.write("\t// Turns the type's attributes into raw data\n")
    f_h.write("\tvirtual bool serialize(shared_ptr<MessageDataBuffer> output) override;\n")
    f_h.write("\n")
else:
    f_h.write("\t// Turns raw data into the usable data (type's attributes)\n")
    f_h.write("\tvirtual bool deserialize(shared_ptr<MessageDataBuffer> input);\n")
    f_h.write("\t// Turns the type's attributes into raw data\n")
    f_h.write("\tvirtual bool serialize(shared_ptr<MessageDataBuffer> output);\n")
    f_h.write("\n")
for att in attributes:
    f_h.write("\t" + att + ";\n")
f_h.write("\n")
f_h.write("};\n")
f_h.write("\n")
f_h.write("#endif")

f_h.close()

f_cpp = open(file_path + "/" + className + ".cpp", 'w')

f_cpp.write("#include \"" + className +".h\"\n")
f_cpp.write("\n")
f_cpp.write("bool " + className + "::serialize(shared_ptr<MessageDataBuffer> output) {\n")
if(parentName != "NetworkType"):
    f_cpp.write("\tif(!" + parentName + "::serialize(output))\n")
    f_cpp.write("\t\treturn false;\n")
f_cpp.write("\n")
f_cpp.write("\treturn true;\n")
f_cpp.write("}\n")
f_cpp.write("\n")
f_cpp.write("bool " + className + "::deserialize(shared_ptr<MessageDataBuffer> input) {\n")
if(parentName != "NetworkType"):
    f_cpp.write("\tif(!" + parentName + "::deserialize(input))\n")
    f_cpp.write("\t\treturn false;\n")
f_cpp.write("\n")
f_cpp.write("\treturn true;\n")
f_cpp.write("}\n")

f_cpp.close()

f_config = open("NetworkTypeGenerator.config", 'w')
f_config.write(file_path)
f_config.close()