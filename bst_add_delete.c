#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int key;
	struct node *lchild,*rchild;
}node;

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->lchild);
		printf(" %d ",root->key);
		inorder(root->rchild);
	}
}

node* newNode(int item)
{
	node* t;
	t=(node *)malloc(sizeof(node));
	t->key=item;
	t->lchild=t->rchild=NULL;
	return t;
}

node* insucc(node* root)
{
	node* curr;
	curr=root;
	while(curr->lchild!=NULL)
		curr=curr->lchild;
	return curr;
}

node* deleteNode(node* root,int key)
{
	if(root==NULL)
	{
		printf("\nTree is empty\n");
		return root;
	}
	if(key<root->key)
		root->lchild=deleteNode(root->lchild,key);
	else if(key>root->key)
		root->rchild=deleteNode(root->rchild,key);
	else
	{
		if(root->lchild==NULL)
		{
			node* temp;
			temp=root->rchild;
			free(root);
			return temp;
		}
		else if(root->rchild==NULL)
		{
			node* temp=root->lchild;
			free(root);
			return temp;
		}
		node* temp=insucc(root->rchild);
		root->key=temp->key;
		root->rchild=deleteNode(root->rchild,temp->key);
	}
	return root;
}

node* insert(node *root,int key)
{
	if(root==NULL)
		return newNode(key);
	if(key<root->key)
		root->lchild=insert(root->lchild,key);
	else
		root->rchild=insert(root->rchild,key);
	return root;
}

int main()
{
	node *root;
	root=NULL;
	int op,d;
	op=1;
	while(1>0)
	{
		printf("\nEnter yr choice::\n1 to add\n2 to delete\n");
		scanf("%d",&op);
		if(op<1 || op>2)
			break;
		printf("\nEnter data=");
		scanf("%d",&d);
		if(op==1)
			root=insert(root,d);
		if(op==2)
			root=deleteNode(root,d);
		printf("\nUpdated tree=");
		inorder(root);
	}
	printf("\nFinal tree=");
	inorder(root);
	return 0;
}