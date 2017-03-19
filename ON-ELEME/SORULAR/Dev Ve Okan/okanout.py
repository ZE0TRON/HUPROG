from sys import argv
def factorial(n):
    if(n==1):
        return 1
    else:
        return(factorial(n-1)*n)
inpdosya=open(argv[1]+"inp.txt","r")
outdosya=open(argv[1]+"out.txt","w")
q=int(inpdosya.readline())
for test in range(q):
    N,M=map(int,inpdosya.readline().split())
    for i in range(M):
        inpdosya.readline()
    print(factorial(n+m-2)/(factorial(n-1)*factorial(m-1)),file=outdosya)
