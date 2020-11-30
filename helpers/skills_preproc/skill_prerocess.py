import json
import sys

if(len(sys.argv) != 3):
    print("usage : python skill_process.py <intput> <output>")
    exit()

skills_json = open(sys.argv[1], 'r')
skills = json.load(skills_json)
skills_json.close()

skills_out = []

for skill in skills:
    if(skill["gatheredRessourceItem"] == -1):
        continue
    
    skill_out = {}
    skill_out["id"] = skill["id"]
    skill_out["interactiveId"] = skill["interactiveId"]
    skill_out["range"] = skill["range"]

    skills_out.append(skill_out)

skills_json_out = open(sys.argv[2], 'w')
json.dump(skills_out, skills_json_out, indent=4, ensure_ascii=False)
skills_json_out.close()