from sys import argv
def factorial(n):
    if(n==1):
        return 1
    else:
        return(factorial(n-1)*n)
inpdosya=open("input/input"+argv[1]+".txt","r")
outdosya=open("output/output"+argv[1]+".txt","w")
q=int(inpdosya.readline())
for test in range(q):
    n,m=map(int,inpdosya.readline().split())
    for i in range(m+1):
        inpdosya.readline()
    print((factorial(n+m-2)//(factorial(n-1)*factorial(m-1))%((10**9)+7)),file=outdosya)
