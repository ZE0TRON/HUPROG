def lcs(S,T):
    m = len(S)
    n = len(T)
    counter = [[0]*(n+1) for x in range(m+1)]
    longest = 0
    lcs_set = []
    for i in range(m):
        for j in range(n):
            if S[i] == T[j]:
                c = counter[i][j] + 1
                counter[i+1][j+1] = c
                if c > longest:
                    lcs_set = []
                    longest = c
                    lcs_set.append(S[i-c+1:i+1])
    nstr=""
    for elem in lcs_set:
        nstr+=elem
    return nstr
def SubStrLocation(string,substr):
    for i in range(len(string)):
        if(string[i]==substr[0]):
            flag=1
            for j in range(len(substr)):
                if(i+j<len(string)):
                    if(string[i+j]!=substr[j]):
                        flag=0
            if(flag==1):
                return i
    return -1



def Bulkardes(start,end,counter):
    counter2=0
    for i in range(len(start)):
        if start[i]==end[i] :
            counter2+=1
        else:
            break
    if counter2==len(start):
        return counter
    else:
        if(len(start)==2):
            print("Serguzest burdan",start,end)
            return counter
    print("Kırpılmadan Start  : ",start,"End : ",end)
    start=start[counter2:]
    end=end[counter2:]
    LCS=lcs(start,end)
    print("Start  : ",start,"End : ",end)
    print("LCS  : ",LCS)

    if(len(LCS)<2):
        #print("Girdim buraya")
        minsk=-5
        minek=-5
        temp1=start
        temp2=end
        minv=float('inf')
        #print("Start : ",start,"End : ",end)
        for j in range(1,len(start)-1):
            for c in range(1,len(end)-1):
                startindex=j
                endindex=c
                temp1=start[startindex:]+start[:startindex]
                temp2=end[endindex:]+end[:endindex]
                #print("Temp1 :",temp1 ,"Temp2 : ",temp2)
                c=Bulkardes(temp1,temp2,counter+1)
                if(c<minv):
                    minv=c
                    minsk=startindex
                    minek=endindex
        #print("Bi kere cikmistim ben")
        start=start[minsk:]+start[:minsk]
        end=end[minek:]+end[:minek]
        return Bulkardes(start,end,counter+1)



    else:
        startindex=SubStrLocation(start,LCS)
        endindex=SubStrLocation(end,LCS)
    if(startindex==0):
        end=end[endindex:]+end[:endindex]

        return Bulkardes(start,end,counter+1)
    else:
        #print("startindex : ",startindex)
        #print("endindex :" ,endindex)
        start=start[startindex:]+start[:startindex]
        end=end[endindex:]+end[:endindex]
        if(start==end):
            return Bulkardes(start,end,counter+1)
        else:
            return Bulkardes(start,end,counter+2)

Q=int(input())
for test in range(Q):
    N=int(input())
    s1 ,aranan = input().split()
    print(s1,aranan)
    print(Bulkardes(s1,aranan,0))
