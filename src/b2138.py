import sys

def click(current):
    count=1
    current[0]=int(not current[0])
    current[1]=int(not current[1])

    for i in range(1,n):
        if(current[i-1]!=result[i-1]):
            count+=1
            current[i-1]=int(not current[i-1])
            current[i]=int(not current[i])
            if(i!=n-1):
                current[i+1]=int(not current[i+1])
    if(current==result):
        return count
    else:
        return -1

def noClick(current):
    count=0
    for i in range(1,n):
        if(current[i-1]!=result[i-1]):
            count+=1
            current[i-1]=int(not current[i-1])
            current[i]=int(not current[i])
            if(i!=n-1):
                current[i+1]=int(not current[i+1])
    if(current==result):
        return count
    else:
        return -1
    
input=sys.stdin.readline

n=int(input())

current=list(map(int,input().rstrip('\n')))
result=list(map(int,input().rstrip('\n')))

res1=click(current[:])
res2=noClick(current[:])

if(res1>=0 and res2>=0):
    print(min(res1,res2))
elif(res1>=0 and res2<0):
    print(res1)
elif (res1<0 and res2>=0):
    print(res2)
else:
    print(-1)
    
    



