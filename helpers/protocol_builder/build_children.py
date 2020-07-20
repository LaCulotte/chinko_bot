#! /usr/bin/python

import json
import sys
import os

if(len(sys.argv) != 4):
    print("usage : ./build_chidren <protocolname> <filepath>.json <output-directory>")
    exit()

children_protocols = []

json_file = open(sys.argv[2], 'r')
json_dict = json.load(json_file)
json_file.close()

children_protocols += list(filter(lambda m : m["super"] == sys.argv[1], json_dict["messages"]))
children_protocols += list(filter(lambda m : m["super"] == sys.argv[1], json_dict["types"]))

for child in children_protocols:
    os.system("./protocol_builder.py " + child["name"] + " " + sys.argv[2] + " " + sys.argv[3])