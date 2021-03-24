import sys

input=sys.stdin.readline
n=int(input())

wine=[0]
for i in range (n):
    wine.append(int(input()))

dp=[0]
dp.append(wine[1])
if n>1:
    dp.append(wine[1]+wine[2])

for i in range (3,n+1):
    dp.append(max(dp[i-1],dp[i-2]+wine[i],dp[i-3]+wine[i-1]+wine[i]))
    #이번에 안마시는 경우, 세번전 두번전에 마시고 이번에 마시는 경우, 세번전 한번전에 마시고 이번에 마시는 경우

print(dp[n])
