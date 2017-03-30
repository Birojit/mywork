#include<stdio.h>
#define sm 1001
#define sl 10000001
#define s1 1000
#define s2 10000000
int min_tree[sm];
int max_tree[sm];
int n;
int maxmin(int a1,int a2,int op)
{
	if(op==1)
	return(a1>a2?a1:a2);
	return(a1<a2?a1:a2);
}
void create_max(int a[],int low,int high,int i)
{
	if(low==high)
	{
		max_tree[i]=a[low];
		return;
	}
	int mid;
	mid=(low+high)/2;
	create_max(a,low,mid-1,i*2+1);
	create_max(a,mid,high,i*2+2);
	max_tree[i]=maxmin(max_tree[i*2+1],max_tree[i*2+2],1);	
}

void create_min(int a[],int low,int high,int i)
{
	if(low==high)
	{
		min_tree[i]=a[low];
		return;
	}
	int mid;
	mid=(low+high)/2;
	create_min(a,low,mid,i*2+1);
	create_min(a,mid+1,high,i*2+2);
	min_tree[i]=maxmin(min_tree[i*2+1],min_tree[i*2+2],2);
}

int search_max(int l,int h,int i,int q1,int q2)
{

	if(q1>h || q2<l || l<0 || h>=n)
		return 0;
	return maxmin(search_max(l,(l+h)/2-1,i*2+1,q1,q2),search_max((l+h)/2,h,i*2+2,q1,q2),1);
}

int search_min(int l,int h,int i,int q1,int q2)
{
	if(q1>h || q2<l || l<0 || h>=n)
		return sm;
	return maxmin(search_min(l,(l+h)/2-1,i*2+1,q1,q2),search_min((l+h)/2,h,i*2+2,q1,q2),2);
}

int main()
{
	int l,r,i,q,a[100001];
	for(i=0;i<s1;i++)
	{
		min_tree[i]=sm;
		max_tree[i]=0;
	}
	//initialization of global seg-trees

	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	create_max(a,0,n-1,0);
	create_min(a,0,n-1,0);
	double res,k;
	scanf("%d",&q);
	int slw1,slw2,slw3,fast;
	while(q--)
	{
		scanf("%d%d",&l,&r);
		slw1=search_max(0,n-1,0,0,l-1);
		slw2=search_max(0,n-1,0,r+1,n-1);
		slw3=slw1>slw2?slw1:slw2;
		slw2=slw3;
		slw1=search_max(0,n-1,0,l,r);
		fast=search_min(0,n-1,0,l,r);

		k=((slw1-fast*1.0)/2);
		res=k>slw2?k:slw2;

		printf("%.1lf\n",res+slw1);
	}
	return 0;
}