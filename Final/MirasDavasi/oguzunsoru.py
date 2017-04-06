from math import sqrt
q=int(input())
for test in range(q):
    M=int(input())
    d=0
    for i in range(M):
        d+=sqrt(int(input()))
    c=int(input())
    print(int(sqrt(c**2-d**2)))
