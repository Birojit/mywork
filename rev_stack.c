#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
	int data[1001];
	int top;
}stack;

stack push(stack s,int key)
{
	s.data[++s.top]=key;
	return s;
}

int pop(stack *s)
{
	int key=s->data[s->top--];
	return key;
}

int main()
{
	int n,op;
	stack s1,s2;
	s1.top=-1;
	s2.top=-1;
	do
	{
		printf("\nEnter data to push=");
		scanf("%d",&n);
		s1=push(s1,n);
		printf("\nEnter more data?1->yes=");
		scanf("%d",&op);
	}while(op==1);
	int temp;
	int c;
	c=s1.top+1;
	int q=-1;int i;
	printf("\nOriginal Stack=");
	for(i=0;i<=s1.top;i++)
		printf(" %d ",s1.data[i]);
	while(c--)
	{
		temp=pop(&s1);
		while(s1.top!=q)
			s2=push(s2,pop(&s1));
		q++;
		s1=push(s1,temp);
		while(s2.top!=-1)
			s1=push(s1,pop(&s2));
	}
	printf("\nFinal stack=");
	for(i=0;i<=s1.top;i++)
		printf(" %d ",s1.data[i]);
	printf("\n");
	return 0;
}