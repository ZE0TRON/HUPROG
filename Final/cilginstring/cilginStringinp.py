from random import randint
from string import ascii_lowercase
from random import choice

print("Dosya Adı: ")
output = input()
out = open(output + ".txt","w")

print("soru sayısı: ")
q = int(input())
print("string uzunluğu min max: ")
minS,maxS = map(int,input().rstrip().split(" "))
print("min, max karıştırma miktarı")
minK,maxK = map(int,input().rstrip().split(" "))

print(q,file=out)
for _ in range(q):
    uzunluk = randint(minS,maxS)
    kelime = ""
    for _ in range(uzunluk):
        kelime += (choice(ascii_lowercase))
    print(uzunluk,file=out)
    karistirma = randint(minK,maxK)
    temp=kelime
    for _ in range(karistirma):
        start = randint(0,uzunluk - 2)
        end = randint(start,uzunluk - 1)
        kelime = kelime[:start] + kelime[end:] + kelime[start:end]
    print(temp,kelime,file=out)
