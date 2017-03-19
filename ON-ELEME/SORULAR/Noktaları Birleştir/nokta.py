from collections import defaultdict
q=int(input())
def zeroer():
    return 0
for test in range(q):
    N,E=map(int,input().split())
    graph=defaultdict(zeroer)
    for edge in range(E):
        a,b=map(int,input().split())
        graph[a]+=1
        graph[b]+=1
    okey=1
    for elem in graph.values():
        if(elem%2==1):
            okey=-1
    print(okey)
