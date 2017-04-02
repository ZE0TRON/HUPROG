from random import randint

print("Dosya Adı: ")
output = input()
out = open(output + ".txt","w")

print("soru sayısı: ")
q = int(input())
print("min,max hissedar sayısı: (min M  max M)")
minM,maxM = map(int,input().rstrip().split(" "))
print("min, max k sayısı: (minK maxK)")
minK,maxK = map(int,input().rstrip().split(" "))
print("min,max l sayısı(hissedardan fazla olsun): (minL maxL)")
minL,maxL = map(int,input().rstrip().split(" "))


print(q,file=out)
for _ in range(q):
    while True:
        hissedar = randint(minM,maxM)
        l = randint(minL,maxL)
        if l >= hissedar:
            break
    print(hissedar,file=out)
    k = randint(minK,maxK)
    c = k ** 2 + l ** 2
    düsükOrt = l // hissedar
    liste = []
    for _ in range(hissedar):
        sayi = randint(1,düsükOrt)
        liste.append(sayi)
        l -= sayi
    while l != 0:
        liste[randint(0,hissedar - 1)] += 1
        l -= 1
    kareliListe = []
    for lol in liste:
        kareliListe.append(lol ** 2)
    for elem in kareliListe:
        print(elem,file=out)
    print(c,file=out)