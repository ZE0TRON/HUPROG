from collections import defaultdict
def zeror():
    return 0
q=int(input())
for _ in range(q):
    N = int(input())
    liste = list(map(int,input().rstrip().split()))
    sozluk = defaultdict(zeror)
    for num in liste:
        sozluk[num] += 1
    for elem in sozluk:
        if sozluk[elem] % 2 != 0:
            print(elem)
            break