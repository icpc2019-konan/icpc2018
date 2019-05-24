while(True):
    n=int(input())
    if(n==0):
        break
    a=list(map(float,input().split()))
    ave=sum(a)/n
    count=0
    for i in a:
        if(i<=ave):
            count+=1
    print(count)