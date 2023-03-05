/*
	Name: 						Akshita Gupta
	Copyright: 
	Author: 
	Date: 						28-10-20 12:30
	Description: 			 

// Write a program to implement circularly linked list which supports the following operations:
// (i) Insert an element x at the front of the circularly linked list
// (ii) Insert an element x after an element y in the circularly linked list
// (iii)Insert an element x at the back of the circularly linked list
// (iv) Remove an element from the back of the circularly linked list
// (v) Remove an element from the front of the circularly linked list
// (vi) remove the element x from the circularly linked list
// (vii)Search for an element x in the circularly linked list and return its pointer
// (viii) Concatenate two circularly linked lists
//
// Please ensure :
// - use only to access the linked list
// - create appropriate constructors/destructors
// - class member variables must be private
*/

#include<iostream>
using namespace std;

class node
{
  int val;
  node *next;
public:
  friend class CLL;	
  
  node(int v,node* n)
  {
    val=v;
    next=n;
  }
};

class CLL
{
  node *tail;
public:
  CLL()
  {
    tail=NULL;
  }

  void insertFront(int);
  void insertAfterEl(int y,int el);
  void insertBack(int el);
  void display();
  void deleteCLL();
  void removeFront();
  void removeBack();
  void remove(int ele);
  node* searchEl(int ele);
  void concatenate(CLL &obj);
  int frontel();
  ~CLL()
  {
    deleteCLL();
  }
};

void CLL::insertFront(int el)
{
  if(tail==NULL)
  {
    tail= new node(el,NULL);
    tail->next=tail;
  }
  else
  {
  	node *n=new node(el,tail->next);
  	tail->next=n;	
  }
}
void CLL::insertAfterEl(int y,int el)
{
	if(tail!=NULL)
	{
		node* temp=tail->next;
		for(;temp!=tail;temp=temp->next)
		{
			if(temp->val==y)
			{
				temp->next=new node(el,temp->next);
				break;
			}
		}
	
	}
}
void CLL::insertBack(int el)
{
  if(!tail)
  {
    insertFront(el);
  }
  else
  {
    node*temp = new node(el,tail->next);
    tail->next=temp;
	tail=temp;
  }
}
void CLL::removeFront()
{
	if(tail==NULL)
	{
		cout<<"\nEmpty List";
	}
	else if(tail->next==tail)
	{
		delete tail;
		tail=NULL;
	}
	else
	{
		node* n=tail->next;
		tail->next=n->next;
		delete n;
	}
}
void CLL::removeBack()
{
	if(tail==NULL || tail->next==tail)
	{
		removeFront();
	}
	else
	{
		node* n=tail->next;
		for(;n->next!=tail;n=n->next);
		n->next=tail->next;
		delete tail;
		tail=n;
	}
}
void CLL::display()
{
  if(tail!=NULL)
  {
    cout<<"\nThe Circular Linked List is :";
    node* temp=tail->next;
    do 
	{
      cout<<temp->val<<" ";
      temp=temp->next;
    } while(temp!=tail->next);
  }
  else
  {
    cout<<"Empty List!";
  }
}
void CLL::remove(int ele)
{
	if(tail==NULL || tail==tail->next)
	{
		removeFront();
	}
	else
	{
		node* prev=	tail;
		node* n=	tail->next;
		do
		{
			if(n->val==ele)
			{
				prev->next=n->next;
				delete n;
				break;
			}
			prev=prev->next;
			n=n->next;
		}while(n!=tail->next);
	}
}
void CLL::deleteCLL()
{
	if(tail==NULL)
  	{
  		cout<<"Deleted !";
  	}
  else if(tail->next==tail)
  {
  		delete tail;
  		tail=NULL;
  }	
  else if(tail)
  {
    node*n;
    node*cur=tail->next;
    do {
      /* code */
      n=cur;
      cur=cur->next;
      delete n;

    } while(cur!=tail);
    delete cur;
    cur=NULL;
  }
  
  cout<<"\nDeletion Successful !";
}
node* CLL::searchEl(int ele)
{
	if(tail!=NULL)
	{
		node*n=tail->next;
		do
		{
			if(n->val==ele)
			{
				return n;
			}
			n=n->next;
		}while(n!=tail->next);
	}
	return 0;
}
int CLL::frontel()
{
	if(tail)
	{
	return(tail->next->val);
	}
}
void CLL::concatenate(CLL &obj3)
{
	while(obj3.tail)
	{
		int x=obj3.frontel();
		insertBack(x);
		obj3.removeFront();
	}
	display();
	cout<<"\nReturning !";
}
int main()
{
  CLL obj;
  CLL obj3;
  while(1)
	{
		int c;
		int el,y;
		cout<<"\n1)Enter Front\t3)Enter After Y \t5)Remove Back \t\t7)Search \t9)Exit\n2)Enter Back \t4)Remove Front \t\t6)Remove Element\t8)Concatenate\nEnter Choice :";
		cin>>c;
		switch(c)
		{
			case 1:						cout<<"\nEnter Element :";
										cin>>el;
										obj.insertFront(el);
										obj.display();
										break;
										
			case 2:						cout<<"\nEnter Element :";
										cin>>el;
										obj.insertBack(el);
										obj.display();
										break;
																	
			case 3:						cout<<"\nEnter Element Y and Element you wish to Enter ::";
										cin>>y>>el;
										obj.insertAfterEl(y,el);
										obj.display();
										break;
									
			case 4:						obj.removeFront();
										obj.display();
										break;
			
			case 5:						obj.removeBack();
										obj.display();
										break;
									
			case 6:						cout<<"\nEnter Element you wish to remove :";
										cin>>el;
										obj.remove(el);
										obj.display();
										break;
										
			case 7:						cout<<"\nEnter Element :";
										cin>>el;
										cout<<"\nElement Address :"<<obj.searchEl(el);			
										break;		
			
			case 8:						{	
										cout<<"\nEnter Size for CLL -2 :";
										cin>>el;
										cout<<"\nEnter Elements :";
										for(int i=0;i<el;i++)
										{
											cin>>y;
											obj3.insertBack(y);
										}
										obj.concatenate(obj3);
										cout<<"Concat Done !";
										obj.display();
										break;
										}
										
										
										
			case 9:						obj.deleteCLL();
										obj3.deleteCLL();
										exit(0);
			
		}
  	
	}
	return 0;
}
