from random import randint
from collections import defaultdict

print("Dosya Adı: ")
output = input()

print("matrix boyutları: (x y)")
matrixX,matrixY = map(int,input().rstrip().split(" "))
print("portal sayısı: ")
portalNum = int(input())
print("portalların açık kalma süresi aralığı: (min maks)")
minS,maxS = map(int,input().rstrip().split(" "))
print("adım süresi :")
adim = int(input())
#erdem kiraz'ın numarası: 5542638860#
while True:
    out = open(output + ".txt", "w")
    print(matrixX,matrixY,file=out)
    matrix = []
    for x in range(matrixX):
        matrix.append([])
        for y in range(matrixY):
            zar = randint(1,10)
            if zar <= 4:
                matrix[x].append("X")
            else:
                matrix[x].append("0")
    for elem in matrix:
        for oda in elem:
            print(oda,end=" ",file=out)
        print("",file=out)
    print(adim,file=out)
    print(portalNum,file=out)
    portalset = set()
    while len(portalset) != portalNum:
        while True:
            basX,basY,sonX,sonY = randint(0,matrixX - 1),randint(0,matrixY - 1),randint(0,matrixX - 1),randint(0,matrixY - 1)
            if matrix[basX][basY] == "X" or matrix[sonX][sonY] == "X" or (basX == sonX and basY == sonY):
                continue
            portalset.add(tuple((basX,basY,sonX,sonY)))
            break
    portalList = []
    for elem in portalset:
        print(elem[0],elem[1],elem[2],elem[3],file=out)
        baslangic = randint(0,(matrixX + matrixY) * adim * 2)
        bitis =  baslangic + randint(minS,maxS)
        print(baslangic,bitis,file=out)
        portalList.append([elem[0],elem[1],elem[2],elem[3],baslangic,bitis])
    n = 100
    while n > 0:
        startX,startY,finishX,finishY = randint(0,(matrixX - 1) // 10 + 1),randint(0,(matrixY - 1) // 10 + 1),randint(matrixX - ((matrixX - 1) // 10 + 1),matrixX - 1),randint(matrixY - ((matrixY - 1) // 10 + 1),matrixY - 1)
        if (startX == finishX and startY == finishY) or matrix[startX][startY] == "X" or matrix[finishX][finishY] == "X":
            n -= 1
            continue
        break
    print(startX," ",startY,"\n",finishX," ",finishY,sep="",file=out)
    if n == 0:
        print("bozuk bu")
        continue

    def negativer():
        return -1
    class PriorityQueueBase:
        class _Item:
            __slots__ = '_key','_value'

            def __init__(self,k,v):
                self._key=k
                self._value=v

            def __lt__(self,other):
                return self._key < other._key

        def is_empty(self):
            return len(self) == 0

    class HeapPriorityQueue(PriorityQueueBase):

        def _parent(self,j):
            return (j-1)//2

        def _left(self,j):
            return 2*j + 1

        def _right(self,j):
            return 2*j + 2

        def _has_left(self,j):
            return self._left(j) < len(self._data)

        def _has_right(self,j):
            return self._right(j) < len(self._data)

        def _swap(self,i,j):
            self._data[i] , self._data[j] = self._data[j] , self._data[i]

        def _upheap(self,j):
            parent = self._parent(j)
            if j > 0 and self._data[j]._key < self._data[parent]._key:
                self._swap(j,parent)
                self._upheap(parent)

        def _downheap(self,j):
            if self._has_left(j):
                left = self._left(j)
                small_child = left
                if self._has_right(j):
                    right = self._right(j)
                    if self._data[right]._key < self._data[left]._key:
                        small_child = right
                if self._data[small_child]._key < self._data[j]._key:
                    self._swap(j,small_child)
                    self._downheap(small_child)

        def __init__(self):
            self._data = []

        def __len__(self):
            return len(self._data)

        def add(self,key,value):
            self._data.append(self._Item(key,value))
            self._upheap(len(self._data) - 1)
        def min(self):
            if self.is_empty():
                print("Heap is empty")
            item = self._data[0]
            return(item._key,item._value)

        def remove_min(self):
            if self.is_empty():
                print("Heap is empty")
            self._swap(0,len(self._data) -1)
            item = self._data.pop()
            self._downheap(0)
            return (item._key,item._value)
        def remove(self,values):
            for i in range(len(self._data)):
                if self._data[i]._key == values:
                    index= i
            self._swap(index,len(self._data)-1)
            item = self._data.pop()
            self._downheap(index)
        def printheap(self):
            for i in range(len(self._data)):
                print(self._data[i]._key,self._data[i]._value)

    class AdaptableHeapPriorityQueue(HeapPriorityQueue):
        class Locator(HeapPriorityQueue._Item):
            __slots__ = '_index'
            def __init__(self,k,v,j):
                super().__init__(k,v)
                self._index=j
        def _swap(self, i, j):
            super()._swap(i,j)
            self._data[i]._index = i
            self._data[j]._index = j
        def  _bubble(self, j):
            if j > 0 and self._data[j] < self._data[self._parent(j)]:
                self._upheap(j)
            else:
                self._downheap(j)
        def add(self, key, value):
            token = self.Locator(key, value, len(self._data))
            self._data.append(token)
            self._upheap(len(self._data)-1)
            return token
        def update(self, loc, newkey, newval):
            j = loc._index
            if not (0 <= j < len(self) and self._data[j] is loc):
                raise ValueError('Invalid locator')
            loc._key = newkey
            loc._value = newval
            self._bubble(j)
        def remove(self, loc):
            j = loc._index
            if not (0 <= j < len(self) and self._data[j] is loc):
                raise ValueError( 'Invalid locator')
            if j == len(self)-1:
                self. data.pop( )
            else:
                self. swap(j, len(self)-1)
                self. data.pop( )
                self. bubble(j)
            return (loc._key, loc._value)



    def dijkstra(G,b,start,finish):
        D={}
        pq=AdaptableHeapPriorityQueue()
        pqlocator={}
        cloud={}
        for vertex in G.keys():
            if(vertex == start):
                D[vertex]=0
            else:
                D[vertex]=float('inf')
            pqlocator[vertex]=pq.add(D[vertex],vertex)
            #print(vertex)

        while len(pq)!=0:
            key,u=pq.remove_min()
            cloud[u]=key
            #print("Silindi : ",u)
            del pqlocator[u]
            for vertex in G[u]:
                if vertex not in cloud.keys():
                    #print("Cloud keys : ",cloud.keys())
                    #print("Vertex : ",vertex)
                    #print("U: ",u)
                    if portalIndexs[vertex]!=-1 and portalIndexs[u] != -1:
                        time = portalTime[portalIndexs[vertex]]
                        if D[u] > time[1]:
                            #print("girdim cook fena")
                            #print("Cloud U : ",cloud[u],"u : ",u)

                            weight = float('inf')
                        elif D[u] < time[0]:
                            weight = time[0]-cloud[u]
                        else:
                            weight=0
                            #print("Portala girdim")
                        del portalIndexs[vertex],
                        del portalIndexs[u]
                    else:
                        weight=b
                    #print(weight)
                    if D[u]+weight<D[vertex]:
                        D[vertex]=D[u]+weight
                        #print("Şurdan geliyom ",u)
                        #print("Şuna : ",vertex,"Şu yüklendi : ",D[vertex])
                        pq.update(pqlocator[vertex],D[vertex],vertex)
        #print(cloud)
        try:
            return cloud[finish]
        except:
            return float('inf')
    #portalTime example
    #portalTime=[(5,25),(10,15)]
    #portalIndexs example
    #portalIndexs[(1,2)]=1 defaultdict return -1
    #G example
    #G[(0,0)]=[(0,1),(1,0),(1,2)]
    G=defaultdict(list)
    portalTime={}
    portalIndexs=defaultdict(negativer)
    N,M=matrixX,matrixY
    Matrice=[]
    for i in range(N):
        line = matrix[i]
        Matrice.append([])
        for j in range(M):
            Matrice[i].append(line[j])
    for i in range(N):
        for j in range(M):
            if(Matrice[i][j]!="X"):
                try:
                    if(Matrice[i][j+1]=="0"):
                        G[(i,j)].append((i,j+1))
                        G[(i,j+1)].append((i,j))
                except:
                    nothing=0
                try:
                    if(Matrice[i+1][j]=="0"):
                        G[(i,j)].append((i+1,j))
                        G[(i+1,j)].append((i,j))
                except:
                    nothing=0
    steptime=adim
    p=portalNum
    for i in range(p):
        a,b,c,d=portalList[i][0],portalList[i][1],portalList[i][2],portalList[i][3]
        portalIndexs[(a,b)]=i
        portalIndexs[(c,d)]=i
        G[(a,b)].append((c,d))
        G[(c,d)].append((a,b))
        t1,t2=portalList[i][4],portalList[i][5]
        portalTime[i]=(t1,t2)
    a,b=startX,startY
    start=(a,b)
    c,d=finishX,finishY
    finish=(c,d)
    #print(G[(2,0)])
    #print("Start : ",start,"Finish : ",finish)
    if dijkstra(G,steptime,start,finish) == float('inf'):
        print("olmadı")
        continue
    break
