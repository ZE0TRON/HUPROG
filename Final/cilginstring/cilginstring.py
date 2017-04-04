from collections import defaultdict
def negativer():
    return -1
DP=defaultdict(negativer)
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
Q=int(input())
for test in range(Q):
    N=int(input())
    s1 ,aranan = input().split()
    print(DParak(s1,0))
