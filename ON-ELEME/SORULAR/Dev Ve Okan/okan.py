def factorial(n):
    if(n==1):
        return 1
    else:
        return(factorial(n-1)*n)
q=int(input())
for test in range(q):
    N,M=map(int,input().split())
    for i in range(M):
        input()
print(factorial(n+m-2)/(factorial(n-1)*factorial(m-1)))
