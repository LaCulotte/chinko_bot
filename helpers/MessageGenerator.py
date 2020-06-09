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

file_path = filedialog.asksaveasfilename(master=root)

f = open(file_path, 'w')

f.write("#ifndef " + "_MESSAGE".join(className.upper().split("MESSAGE")) + "_H\n")
f.write("#define " + "_MESSAGE".join(className.upper().split("MESSAGE")) + "_H\n")
f.write("\n")
f.write("#include \"" + parentName + ".h\"\n")
f.write("\n")
f.write("class " + className + " : public " + parentName + " {\n")
f.write("public: \n")
f.write("\t// Constructor\n")
f.write("\t" + className + "() {};\n")
f.write("\t// Copy constructor\n")
f.write("\t" + className + "(const " + className + "& other) = default;\n")
f.write("\n")
f.write("\t// Copy operator\n")
f.write("\t" + className + "& operator=(const " + className + "& other) = default;\n")
f.write("\t// Destructor\n")
f.write("\t~" + className + "() = default;\n")
f.write("\n")
f.write("\tvirtual unsigned int getId() override { return protocolId; };\n")
f.write("\tstatic const unsigned int protocolId = " + msg_id + ";\n")
f.write("\n")
if(with_serialize != 'n' and with_serialize != 'N'):
    f.write("\t// Turns raw data into the usable data (message's attributes)\n")
    f.write("\tvirtual bool deserialize(shared_ptr<MessageDataBuffer> input) override;\n")
    f.write("\t// Turns the message's attributes into raw data\n")
    f.write("\tvirtual bool serialize(shared_ptr<MessageDataBuffer> output) override;\n")
    f.write("\n")
else:
    f.write("\t// Turns raw data into the usable data (message's attributes)\n")
    f.write("\tvirtual bool deserialize(shared_ptr<MessageDataBuffer> input) override { return true; };\n")
    f.write("\t// Turns the message's attributes into raw data\n")
    f.write("\tvirtual bool serialize(shared_ptr<MessageDataBuffer> output) override { return true; };\n")
    f.write("\n")
for att in attributes:
    f.write("\t" + att + ";\n")
f.write("\n")
f.write("};\n")
f.write("\n")
f.write("#endif")

f.close()