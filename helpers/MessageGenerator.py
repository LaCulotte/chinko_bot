#! /usr/bin/python

import tkinter as tk
from tkinter import filedialog
from tkinter import font
from tkinter import ttk

className = input("msg class name ?\n")
print(className)

parentName = input("Parent class ? (blank for PrefixedMessage)\n")
if(parentName == ""):
    parentName = "PrefixedMessage"
print(parentName)

msg_id = input("Message id?\n")
print(msg_id)

with_serialize = input("With serialize/desirealize? (y/n) (blank = yes)\n")

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

f_config = open("MessageGenerator.config", 'r')
initial_dir = f_config.readline()
f_config.close()

file_path = filedialog.askdirectory(master=root, initialdir = initial_dir)

f_h = open(file_path + "/" + className + ".h", 'w')

f_h.write("#ifndef " + "_MESSAGE".join(className.upper().split("MESSAGE")) + "_H\n")
f_h.write("#define " + "_MESSAGE".join(className.upper().split("MESSAGE")) + "_H\n")
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
f_h.write("\tvirtual unsigned int getId() override { return protocolId; };\n")
f_h.write("\tstatic const unsigned int protocolId = " + msg_id + ";\n")
f_h.write("\n")
if(with_serialize != 'n' and with_serialize != 'N'):
    f_h.write("\t// Turns raw data into the usable data (message's attributes)\n")
    f_h.write("\tvirtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;\n")
    f_h.write("\t// Turns the message's attributes into raw data\n")
    f_h.write("\tvirtual bool serialize(shared_ptr<MessageDataBuffer> output) override;\n")
    f_h.write("\n")
else:
    f_h.write("\t// Turns raw data into the usable data (message's attributes)\n")
    f_h.write("\tvirtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { return true; };\n")
    f_h.write("\t// Turns the message's attributes into raw data\n")
    f_h.write("\tvirtual bool serialize(shared_ptr<MessageDataBuffer> output) override { return true; };\n")
    f_h.write("\n")
for att in attributes:
    f_h.write("\t" + att + ";\n")
f_h.write("\n")
f_h.write("};\n")
f_h.write("\n")
f_h.write("#endif")

f_h.close()

if(with_serialize != 'n' and with_serialize != 'N'):
    f_cpp = open(file_path + "/" + className + ".cpp", 'w')

    f_cpp.write("#include \"" + className +".h\"\n")
    f_cpp.write("\n")
    f_cpp.write("bool " + className + "::serialize(shared_ptr<MessageDataBuffer> output) {\n")
    if(parentName != "PrefixedMessage"):
        f_cpp.write("\tif(!" + parentName + "::serialize(output))\n")
        f_cpp.write("\t\treturn false;\n")
    f_cpp.write("\n")
    f_cpp.write("\treturn true;\n")
    f_cpp.write("}\n")
    f_cpp.write("\n")
    f_cpp.write("bool " + className + "::deserialize(shared_ptr<MessageDataBuffer> input) {\n")
    if(parentName != "PrefixedMessage"):
        f_cpp.write("\tif(!" + parentName + "::deserialize(input))\n")
        f_cpp.write("\t\treturn false;\n")
    f_cpp.write("\n")
    f_cpp.write("\treturn true;\n")
    f_cpp.write("}\n")

    f_cpp.close()

f_config = open("MessageGenerator.config", 'w')
f_config.write(file_path)
f_config.close()