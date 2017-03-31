def factorial(n):
    for i in range(1,n+1):
        if i not in fakto.keys():
            fakto[i]=fakto[i-1]*i
    return fakto[n]
q=int(input())
fakto={}
fakto[0]=1
fakto[1]=1
for test in range(q):
    n,m=map(int,input().split())
    for i in range(n+1):
        input()
    print(factorial(n+m-2)//(factorial(n-1)*factorial(m-1))%((10**9)+7))
