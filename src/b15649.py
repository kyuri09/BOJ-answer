import sys

def go(index, n,m):

    
    if index==m:
        for i in range(0,m):
            print()
input=sys.stdin.readline
a=[0 for in range(0)]
n,m=map(int,input().split())
go(0,n,m)
