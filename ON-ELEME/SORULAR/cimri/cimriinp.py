from random import randint

print("Dosya Adı: ")
output = input()
out = open("Inputs/input"+output+".txt","w")

print("soru sayısı: ")
soruSayısı = int(input())
print("en düşük amca sayısı: ")
amcaL = int(input())
print("en yuksek amca sayısı: ")
amcaH = int(input())
print("en düşük çay sayısı: ")
çayL = int(input())
print("en yüksek çay sayısı: ")
çayH = int(input())
AmcaSayısı = 0

print(soruSayısı, file=out)

for _ in range(soruSayısı):
    AmcaSayısı = randint(amcaL,amcaH + 1)
    print(AmcaSayısı,file=out)

    for i in range(AmcaSayısı):

        for k in range(AmcaSayısı):
            if(i==k):
                print(0, end=" ", file=out)
                continue
            sayi = randint(çayL,çayH + 1)
            print(sayi, end=" ", file=out)
        print("", file=out)
