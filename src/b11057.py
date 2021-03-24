import sys

input=sys.stdin.readline

n=int(input())
dp=[[0 for i in range(1001)] for j in range(1001)]

for i in range(0,10):
    dp[1][i]=1


for i in range(2,n+1):
    for j in range(0,10):
        for k in range(0,j+1):
            dp[i][j]+=dp[i-1][k]
            dp[i][j]%=10007

sum=0
for i in range (0,10):
    sum+=dp[n][i]

sum=sum%10007

print(sum)
