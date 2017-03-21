from collections import defaultdict
def negativer():
    return -5

def editDistDP(str1, str2, m, n):
    # Create a table to store results of subproblems
    dp = [[0 for x in range(n+1)] for x in range(m+1)]

    # Fill d[][] in bottom up manner
    for i in range(m+1):
        for j in range(n+1):

            # If first string is empty, only option is to
            # isnert all characters of second string
            if i == 0:
                dp[i][j] = 0    # Min. operations = j

            # If second string is empty, only option is to
            # remove all characters of second string
            elif j == 0:
                dp[i][j] = 0    # Min. operations = i

            # If last characters are same, ignore last char
            # and recur for remaining string
            elif str1[i-1] == str2[j-1]:
                dp[i][j] = dp[i-1][j-1]

            # If last character are different, consider all
            # possibilities and find minimum
            else:
                dp[i][j] = min(dp[i][j-1]+costs[(W,str2[j])],        # Insert        # Remove
                                   dp[i-1][j-1]+costs[(str1[i-1],str2[j])])    # Replace

    return dp[m][n]












t=int(input())
for test in range(t):
    replika=""
    gercek=""
    costs={}
    memo=defaultdict(negativer)
    N,M=map(int,input().split())
    for i in range(N):
        replika+=input()
    I,K=map(int,input().split())
    for i in range(I):
        gercek+=input()
    for i in range(12):
        a,b,c=map(int,input().split())
        costs[(a,b)]=c
    rmaliyet=int(input())
    p1="wwwwww"+gercek
    p2="www"+gercek+"www"
    p3=gercek+"wwwwww"
