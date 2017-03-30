from sys import argv

inpdosya=open("input/input"+argv[1]+".txt","r")
outdosya=open("output/output"+argv[1]+".txt","w")
q=int(inpdosya.readline())
for test in range(q):
    N=int(inpdosya.readline())
    minv=float('inf')
    mink=N+1
    for i in range(N):
        a=sum(list(map(int,inpdosya.readline().strip().split())))
        if(a<minv):
            minv=a
            mink=i+1
    print(mink,file=outdosya)
