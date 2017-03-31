lol = input()
inp = open("input/input" + lol + ".txt","r")
out = open("output/output" + lol + ".txt", "w")
q=int(inp.readline())
for _ in range(q):
    N = int(inp.readline())
    liste = list(map(int,inp.readline().rstrip().split()))
    anlamsızSayı = liste[0]
    for elem in liste[1:]:
        anlamsızSayı = anlamsızSayı ^ elem
    print(anlamsızSayı ^ 0,file=out)
