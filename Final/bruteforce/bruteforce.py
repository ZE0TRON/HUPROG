"""from collections import defaultdict
def negativer():
    return -1
memo=defaultdict(negativer)
def T(n):
    if memo[n]==-1:
        memo[n]=T(n-1)+Necklace(n)
    return memo[n]
def Necklace(n):
    for k in range(3,500):
        while k>0:
        """
"""from math import sqrt
k4=1
counter=0
for k1 in range(1000):
    for k2 in range(1000):
        for k3 in range(1000):
            if(k4== (k1+k2+k3+2*sqrt(k1*k2+k2*k3+k3*k1))):
                counter+=1
print(counter)
"""
for k4 in range(100):
    deg=[1 for _ in range(k4)]
