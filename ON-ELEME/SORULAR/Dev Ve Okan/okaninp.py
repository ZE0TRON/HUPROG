import random
import string

print("Dosya Adı: ")
output = input()
out = open(output + ".txt","w")

print("soru sayısı: ")
soruSayısı = int(input())

print("Matrix boyutu minimum x:")
minX = int(input())

print("Matrix boyutu maximum x:")
maxX = int(input())

print("Matrix Boyutu minimum Y:")
minY = int(input())

print("Matrix Boyutu maksimum Y:")
maxY = int(input())

print(soruSayısı,file=out)

for _ in range(soruSayısı):
    matrixBoyutuX = random.randint(minX, maxX)
    matrixBoyutuY = random.randint(minY, maxY)
    print(matrixBoyutuX,matrixBoyutuY,file=out)
    kelime = ""
    for _ in range(matrixBoyutuX + matrixBoyutuY - 1):
        kelime += random.choice(string.ascii_letters)
    print(kelime,file=out)
    xCoor = 0
    yCoor = 0
    while True:
        if yCoor == matrixBoyutuY:
            break
        elif xCoor == matrixBoyutuX:
            yCoor += 1
            xCoor = 0
            print("", file=out)
            continue
        else:
            print(kelime[xCoor + yCoor], end=" ", file=out)
            xCoor += 1