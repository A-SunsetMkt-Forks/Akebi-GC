import requests
import json
import re

# Reading api
with open("map_api.txt", "r") as map_api_file:
    api_list = []
    for line in map_api_file.readlines():
        name, address = line.split()
        api_list.append((name, address))

# Getting points data
points_messages = []
for (name, address) in api_list:
    r = requests.get(address)
    if r.status_code != 200:
        print(f"Failed load points data for {name}")
        continue

    points_messages.append((name, json.loads(r.content.decode())))

# Refactor data to our format
refactored_data = {}
for (name, message) in points_messages:
    label_list = message["data"]["label_list"]
    point_list = message["data"]["point_list"]

    label_map = {}
    for label in label_list:
        label_map[label["id"]] = label

    data = {}
    for point in point_list:
        label_id = point["label_id"]
        if label_id not in data:
            label = label_map[label_id]
            clear_name = re.sub(r"[^\w\d_]", "", label["name"])
            data[label_id] = {
                "name": label["name"],
                "clear_name": clear_name,
                "points": [],
                "icon": label["icon"]
            }

        points = data[label_id]["points"]
        points.append({
            "id": point["id"],
            "x_pos": point["x_pos"],
            "y_pos": point["y_pos"]
        })

    refactored_data[name] = {
        "labels": data
    }

# Getting categories data
categories_messages = []
for (name, address) in api_list:
    r = requests.get(address.replace("list", "tree").replace("point", "label"))
    if r.status_code != 200:
        print(f"Failed load categories data for {name}")
        continue

    categories_messages.append((name, json.loads(r.content.decode())))

# Refactor data to our format
for (name, message) in categories_messages:
    categories_list = message["data"]["tree"]

    data = []
    for category in categories_list:
        data.append(
            {
                "id": category["id"],
                "name": category["name"],
                "children": [child["id"] for child in category["children"]]
            }
        )

    refactored_data[name]["categories"] = data

# Writing refactored data to json files
for (name, data) in refactored_data.items():
    with open(f"../{name}.json", "w") as out_json_file:
        json.dump(data, out_json_file, indent=4)
