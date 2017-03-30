from collections import defaultdict
from time import time
from sys import argv
atime=time()
inpdosya=open("input/input"+argv[1]+".txt","r")
outdosya=open("output/output"+argv[1]+".txt","w")
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
print(time()-atime)
