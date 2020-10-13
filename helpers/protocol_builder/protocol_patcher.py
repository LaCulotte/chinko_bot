#! /usr/bin/python

from os import walk
import json
import sys

if(len(sys.argv) != 3):
    print("Use : ./protocol_parser.py <root-dir> <output-dir>")
    exit()

json_file = open("protocols.json", "r")
json_dict = json.load(json_file)
json_file.close()

files = []
files_names = []
for (dirpath, dirnames, filenames) in walk(sys.argv[1]):
    for name in filenames:
        if(name[-1] == 'h'):
            files.append(dirpath + "/" + name)
            files_names.append(name.split(".")[0])
            # print(name)

for messages_protocol in json_dict["messages"]:
    if(messages_protocol["name"] in files_names):
        index = files_names.index(messages_protocol["name"])

        print(files[index])

        in_file = open(files[index], 'r')
        in_lines = in_file.readlines()
        in_file.close()

        for i, line in enumerate(in_lines):
            line_parts = line.split(" ")
            if(len(line_parts) > 3 and line_parts[-3] == "protocolId"):
                line_parts[-1] = str(messages_protocol["protocolID"]) + ";"
                in_lines[i] = " ".join(line_parts) + "\n"
                break

        out_file = open(files[index], "w")
        out_file.writelines(in_lines)
        out_file.close()
