import yaml
import json
import pandas
import time

start = time.perf_counter()
with open('schedule.yaml', 'r', encoding='utf-8-sig') as yaml_file:
    data = yaml.safe_load(yaml_file)

json_data = json.dumps(data, indent=2, ensure_ascii=False)

dataframe = pandas.json_normalize(data)
dataframe.to_csv('out.csv', encoding="utf-8-sig")

finish = time.perf_counter()
time = finish - start