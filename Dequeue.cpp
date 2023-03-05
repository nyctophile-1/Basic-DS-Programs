/*
	Name: 						Akshita Gupta
	Copyright: 
	Author: 
	Date: 						28-10-20 12:30
	Description: 				Implement a Deque using Linked representation 
								Following operations to be implemented : 	
								enqueue_front, enqueue_rear, dequeue_front, dequeue_rear, isempty, front_el, rear_el clear
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
		void enqueueRear(int);
		void enqueueFront(int);
		void display();
		int isempty();
		void deleteLL();
		void dequeueFront();
		void dequeueRear();
		void frontel();
		void rearel();
		~QueueLL()
		{
			deleteLL();
		}
};

void QueueLL::enqueueRear(int value)
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

void QueueLL::enqueueFront(int value)
{
	if(isempty())
	{
		enqueueRear(value);
	}
	else
	{
		node* n=new node(value,front);
		front=n;
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
		cout<<"Linked List Empty !";
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
void QueueLL::rearel()
{
	if(!isempty())
	{
		node* n=front;
		for(;n->next!=NULL;n=n->next);
		cout<<endl<<"Rear-most Element :"<<n->data;
	}
	else
	{
		cout<<"\nEmpty Queue !";
	}
}
void QueueLL::dequeueFront()
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

void QueueLL::dequeueRear()
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
		node* n=front;
		for(;n->next->next!=NULL;n=n->next); 
		delete(n->next);
		n->next=NULL;
	}
}
int main()
{
	QueueLL obj;
	while(1)
	{
		int c;
		int ele;
		cout<<"\n1)Enter Front\t3)Remove Front \t\t5)Front-Most \t7)Check Emptiness \t9)Exit\n2)Enter Back \t4)Remove Back \t\t6)Rear-Most \t8)Clear\nEnter Choice :";
		cin>>c;
		switch(c)
		{
			case 1:						cout<<"\nEnter Element :";
										cin>>ele;
										obj.enqueueFront(ele);
										obj.display();
										break;
										
			case 2:						cout<<"\nEnter Element :";
										cin>>ele;
										obj.enqueueRear(ele);
										obj.display();
										break;
																	
			case 3:						obj.dequeueFront();
										obj.display();
										break;
			
			case 4:						obj.dequeueRear();
										obj.display();
										break;
										
			case 5:						obj.frontel();
										break;
										
			case 6:						obj.rearel();
										break;					
			
			case 7:						cout<<"\nEmptiness :"<<obj.isempty();
										break;
										
			case 8:						obj.deleteLL();
										break;
										
			case 9:						obj.deleteLL();
										exit(0);
			
		}
	}
	
}
