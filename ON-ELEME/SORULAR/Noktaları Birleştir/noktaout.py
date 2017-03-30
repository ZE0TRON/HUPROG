from collections import defaultdict
from sys import argv
inpdosya=open("Inputs/input"+argv[1]+".txt","r")
outdosya=open("Outputs/output"+argv[1]+".txt","w")
q=int(inpdosya.readline())


def zeroer():
    return 0
for test in range(q):
    N,E=map(int,inpdosya.readline().split())
    graph=defaultdict(zeroer)
    for edge in range(E):
        a,b=map(int,inpdosya.readline().split())
        graph[a]+=1
        graph[b]+=1
    okey=1
    for elem in graph.values():
        if(elem%2==1):
            okey=-1
    print(okey,file=outdosya)
