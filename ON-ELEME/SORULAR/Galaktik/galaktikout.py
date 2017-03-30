from collections import defaultdict
from math import sqrt
import operator
from sys import argv
class PriorityQueue:
    def __init__(self):
        self.data=[]
        self.pqlocator={}
        self.maxi=0
    def enqueue(self,key,value):
        self.data.append((key,value))
        #print("Sunu ekliyom : ",value," Suraya ekliyom : ",self.maxi)
        self.pqlocator[value]=self.maxi
        self.maxi+=1
    def find_min(self):
        minkv=min(self.data, key=operator.itemgetter(0))[1]
        return minkv
    def dequeue(self):
        minv=float('inf')
        for i in range(len(self.data)):
            if(self.data[i][0]<=minv):
                minv=self.data[i][0]
                mink=i
                minci=self.data[i][1]
        del(self.data[mink])
        #print("Mink",mink)
        self.maxi-=1
        for i in range(mink,self.maxi):
            self.pqlocator[self.data[i][1]]-=1

        return minv,minci
    def __len__(self):
        return len(self.data)
    def update(self,location,nk,nv):
        locationr=self.pqlocator[location]
        #print("Pq Locator : ",self.pqlocator)
        #print("Location : ",location,"Locationr : ",locationr,"Self Data : ",self.data)
        self.data[locationr]=(nk,nv)
    def changePqLocator(self,index):
        del(self.pqlocator[index])


def dijkstra(graph,weights,start,end):
    d={}
    cloud={}
    pqlocator={}
    pq=PriorityQueue()
    for elem in graph.keys():
        if(elem==start):
            d[elem]=0
        else:
            d[elem]=float('inf')
        pq.enqueue(d[elem],elem)
    #print("PQ Data: ",pq.data)
    while pq.find_min()!=end:
        key,u=pq.dequeue()
        cloud[u]=key
        pq.changePqLocator(u)
        for vertex in graph[u]:
            if vertex not in cloud:
                weight=weights[u,vertex]
                if d[u]+weight<d[vertex]:
                    d[vertex]=d[u]+weight
                    pq.update(vertex,d[vertex],vertex)
    key,u=pq.dequeue()
    cloud[u]=key
    return cloud[end]

inpdosya=open("Inputs/input"+argv[1]+".txt","r")
outdosya=open("Outputs/output"+argv[1]+".txt","w")



N,E=map(int,inpdosya.readline().strip().split())
graph=defaultdict(list)
coordinates={}
weights={}
for i in range(E):
    a,b = map(int,inpdosya.readline().strip().split())
    graph[a].append(b)
    graph[b].append(a)
for i in range(N):
    a,x,y,z=map(int,inpdosya.readline().strip().split())
    coordinates[a]=[x,y,z]
p1=int(inpdosya.readline().strip())
p2=int(inpdosya.readline().strip())
hedef=int(inpdosya.readline().strip())
merkez=int(inpdosya.readline().strip())
for i in range(E):
    for elem in graph[i]:
        weights[(elem,i)]=sqrt(((coordinates[elem][0]-coordinates[i][0])**2)+((coordinates[elem][1]-coordinates[i][1])**2)+((coordinates[elem][2]-coordinates[i][2])**2))
a1=dijkstra(graph,weights,merkez,p1)+dijkstra(graph,weights,p1,p2)+dijkstra(graph,weights,p2,hedef)
a2=dijkstra(graph,weights,merkez,p2)+dijkstra(graph,weights,p2,p1)+dijkstra(graph,weights,p1,hedef)
print(min(a1,a2),file=outdosya)
