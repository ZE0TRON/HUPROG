from random import randint

print("Dosya Adı: ")
output = input()
out = open(output + ".txt","w")

print("Mekanizma sayısı: ");
n = int(input());

print("İşlem sayısı: ");
m = int(input());

#tree generator
tree = {1:[2,3]}
node = 2
nerdeyim = 4
while nerdeyim != n + 1:
    zar = randint(0,100)
    if zar >= 90:
        tree[node] = []
    elif zar >= 75 or nerdeyim == n:
        tree[node] = [nerdeyim]
        nerdeyim += 1
    elif zar >= 50 or nerdeyim >= n - 9:
        tree[node] = [nerdeyim, nerdeyim + 1]
        nerdeyim += 2
    elif zar >= 30 or nerdeyim >= n - 49:
        rasgele = randint(3,10)
        tree[node] = [nerdeyim]
        nerdeyim += 1
        for _ in range(rasgele - 1):
            tree[node].append(nerdeyim)
            nerdeyim += 1
    elif zar >= 20 or nerdeyim >= n - 99:
        rasgele = randint(11,50)
        tree[node] = [nerdeyim]
        nerdeyim += 1
        for _ in range(rasgele - 1):
            tree[node].append(nerdeyim)
            nerdeyim += 1
    elif zar >= 10 or nerdeyim >= n - 499:
        rasgele = randint(51,100)
        tree[node] = [nerdeyim]
        nerdeyim += 1
        for _ in range(rasgele - 1):
            tree[node].append(nerdeyim)
            nerdeyim += 1
    elif zar >= 5 or nerdeyim >= n - 999:
        rasgele = randint(101,500)
        tree[node] = [nerdeyim]
        nerdeyim += 1
        for _ in range(rasgele - 1):
            tree[node].append(nerdeyim)
            nerdeyim += 1
    else:
        rasgele = randint(501,1000)
        tree[node] = [nerdeyim]
        nerdeyim += 1
        for _ in range(rasgele - 1):
            tree[node].append(nerdeyim)
            nerdeyim += 1
    node += 1
print(n,file=out)
for elem in tree:
    for elem2 in tree[elem]:
        print(elem, elem2,file=out)
print(m,file=out)

t = randint(1,1000)
sayi1 = randint(1,n)
while True:
    sayi2 = randint(1,n)
    if sayi2 != sayi1:
        break
print(1,sayi1,sayi2,t,file=out)
for _ in range(m - 1):
    acaba = randint(1,5)
    if acaba == 1:
        t = randint(1,1000)
        sayi1 = randint(1,n)
        while True:
            sayi2 = randint(1,n)
            if sayi2 != sayi1:
                break
        print(1,sayi1,sayi2,t,file=out)
    else:
        print(2,randint(1,elem),file=out)

