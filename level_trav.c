#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *l,*r;
}node;

int ht(node* root)
{
	if(root==NULL)
		return 0;
	int lh,rh;
	lh=ht(root->l);
	rh=ht(root->r);
	if(lh>rh)
		return(lh+1);
	else
		return(rh+1);
}

void levelprt(node* root,int level)
{
	if(root==NULL)
		return;
	if(level==1)
		printf(" %d ",root->data);
	else if(level>1)
	{
		levelprt(root->l,level-1);
		levelprt(root->r,level-1);
	}
}


void level_trav(node* root)
{
	int h,i;
	if(root==NULL)
	{
		printf("\nTree is empty\n");
		return;
	}
	h=ht(root);
	for(i=1;i<=h;i++)
		levelprt(root,i);
}

void create(node **root,int d)
{
	if(*root==NULL)
	{
		*root=(node *)malloc(sizeof(node));
		(*root)->data=d;
		(*root)->l=(*root)->r=NULL;
		return;
	}
	if((*root)->data<d)
		create(&((*root)->r),d);
	else
		create(&((*root)->l),d);
}
int main()
{
	int n,op;
	node* root;
	root=NULL;
	op=1;
	do{
		printf("\nEnter data=");
		scanf("%d",&n);
		create(&root,n);
		printf("\nEnter 1 to enter more data=");
		scanf("%d",&op);
	}while(op==1);
	printf("\nList in level traversed order=");
	level_trav(root);
	return 0;
}