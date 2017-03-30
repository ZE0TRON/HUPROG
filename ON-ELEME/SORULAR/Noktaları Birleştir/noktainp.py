from random import randint
from collections import defaultdict

def BFS(graph, start):
    global UzaklikDict
    q = []
    q.append(start)

    while len(q) > 0:
        current = q.pop(0)
        for cocuk in graph[current]:

            if cocuk not in UzaklikDict.keys():
                UzaklikDict[cocuk] = UzaklikDict[current] + 1
                q.append(cocuk)

    return 0



print("Dosya Adı: ")
output = input()
out = open("Inputs/input"+output + ".txt","w")

print("soru sayısı: ")
soruSayısı = int(input())

print("node sayısı:")
nodeSayısı = int(input())

print("edge sayisi:")
edgeSayisi = int(input())

print("dogru test case sayısı yüzdesi: ")
yuzde = int(input())
print(soruSayısı,file=out)
yanlis = 0
for _ in range(soruSayısı):
    while True:
        edgeList = []
        graph = defaultdict(list)
        lol = edgeSayisi
        while lol != 0:
            n1 = randint(1,nodeSayısı)
            n2 = randint(1,nodeSayısı)
            if n1 == n2:
                continue
            if n2 not in graph[n1]:
                graph[n1].append(n2)
                graph[n2].append(n1)
                edgeList.append([n1,n2])
                lol -= 1

        acaba = randint(1,100)
        if acaba <= yuzde:
            tek1 = 0
            node = 1
            while node != nodeSayısı + 1:
                if len(graph[node]) == 0:
                    while True:
                        ran = randint(1,nodeSayısı)
                        if ran != node:
                            graph[node].append(ran)
                            graph[ran].append(node)
                            edgeList.append([node,ran])
                            break
                node += 1
            node = 1
            while node != nodeSayısı + 1:
                if tek1 == 0:
                    if len(graph[node]) % 2 != 0:
                        tek1 = node
                else:
                    if len(graph[node]) == 0 or len(graph[node]) % 2 != 0:
                        if tek1 not in graph[node]:
                            graph[tek1].append(node)
                            graph[node].append(tek1)
                            edgeList.append([tek1, node])
                            tek1 = 0
                node += 1

            tek1 = 0
            node = 1
            while node != nodeSayısı + 1:
                if tek1 == 0:
                    if len(graph[node]) % 2 != 0:
                        tek1 = node
                else:
                    if len(graph[node]) == 0 or len(graph[node]) % 2 != 0:
                        if tek1 not in graph[node]:
                            graph[tek1].append(node)
                            graph[node].append(tek1)
                            edgeList.append([tek1, node])
                            tek1 = 0
                node += 1

        print("graph oluşturuldu. Connected özelliği test ediliyor...")
        UzaklikDict = {1: 0}
        BFS(graph, 1)
        if len(UzaklikDict) < nodeSayısı:
            print("Başaramadın... Başa Dönülüyor")
        else:
            print("geliştirme başarılı...")
            break

    edgeler = len(edgeList)

    print(nodeSayısı, edgeler,file=out)
    for num1,num2 in edgeList:
        print(num1,num2,file=out)

    for bilge in graph.values():
        if len(bilge) % 2 != 0:
            yanlis += 1
            break
print(soruSayısı , "/",soruSayısı - yanlis)
