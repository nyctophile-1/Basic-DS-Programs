#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
	int data;
	node* left;
	node* right;
	public:
		friend class BST;
		node(int v)
		{
			data=v;
			left=0;
			right=0;
		}
};

class BST{
	node* root;
	public:
		BST()
		{
			root=0;
		}
		void insertData(int);
		int height(node*);
		void searchReplace(int,int);
		void levelDisplay();
		void deleteAll();
		void findToDeleteM(int);
		
		void findtoDeleteC(int el);
		
		void deleteByMerging(node* &);
		void deleteByCopying(node* &);
		
		void inorderTraversal();
		void preorderTraversal();
		void postorderTraversal();
		node* rootReturn();
};
void BST::insertData(int v)
{
	if(root==0)
	{
		root=new node(v);
	}
	else
	{
		node* curr=root;
		node* prev=0;
		while(curr!=0)
		{	
			prev=curr;
			if(v<curr->data)
			{
				curr=curr->left;
			}
			else
			{
				curr=curr->right;
			}	
		}
		if(v<prev->data)
		{
			prev->left=new node(v);
		}
		else
		{
			prev->right=new node(v);
		}
	}
}
int BST::height(node* ptr)
{
	if(!ptr)
	{
		return 0;
	}
	int l=height(ptr->left);
	int r=height(ptr->right);
	
	if(l>r)
	{
		return l+1;
	}
	else
	{
		return r+1;
	}
}
void BST::searchReplace(int val,int replaceY)
{
	node* curr=root;
	while(curr!=0)
	{
		if(curr->data==val)
		{
			break;
		}
		else if(val>curr->data)
		{
			curr=curr->right;
		}
		else
		{
			curr=curr->left;
		}
	}
	if(curr!=0)
	{
	delete curr;
	insertData(replaceY);
	}
	else
	{
		cout<<"\nValue Not Found";
	}
}
void BST::levelDisplay()
{
	if(root==NULL)
	{
		cout<<"\nEmpty BST ";
	}
	else
	{
		queue<node*> q;
		q.push(root);
		node* n;
		while(!q.empty())
		{
			n=q.front();
			q.pop();
			cout<<n->data<<" ";
			
			if(n->left!=0)
			{
				q.push(n->left);
			}
			if(n->right!=0)
			{
				q.push(n->right);
			}
		}
		cout<<endl;
	}
}
void BST::deleteAll()
{
	if(root==NULL)
	{
		cout<<"\nEmpty BST ";
	}
	else
	{
		queue<node*> q;
		q.push(root);
		while(!q.empty())
		{
			node* n=q.front();
			q.pop();
			
			if(n->left!=0)
			{
				q.push(n->left);
			}
			if(n->right!=0)
			{
				q.push(n->right);
			}
			cout<<"Deleting "<<n->data<<endl;
			delete n;
		}
		cout<<"\nDeleted ALL ";
	}
}
void BST::findToDeleteM(int el)
{
	node* temp;
	node* prev;
	temp=root;
	while(temp!=0)
	{
		if(temp->data==el)
		{
			break;
		}
		prev=temp;								//keeping note of deleted node's parent
		if(el>temp->data)
		{
			temp=temp->right;
		}
		else
		{
			temp=temp->left;
		}
	}
	if(temp->data==el && temp!=0)
	{
		if(temp==root)
		{
			deleteByMerging(root);
		}
		else if(prev->right==temp)
		{
			deleteByMerging(prev->right);
		}
		else
		{
			cout<<"\nCalling 3 by DBMerge";
			deleteByMerging(prev->left);
		}
	}
	else if(temp==0)
	{
		cout<<"\nTree Empty ";
	}
	else
	{
		cout<<"\nElement Not Found ";
	}
}
void BST::findtoDeleteC(int el)
{
	node* temp;
	node* prev;
	temp=root;
	while(temp!=0)
	{
		if(temp->data==el)
		{
			break;
		}
		prev=temp;								//keeping note of deleted node's parent
		if(el>temp->data)
		{
			temp=temp->right;
		}
		else
		{
			temp=temp->left;
		}
	}
	if(temp->data==el && temp!=0)
	{
		if(temp==root)
		{
			deleteByCopying(root);
		}
		else if(prev->right==temp)
		{
			deleteByCopying(prev->right);
		}
		else
		{
			deleteByCopying(prev->left);
		}
	}
	else if(temp==0)
	{
		cout<<"\nTree Empty ";
	}
	else
	{
		cout<<"\nElement Not Found ";
	}
}
void BST::deleteByMerging(node* &x)
{
	node *temp=x;
	if(x!=0)
	{
		if(x->right==0)
		{
			x=x->left;
		}
		else if(x->left==0)				
		{
			x=x->right;		   			 /////									  ^^^^^
		}								/////Handling single child/no child cases |||||
		
		else
		{
			temp=x->left;
			while(temp->right!=0)
			{
				temp=temp->right;	
			}	
			temp->right=x->right;
			
			temp=x;
			x=x->left;
		}
	}
	delete temp;
}
void BST::deleteByCopying(node* &x)
{
	node *previous=x;
	node *tmp = x ;
	if ( x->right == 0 ) 
		x = x->left ;
	else if ( x->left == 0 ) 
		x = x->right ;
	else 
	{
		tmp = x->left ; 
		previous = x ; 
		while ( tmp->right != 0 )
		{
			previous = tmp ;
			tmp = tmp->right ;
		}
		x->data = tmp->data ; 
		if ( previous == x)
		previous->left = tmp->left ;
		else previous->right = tmp->left ; 
	}
	delete tmp ; 
}
void BST::inorderTraversal()
{
	if(root!=0)
	{
	
	stack<node*> S;
	node *p=root;
	while(p!=0)
	{
		while(p!=0)
		{
			if(p->right)
			{
				S.push(p->right);
			}
			S.push(p);
			p=p->left;
		}
		p=S.top();
		S.pop();
		while(!S.empty() && p->right==0)
		{
			cout<<p->data<<" ";
			p=	S.top();
			S.pop();
		}
		cout<<p->data<<" ";
		if(!S.empty())
		{
			p=S.top();
			S.pop();
		}
		else
		{
			p=0;
		}
	}
	}
}
void BST::preorderTraversal()
{
	if(root!=0)
	{
		stack <node*> S;
		S.push(root);
		while(!S.empty())
		{
			node *temp=S.top();
			cout<<temp->data<<" ";
			S.pop();
			if(temp->right)
			{
				S.push(temp->right);
			}
			if(temp->left)
			{
				S.push(temp->left);
			}
		}
	}
}
void BST::postorderTraversal()
{
	stack<node*> S;
	node *p=root;
	node *q=root;
	while(p!=0)
	{
		for( ; p->left!=0 ; p=p->left)
		{
			S.push(p);
		}
		while(p->right==0 || p->right==q)
		{
			cout<<p->data<<" ";
			q=p;
			if(S.empty())
			{
				return;
			}
			p=S.top();
			S.pop();
		}
		S.push(p);
		p=p->right;
	}
}
node* BST::rootReturn()
{
	if(root!=0)
	{
		return (root);
	}
	else
	{
		return 0;
	}
}

