#include <stdio.h>
#include <stdlib.h>

typedef struct node* Node;

int height;
int requiredHeight;
int count;

int *a;
int n;

struct node{
	int data;
	Node left, right;
	};



Node getNode(int);
void swap(int*,int*);

Node insert(Node root,int key)
{
	height=0;
	Node newnode=getNode(key);
	if (!root)
		 return newnode;
	Node p=root,q=0;
	while(p)
	{
		q=p;
		if(key<p->data)
			p=p->left;
		else
			p=p->right;
		
		height++;
	}
	if(key<q->data)
		q->left=newnode;
	else
		q->right=newnode;
	
	return root;
	height++;
}

Node getNode(int key)
{
	Node x= malloc(sizeof(struct node));
	x->data=key;
	x->left=x->right=0;
}

void permute(int* a, int l, int r)
{
    if (l == r)
    {
    	Node root=0;
    	int maxHeight=0;
        for (int i=0;i<n;i++)
        {
        	printf("%d ",a[i]);
        	root=insert(root,a[i]);
        	if (height>maxHeight)
        		maxHeight=height;
        }
        if(maxHeight==requiredHeight)
        	{
        		printf("\tYES");
        		count++;
        	}
        printf("\n");
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
 
            swap(&a[l], &a[i]);
 
            permute(a, l+1, r);
 
            swap(&a[l], &a[i]);
        }
    }
}

void swap(int*a, int*b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void main()
{
	printf("n?");
	scanf("%d",&n);
	a=malloc(sizeof(int)*n);
	int i;
	for(i=0;i<n;i++)
		a[i]=i+1;
	//printf("h?");
	//scanf("%d",&requiredHeight);
	requiredHeight=n-2;
	count=0;
	permute(a,0,n-1);
	printf("%d\n",count);
}
