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
"""
def square(a):
    return a**2

Q = int(input())
for test in range(Q):
    N=int(input())
    minv=int(input())
    maxv=int(input())
    radsums=set()
    rads=[minv for i in range(N+2)]
    counter1=0
    counter2=0
    curvatures=[1/rad for rad in rads]
    print(curvatures)
    while rads[N+1]!=maxv:
        counter1=counter1%(N+2)
        rads[counter1]+=1
        curvatures[counter1]=1/rads[counter1]
        ssum=sum(map(square,curvatures))
        a=sum(curvatures)**2
        b=N*ssum
        if(format(a,'.7f')==format(b,'.7f') ):
            print(format(a,'.4f'),format(b,'.4f'))
            radsums.add(sum(rads))
        counter1+=1
    print(len(radsums))
"""
def square(a):
    return a**2
from random import randint
N=int(input())

minv=int(input())
maxv=int(input())
posslist=[]
for j in range(3):
    counter=0
    for i in range(50000):
        rads=[1/randint(1,2<<32)+randint(minv,maxv-1) for i in range(N+2)]
        curvatures=[1/rad for rad in rads]
        ssum=sum(map(square,curvatures))
        a=sum(curvatures)**2
        b=N*ssum
        if(format(a,'.9f')[:-1] ==format(b,'.9f')[:-1] and format(a,'.9f')[:-1].count('0')<8):
            counter+=1
    print(counter/50000)
    posslist.append(format(counter/50000,'.4f')[:-1])
maxcount=0
maxcounted=0
for elem in posslist:
    a=posslist.count(elem)
    print(a)
    print(elem)
    if a>maxcount:
        maxcount=a
        maxcounted=elem
print(maxcounted)
"""
from math import sqrt

r1=2
r2=0.05
r3=1
N=2
r4=r1*r2*r3/(r1*r2+r2*r3+r3*r1+2*sqrt(r1*r2*r3*(r1+r2+r3)))
rads=[r1,r2,r3,r4]
curvatures=[1/rad for rad in rads]
ssum=sum(map(square,curvatures))
a=sum(curvatures)**2
b=N*ssum
print(format(a,'.4f'),format(b,'.4f'))
if(format(a,'.4f')==format(b,'.4f')):
    print("it works")
"""
