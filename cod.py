n,k=map(int,input().split())
a=list(map(int,input().split()))
a=sorted(a)
for i in range(n):
    if(a[i]>k):
        break
