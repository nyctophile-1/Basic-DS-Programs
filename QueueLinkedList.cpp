/*
	Name: 						Akshita Gupta
	Copyright: 					
	Author: 			
	Date: 						28-10-20 12:19
	Description: 				Implement a Queue using Linked representation 
								Following operations to be implemented : 
								enqueue, dequeue, isempty, frontel, clear
*/

#include<iostream>
using namespace std;

class node
{
	int data;
	node* next;
	public:
		friend class QueueLL;
		node(int value,node* temp)
		{
			data=value;
			next=temp;
		}
};

class QueueLL
{
	node* front;
	node* rear;
	public:
		QueueLL()
		{
			front=NULL;
			rear=NULL;
		}
		void enqueue(int);
		void display();
		int isempty();
		void deleteLL();
		void dequeue();
		void frontel();
		~QueueLL()
		{
			cout<<"\nDeleting Elements";
			deleteLL();
		}
};

void QueueLL::enqueue(int value)
{
	if(isempty())
	{
		front=new node (value,NULL);
		rear=front;
	}
	else
	{
		rear->next=new node(value,NULL);
		rear=rear->next;
	}
}

int QueueLL::isempty()
{
	return(front==NULL);
}

void QueueLL::display()
{
	if(!isempty())
	{
		node*temp=front;
		cout<<"\nThe Queue Linked List is :";
		for(;temp!=NULL;temp=temp->next)
		{
			cout<<temp->data<<" ";
		}
	}
	else
	{
		cout<<"\nEmpty Queue";
	}
}

void QueueLL::deleteLL()
{
	if(!isempty())
	{
		node* temp;
		node* curr=front;
		while(curr!=NULL)
		{
			temp=curr;
			curr=curr->next;
			delete temp;
		}
		front=NULL;
		rear=NULL;
	}
}

void QueueLL::frontel()
{
	if(!isempty())
	{
		cout<<endl<<"Front-most Element :"<<front->data;
	}
	else
	{
		cout<<"\nEmpty Queue !";
	}
}

void QueueLL::dequeue()
{
	if(isempty())
	{
		cout<<"\nEmpty Queue !";
	}
	else if(front==rear)
	{
		delete front;
		front=NULL;
		rear=NULL;
	}
	else
	{
		node* n =front;
		front=front->next;
		delete n;
	}
}

int main()
{
	QueueLL obj;
	while(1)
	{
		int c;
		int ele;
		cout<<"\n1)Enter \t3)Front Element \t5)Check Emptiness \n2)Remove \t4)Clear \t\t6)Exit\nEnter Choice :";
		cin>>c;
		switch(c)
		{
			case 1:						cout<<"\nEnter Element :";
										cin>>ele;
										obj.enqueue(ele);
										obj.display();
										break;
										
			case 2:						obj.dequeue();
										obj.display();
										break;
										
			case 3:						obj.frontel();
										break;
										
			case 4:						obj.deleteLL();
										break;
			
			case 5:						cout<<"\nEmptiness :"<<obj.isempty();
										break;
										
			case 6:						obj.deleteLL();
										exit(0);
			
		}
	}
	
}
