import time
start = time.perf_counter()
file_yml = open('schedule.yaml', 'r', encoding='utf-8')
file_xml = open('schedule.xml', 'w', encoding='utf-8')
info = file_yml.readlines()
file_xml.write("<?xml version = \"1.0\" encoding = \"UTF-8\"?>\n")
info.append("/" + info[0])

for i in range(0, len(info)):
    cnt = 0
    for j in range(0, len(info[i])):
        if info[i][j] == " ":
            cnt += 1
        else:
            break
    if cnt >= 0:
        a = list(info[i])
        a[cnt - 1] = "<"
        info[i] = "".join(a)
        info[i] = info[i][:-1]
        if info[i].count(" ") == 0:
            info[i] = "<" + info[i]
        if info[i][-1] != ":" and info[i].count(":") == 1:
            info[i] = info[i].split(":")
            info[i][0] += ">"
            info[i] = info[i][0] + info[i][1] + " </" + info[i][0].replace(" ", "").lstrip("<")
        if info[i][-1] == ":":
            info[i] = info[i].replace(":", "!")
        if info[i].count(":") > 1:
            info[i] = info[i].replace(":", ">", 1)
            info[i] = info[i].split(">")
            info[i][0] += ">"
            info[i] = info[i][0] + info[i][1] + " </" + info[i][0].replace(" ", "").lstrip("<")
        info[i] = info[i] + '\n'
c = 0
w = []
q = []
for i in range(1, len(info)-1):
    if "!" in info[i] and c == 0:
        q.append(info[i])
        c = 1
    elif c == 1 and not("!" in info[i]):
        q.append(info[i])
        if i == len(info) - 2:
            q.append(" " + "<" + "/" + q[0][2:])
            w.append(' '.join(map(str, q)))
    elif c == 1 and "!" in info[i]:
        q.append(" " + "<" + "/" + q[0][2:])
        w.append(' '.join(map(str, q)))
        q = []
        q.append(info[i])
pravda = []
pravda.append(info[0])
pravda.append(' '.join(map(str, w)))
pravda.append(info[-1])

for i in range(0, len(pravda)):
    pravda[i] = pravda[i].replace("!",">")
    file_xml.write(pravda[i])
finish = time.perf_counter()
time = finish - start