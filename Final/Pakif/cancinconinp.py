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
out = open(output + ".txt","w")

print("soru sayısını gir pilge: ")
soruSayısı = int(input())

print("node sayısı:")
nodeSayısı = int(input())

print("edge sayisi:")
edgeSayisi = int(input())

print("dogru test case sayısı yüzdesi: ")
yuzde = int(input())
print("ağırlık aralığı: (min max)")
minA,maxA = map(int,input().rstrip().split(" "))
yanlis = 0
print(soruSayısı,file=out)
while soruSayısı > 0:
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
        while node != (nodeSayısı + 1)//1.4:
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
        while node != (nodeSayısı + 1) // 2:
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
    edgeler = len(edgeList)

    #print("graph oluşturuldu. Connected özelliği test ediliyor...")
    UzaklikDict = {1: 0}
    BFS(graph, 1)
    if len(UzaklikDict) < nodeSayısı:
        #print("Başaramadın... Başa Dönülüyor")
        continue
    else:
        #print("geliştirme başarılı...")
        pass

    tek = 0
    for bilge in graph.values():
        if len(bilge) % 2 != 0:
           tek += 1
    oran = tek / nodeSayısı
    if not(oran < 0.21 and oran > 0.05):
        continue
    else:
        print("çok güzel oluşturdum aferin bana. oran:",oran)
        print("kalan test case:",soruSayısı)
    print(nodeSayısı, edgeler,file=out)
    for num1,num2 in edgeList:
        print(num1,num2,randint(minA,maxA),file=out)
    soruSayısı -= 1
