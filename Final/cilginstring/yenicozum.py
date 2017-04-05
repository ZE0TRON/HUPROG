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
    index=-1
    for i in range(len(string)):
        if(string[i]==substr[0]):
            index=i
            for j in range(len(substr)):
                if(i+j<len(string)):
                    if(string[i+j]!=substr[j]):
                        index=-1
                else:
                    index=-1
    return index



def Bulkardes(start,end,counter):
    counter2=0
    for i in range(len(start)):
        if start[i]==end[i] :
            counter2+=1
        else:
            break
    if counter2==len(start):
        return counter
    print("Kırpılmadan Start  : ",start,"End : ",end)
    start=start[counter2:]
    end=end[counter2:]
    LCS=lcs(start,end)
    print("Start  : ",start,"End : ",end)
    if(len(LCS)==0):
        startindex=0
        endindex=0

    else:
        startindex=SubStrLocation(start,LCS)
        endindex=SubStrLocation(end,LCS)
    if(startindex==0):
        end=end[endindex:]+end[:endindex]

        return Bulkardes(start,end,counter+1)
    else:
        start=start[startindex:]+start[:startindex]
        end=end[endindex:]+end[:endindex]
        return Bulkardes(start,end,counter+2)

Q=int(input())
for test in range(Q):
    N=int(input())
    s1 ,aranan = input().split()
    print(s1,aranan)
    print(Bulkardes(s1,aranan,0))
