import sys

def check(board):
    count=1
    maxi=1
    for i in range(0,n):
        count=1
        for j in range(1,n):
            if board[i][j]==board[i][j-1]:
                count+=1
            else:
                count=1
            if(count>maxi):
                maxi=count
        count=1
        for j in range(1,n):
            if board[j][i]==board[j-1][i]:
                count+=1
            else:
                count=1
            if(count>maxi):
                maxi=count
    
    return maxi

input=sys.stdin.readline
n=int(input())
board=[list(input().rstrip('\n')) for _ in range(n)]
res=0
tmp=0
for i in range (0,n):
    for j in range (0,n):
        if i+1<n:
            board[i+1][j],board[i][j]=board[i][j],board[i+1][j]
            tmp=check(board[:])
            if tmp>res:
                res=tmp
            board[i+1][j],board[i][j]=board[i][j],board[i+1][j]
        
        if j+1<n:
            board[i][j+1],board[i][j]=board[i][j],board[i][j+1]
            tmp=check(board[:])
            if tmp>res:
                res=tmp
            board[i][j+1],board[i][j]=board[i][j],board[i][j+1]
        

print(res)
