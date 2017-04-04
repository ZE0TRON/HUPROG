from collections import defaultdict
"""def negativer():
    return -1
DP=defaultdict(negativer)
"""
def BFS(start, end):
    q=[(start,0)]
    travelled=[]
    while len(q)!=0:
        current,counter = q.pop(0)
        if current==end:
            return counter
        for i in range(0,N):
            for j in range(i,N):
                elem=current[:i]+current[j:]+current[i:j]
                if elem not in travelled:
                    if(counter<len(current)):
                        q.append((elem,counter+1))
                        travelled.append(elem)
    return float('inf')
"""
def DParak(a,counter):
    if(a==aranan):
        return counter
    if(counter>len(a)*len(a)):
        return float('inf')
    if(DP[a]==-1):
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
    N=int(input())
    s1 ,aranan = input().split()
    print(s1,aranan)
    print(BFS(s1,aranan))
