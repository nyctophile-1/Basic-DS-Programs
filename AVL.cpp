#include<iostream>
#include<stack>
using namespace std;

class node
{
	int data;
	node* left;
	node*right;
	public:
		node(int v)
		{
			data=v;
			right=0;
			left=0;
		}
		friend class AVL;
};

class AVL
{
	node *root;

	public:
		AVL()
		{
			root=0;
		}
		int balanceFactor();
		void balanceCheck();
		int height();
		void insertion();
		void rightRotate(node *);
};

int AVL::height(node *n)
{
	if(n==0)
		return 0;
	int l=height(n->left);
	int r=height(n->right);
	
	if(l>r)
		return l+1;
	else
		return r+1;
}
int AVL::balanceFactor(node *n)
{
	int x=height(n->left)-height(n->right);
	return x;
}

void AVL::rightRotate(node *pivot)
{
	node* x=pivot->left;
	node* T2=x->right;
	
	x->right=pivot;
	pivot->left=T2;
	
	return x;
}
int AVL::insertion(int value)
{
	if(root==0)
		root=new node(value);
	else
	{	
		Stack<node *> S;
		node *ptr =root;
		node *prev=root;
		while(ptr!=0)
		{
			if(value<ptr->data)
			{
				s.push(ptr);		
				prev = ptr;
				ptr=ptr->left;
			}
			else
			{
				s.push(ptr);
				prev = ptr;
				ptr=ptr->right;
			}
				
		}
		if(value<prev->data)
		{
			prev->left=new node(value);
		}
		else
		{
			prev->right=new node(value);
		}
		
		while(!s.empty())
		{
			node *n=s.top();
			s.pop();
			
			int balance = height(n);
			if(balance >-1)
				if(value < n->left->data)
				{
					node *temp=s.top();
					if(temp->data<n->data)
					{
						temp->right=rightRotate(n);
					}
					else
					{
						temp->left=rightRotate(n);
					}
				}
		}
		
		
	}
}
int AVL::balanceCheck(node *ptr)
{
	
}
