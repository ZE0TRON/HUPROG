from collections import defaultdict
from time import time
def negativer():
    return -1
DP=defaultdict(negativer)

def BFS(start, end,blok):
    q=[(start,0,end)]
    travelled=[]
    while len(q)!=0:
        current,counter,end = q.pop(0)
        #counter2=0
        #for i in range(len(current)):
        #    if current[i]==end[i] :
        #        counter2+=1
        #    else:
        #        break
        if current==end:
            return counter
        #current=current[counter2:]
        #end=end[counter2:]
        for i in range(0,N-2):
            j=i+blok
            elem=current[:i]+current[j:]+current[i:j]
            if elem not in travelled:
                if(counter<len(current)):
                    q.append((elem,counter+1,end))
                    travelled.append(elem)
    return float('inf')
"""
def DParak(a,counter):
    counter2=0
    for i in range(len(a)):
        if a[i]==aranan[i] :
            counter2+=1
        else:
            break

    if(counter2==len(a)):
        return counter

    if(DP[a]==-1):
        a=a[counter2:]
        minv=float('inf')
        N=len(a)
        for i in range(0,N):
            for j in range(i,N):
                ns=a[:i]+a[j:]+a[i:j]
                z=DParak(ns,counter+1)
                if(z<minv):
                    minv=z
        DP[a]=z
        return z
    else:
        return DP[a]
"""
Q=int(input())
for test in range(Q):
    blok=int(input())
    N=int(input())
    s1 ,aranan = input().split()
    print(s1,aranan)
    print(BFS(s1,aranan,blok))
