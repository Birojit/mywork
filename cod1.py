# cook your dish here
def mergeSort(alist):
    if len(alist)>1:
        mid = len(alist)//2
        lefthalf = alist[:mid]
        righthalf = alist[mid:]

        mergeSort(lefthalf)
        mergeSort(righthalf)

        i=0
        j=0
        k=0
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                alist[k]=lefthalf[i]
                i=i+1
            else:
                alist[k]=righthalf[j]
                j=j+1
            k=k+1

        while i < len(lefthalf):
            alist[k]=lefthalf[i]
            i=i+1
            k=k+1

        while j < len(righthalf):
            alist[k]=righthalf[j]
            j=j+1
            k=k+1
n,k=map(int,input().split())
a=[0]*n
a=list(map(int,input().split()))
a=mergeSort(a)
s=0
for i in range(n-1):
    if(a[n-1]-a[i]<k):
        break
    for j in range(i+1,n):
    	if(a[j]-a[i]>=k):
    		s+=n-j
    		break
print(s) 