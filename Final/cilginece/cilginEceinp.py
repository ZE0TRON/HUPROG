from random import randint

print("Dosya Adı: ")
output = input()
out = open("input/input"+output + ".txt","w")

print("soru sayısı: ")
q = int(input())
print("min,max eklenen madde-antimadde sayısı: (min max)")
minM,maxM = map(int,input().rstrip().split(" "))

print(q,file=out)
for _ in range(q):
    maddeSayısı = randint(minM,maxM)
    if maddeSayısı % 2 == 0:
        maddeSayısı += 1
    print(maddeSayısı,file=out)
    maddeList = [randint(1,118)]
    for _ in range(maddeSayısı // 2):
        madde = randint(1,118)
        maddeList.append(madde);maddeList.append(madde)
    while len(maddeList) != 0:
        print(maddeList.pop(randint(0,len(maddeList) - 1)), end=" ", file=out)
    print("",file=out)