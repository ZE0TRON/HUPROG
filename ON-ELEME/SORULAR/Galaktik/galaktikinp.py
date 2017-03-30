from collections import  defaultdict
from random import  randint

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
print("Uzay istasyonu sayısı(N): ")
n = int(input())
print("warp rotası sayısı: ")
w = int(input())
print("Harita sınırı: (x y z)")
x,y,z = list(map(int,input().rstrip().split(" ")))

print(n, w, file=out)

print("graph oluşturuluyor...")
while True:
    graph = defaultdict(list)
    edgeList = []
    lol = w - n + 1
    i = 1
    while i < n:
        n2 = randint(1,n)
        if i == n2:
            continue
        if n2 not in graph[i]:
            graph[i].append(n2)
            graph[n2].append(i)
            edgeList.append([i,n2])
            i += 1

    while lol != 0:
        n1 = randint(1,n)
        n2 = randint(1,n)
        if n1 == n2:
            continue
        if n2 not in graph[n1]:
            graph[n1].append(n2)
            graph[n2].append(n1)
            edgeList.append([n1,n2])
            lol -= 1
    print("graph oluşturuldu. Connected özelliği test ediliyor...")
    UzaklikDict = {1:0}
    BFS(graph, 1)
    if len(UzaklikDict) < n:
        print("Başaramadın... Başa Dönülüyor")
    else:
        print("geliştirme başarılı...")
        break
koordinat = set()
while len(koordinat) != n:
    X = randint(0, x)
    Y = randint(0, y)
    Z = randint(0, z)
    koordinat.add((X, Y, Z))
for elem in edgeList:
    print(elem[0], elem[1], file=out)
count = 1
for elem in koordinat:
    print(count, elem[0], elem[1], elem[2], file=out)
    count += 1

while True:
    CapitalShip = randint(1,n)
    Nuke1 = randint(1,n)
    Nuke2 = randint(1,n)
    EnemyPlanet = randint(1,n)
    if CapitalShip == EnemyPlanet or Nuke1 == Nuke2 or Nuke1 == EnemyPlanet or Nuke2 == EnemyPlanet or Nuke1 == CapitalShip or Nuke2 == CapitalShip:
        continue
    break
print(Nuke1, Nuke2, EnemyPlanet, CapitalShip, sep="\n", file=out)
