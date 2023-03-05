//	Write a program to implement doubly linked list which supports the following operations: 
//		(i) 	Insert an element x at the beginning of the doubly linked list 
//		(ii) 	Insert an element x at position in the doubly linked list 
//		(iii)	Insert an element x at the end of the doubly linked list 
//		(iv) 	Remove an element from the beginning of the doubly linked list 
//		(v) 	Remove an element from position in the doubly linked list. 
//		(vi) 	Remove an element from the end of the doubly linked list 
//		(vii) 	Search for an element x in the doubly linked list and return its pointer 
//		(viii) 	Concatenate two doubly linked lists

#include<iostream>
using namespace std;

class node
{
	int value;
	node*next;
	node*prev;
	friend class DLL;
	public:
		node(int v, node*B, node*F)
		{
			value=v;
			prev=B;
			next=F;
		}
};
class DLL
{
	node* head;
	node* tail;
	public:
	DLL()
	{
		head=new node(0,NULL,tail);
		tail=new node(0,head,NULL);	
		head->next=tail;
		tail->prev=head;
	}
		void display();
		void addAtFront(int);
		void addAtPos(int,int);
		void addAtTail(int);
		void removeFront();
		void removePos(int);
		void removeTail();
		node* searchNode(int);
		void concatDLL(DLL);
		void deletenodes();
	~DLL()
	{
		deletenodes();
	}
};
void DLL::display()
{
	if(head->next!=tail)
	{
	
		node*temp=head->next;
		cout<<endl;
		for(;temp!=tail;temp=temp->next)
		{
			cout<<temp->value<<" ";
		}
	}
	else
	{
		cout<<"\nEmpty List !";
	}
}
void DLL::deletenodes()
{
	node*temp;
	node*curr=head;
	while(curr!=tail)
	{
		temp=curr;
		curr=temp->next;
		delete temp;
	}
	delete curr;
}
void DLL::addAtFront(int v)
{
	node* temp=new node(v,head,head->next);
	head->next->prev=temp;
	head->next=temp;
}

void DLL::addAtPos(int pos,int v)
{
	if(head->next!=tail)
	{
		int c=0;
		node*temp=head->next;
		for(;temp!=tail && c<pos-1;temp=temp->next,c++);
	//	add(temp,v);
		temp->prev->next=new node(v,temp->prev,temp);
		temp->prev=temp->prev->next;
	}
	else
	{
		addAtFront(v);
	}
}

void DLL::addAtTail(int v)
{
	tail->prev->next=new node(v,tail->prev,tail);
	tail->prev=tail->prev->next;
}

void DLL::removeFront()
{
	if(head->next!=tail)
	{
		node*temp=head->next;
		temp->next->prev=head;
		head->next=temp->next;
		delete temp;
	}
	else
	{
		cout<<"\nEmpty List !";
	}
}

void DLL::removePos(int pos)
{
	if(head->next!=tail)
	{
		node*temp=head->next;
		int c=0;
		for(;temp->next!=tail && c<pos-1;c++,temp=temp->next);
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			delete temp;			
	}
	else
	{
		cout<<"\nEmpty List !";
	}
}

void DLL::removeTail()
{
	if(head->next!=tail)
	{
		node*temp=tail->prev;
		temp->next->prev=temp->prev;
		temp->prev->next=temp->next;
		delete temp;
	}
	else
	{
		cout<<"\nEmpty List !";
	}
}

node* DLL::searchNode(int x)
{
	if(head->next!=tail)
	{
		node*temp=head->next;
		for(;temp!=tail;temp=temp->next)
		{
			if(temp->value==x)
				return temp;
		}
	}
	return 0;
}

void DLL::concatDLL(DLL obj)
{
	DLL obj3;
	node*temp=head->next;
	while(temp!=tail)
	{
		obj3.addAtTail(temp->value);
		temp=temp->next;
	}
	
	temp=obj.head->next;
	while(temp!=obj.tail)
	{
		obj3.addAtTail(temp->value);
		temp=temp->next;
	}
	obj3.display();
	cout<<"\nEnding with COncat func";
}

int main()
{
	int c;
	int x;
	int ele;
	int pos;
	DLL obj1;
	DLL obj2;
	do
	{
	
	cout<<"\n1)Add Front \t\t4)Remove Front \t\t7)Search Element \n2)Add Position\t\t5)Remove Position \t8)Concatenate DLLs\n3)Add Tail\t\t6)Remove Tail";
	cout<<"\nEnter Choice :";
	cin>>c;
	switch(c)
	{
		case 1:				cout<<"Enter Element :";
							cin>>x;
							obj1.addAtFront(x);
							obj1.display();
							break;
		case 2:				cout<<"\nEnter Element and Position :";
							cin>>x>>pos;
							obj1.addAtPos(pos,x);
							obj1.display();
							break;
		case 3:				cout<<"\nEnter Element :";
							cin>>x;
							obj1.addAtTail(x);
							obj1.display();
							break;
		case 4:				obj1.removeFront();
							obj1.display();
							break;
		case 5:				cout<<"\nEnter Position :";
							cin>>pos;
							obj1.removePos(pos);
							obj1.display();
							break;
		case 6:				obj1.removeTail();	
							obj1.display();
							break;
		case 7:				cout<<"\nEnter Element to Search :";
							cin>>x;
							cout<<"Address (0 for Not Found) :"<<obj1.searchNode(x);
							break;
		case 8:				cout<<"\nEnter No. of Elements for DLL 2 :";
							cin>>x;
							cout<<"\n1)Add At Tail \n2)Add at Front \nEnter Choice :";
							cin>>c;
							if(c==1)
							{
								for(int i=0;i<x;i++)
								{
									cin>>ele;
									obj2.addAtTail(ele);
								}
							}
							else if(c==2)
							{
								for(int i=0;i<x;i++)
								{
									cin>>ele;
									obj2.addAtFront(ele);
								}
							}
							else
							{
								cout<<"\nWrong Choice !";
							}
		
							cout<<"\n1)DLL-1 + DLL-2\n2)DLL-2 + DLL-1\nEnter Choice :";
							cin>>c;
							if(c==1)
							{
								cout<<"\nDLL 1";
								obj1.display();
								obj1.concatDLL(obj2);
							}
							else if(c==2)
							{
								cout<<"\nDLL 2";
								obj2.display();
								obj2.concatDLL(obj1);
							}
							else
							{
								cout<<"\nWrong Choice !";
							}
							break;
	}
	cout<<"\nContinue ? 1/0 :";
	cin>>c;
	}while(c==1);
	return 0;
}
