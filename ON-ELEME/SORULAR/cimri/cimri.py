q=int(input())
for test in range(q):
    N=int(input())
    minv=float('inf')
    mink=N+1
    for i in range(N):
        a=sum(list(map(int,input().strip().split())))
        if(a<minv):
            minv=a
            mink=i+1
    print(mink)
    
