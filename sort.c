#include<stdio.h>
void print(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		printf(" %d ",a[i]);
}
void insertion(int a[],int n)
{
	int i,j,t;
	for(i=1;i<n;i++)
	{
		t=a[i];
		j=i-1;
		for(;j>=0 && t<a[j];j--)
			a[j+1]=a[j];
		a[j+1]=t;
	}
	printf("\nSorted array after insertion sort algorithm=");
	print(a,n);
}
void bubble(int a[],int n)
{
	int i,j,t,k;
	for(i=0;i<n;i++)
	{
		for(j=n-1;j>=i+1;j--)
		{
			if(a[j]<a[j-1])
			{
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
				print(a,n);
				printf("\n");
			}
		}
	}
}
int main()
{
	int a[101];
	int i,n;
	printf("\nEnter no of array elements=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("\nOriginal array=");
	print(a,n);
	bubble(a,n);
	//insertion(a,n);
	return 0;
}