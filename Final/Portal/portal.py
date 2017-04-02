from collections import defaultdict
def negativer():
    return -1
class PriorityQueueBase:
    class _Item:
        __slots__ = '_key','_value'

        def __init__(self,k,v):
            self._key=k
            self._value=v

        def __It__(self,other):
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
        j = loc. index
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
    for vertex in G:
        D[vertex]=float('inf')
        pqlocator[vertex]=pq.add(D[vertex],vertex)
    D[start]=0
    cloud={}
    while len(pq)!=0:
        key,u=pq.remove_min()
        cloud[u]=key
        del pqlocator[u]
        for vertex in G[u]:
            if vertex not in cloud:
                if portalIndexs[vertex]!=-1 and portalIndexs[u] != -1:
                    time = portalTime[portalIndexs[vertex]]
                    if cloud[u] > time[1]:
                        weight = float('inf')
                    elif cloud[u] < time[0]:
                        weight = time[0]-cloud[u]
                    else:
                        weight=0
            else:
                weight=b
            if(D[u]+weight<D[vertex]):
                D[vertex]=D[u]+weight
                pq.update(pqlocator[vertex],D[vertex],vertex)
    return cloud[finish]
#portalTime example
#portalTime=[(5,25),(10,15)]
#portalIndexs example
#portalIndexs[(1,2)]=1 defaultdict return -1
#G example
#G[(0,0)]=[(0,1),(1,0),(1,2)]
G=defaultdict(list)
portalTime={}
portalIndexs=defaultdict(negativer)
N,M=map(int,input().split())
Matrice=[]
for i in range(N):
    line = input().split()
    Matrice.append([])
    for j in range(M):
        Matrice[i].append(j)
for i in range(N-1):
    for j in range(M-1):
        if(Matrice[i][j]!="x"):
            if(Matrice[i][j+1]=="0"):
                G[(i,j)].append((i,j+1))
                print("ekledim")
                G[(i,j+1)].append((i,j))
            if(Matrice[i+1][j]=="0"):
                G[(i,j)].append((i+1,j))
                G[(i+1,j)].append((i,j))
steptime=int(input())
p=int(input())
for i in range(p):
    a,b,c,d=map(int,input().split())
    portalIndexs[(a,b)]=i
    portalIndexs[(c,d)]=i
    G[(a,b)].append((c,d))
    G[(c,d)].append((a,b))
    t1,t2=map(int,input().split())
    portalTime[i]=(t1,t2)
a,b=map(int,input().split())
start=(a,b)
c,d=map(int,input().split())
finish=(c,d)
print(dijkstra(G,steptime,start,finish))
