from random import randint

print("Dosya Adı: ")
output = input()
out = open(output + ".txt","w")

print("soru sayısı: ")
q = int(input())
print("bitki sayısı: ")
l= int(input())
print("bitkinin ihtiyaç duyduğu alanın exsen sınırları: (min max)")
minB,maxB = map(int,input().rstrip().split(" "))
print("bitkinin kar sınırları: (minK maxK)")
minK,maxK = map(int,input().rstrip().split(" "))
print("tarla eksen boyutu sınırları: (min max)")
minE,maxE = map(int,input().rstrip().split(" "))

print(q,l,sep="\n",file=out)
for k in range(l):
    print(k,randint(minB,maxB),randint(minB,maxB),randint(minK,maxK),file=out)
for _ in range(q):
    print(randint(minE,maxE),randint(minE,maxE),file=out)