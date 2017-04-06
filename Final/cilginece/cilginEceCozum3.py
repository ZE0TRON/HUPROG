def xor(a,b):
    return a^b
q=int(input())
for _ in range(q):
    N = int(input())
    liste = map(xor,list(map(int,input().rstrip().split())))
    anlamsızSayı = liste[0]
    for elem in liste[1:]:
        anlamsızSayı = anlamsızSayı ^ elem
    print(anlamsızSayı ^ 0)
