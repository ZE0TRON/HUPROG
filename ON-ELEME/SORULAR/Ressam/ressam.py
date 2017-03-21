t=int(input())
for test in range(t):
    replika=""
    gercek=""
    costs={}
    N,M=map(int,input().split())
    for i in range(N):
        replika+=input()
    I,K=map(int,input().split())
    for i in range(I):
        gercek+=input()
    for i in range(12):
        a,b,c=map(int,input().split())
        costs[(a,b)]=c
    rmaliyet=int(input())
    p1="wwwwww"+gercek
    p2="www"+gercek+"www"
    p3=gercek+"wwwwww"
    
