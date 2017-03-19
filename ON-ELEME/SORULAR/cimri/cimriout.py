from sys import argv

inpdosya=open(argv[1]+"inp.txt","r")
outdosya=open(argv[1]+"out.txt","w")
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
