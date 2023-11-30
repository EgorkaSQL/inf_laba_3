import yaml
import time
from yaml import SafeLoader
import xmltodict
start = time.perf_counter()
yaml_file = open("schedule.yaml", "r")
python_dict = yaml.load(yaml_file, Loader=SafeLoader)  #Делает словарь
file = open("schedule1.xml", "w")
xml_string = xmltodict.unparse(python_dict, output=file)   #Преобразует словарь в строку и добавляет в файл
finish = time.perf_counter()
time = finish - start