int main()
{
	BST obj;
	int x,choice,choice2,y;
	while(1)
	{	
		cout<<"\n1.Insert \t2.Height \t3.Breadth Traverse \t4.Depth Traverse\n5.Delete \t6.Search & Replace \t7.Exit ";
		cin>>choice;
		switch(choice)
			{
				case 1:					cout<<"\nEnter Element :";
										cin>>x;
										obj.insertData(x);
										cout<<"\nBST :";
										obj.levelDisplay();
										break;
										
				case 2:					cout<<"\nHeight is "<<obj.height(obj.rootReturn());
										break;
			
				case 3:					cout<<"\nBST :";
										obj.levelDisplay();
										break;
			
				case 4:					cout<<"\n1.Inorder \t2.Preorder \t3.Postorder";
										cin>>choice2;
										switch(choice2)
										{
											case 1:			cout<<"\nBST :";
															obj.inorderTraversal();
															break;
															
											case 2:			cout<<"\nBST :";
															obj.preorderTraversal();
															break;
															
											case 3:			cout<<"\nBST :";
															obj.postorderTraversal();
															break;
										}
										break;
			
				case 5:					cout<<"\nEnter Element to Delete :";
										cin>>x;
										cout<<"\n1.Delete By Copying\t2.Delete By Merging ";
										cin>>choice2;
										switch(choice2)
										{
											case 1:			obj.findtoDeleteC(x);
															cout<<"\nBST :";
															obj.levelDisplay();
															break;
															
											case 2:			obj.findToDeleteM(x);
															cout<<"\nBST :";
															obj.levelDisplay();
															break;
										}
										break;
			
				case 6:					cout<<"\nEnter Element to Search :";
										cin>>x;
										cout<<"\nEnter New Element Data :";
										cin>>y;
										obj.searchReplace(x,y);
										break;
										
				case 7:					obj.deleteAll();
										exit(0);
			}
	}
}
