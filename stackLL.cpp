/*
	Name: 					Akshita Gupta
	Copyright: 
	Author: 
	Date: 					31-10-20 11:26
	Description: 
				Implement a Stack using Linked representation 
				Following operations to be implemented : push, pop, isempty, topel, clear

*/
#include<iostream>
using namespace std;

class node
{
	int data;
	node* next;
	public:
		friend class stackLL;
		node(int v,node* n)
		{
			data=v;
			next=n;
		}
};

class stackLL
{
	node* top;
	public:
		stackLL()
		{
			top=NULL;

		}
		void push(int);
		void pop();
		int isempty();
		int topel();
		void clear();
		void display();
};

int stackLL::isempty()
{
	return(top==NULL);
}
void stackLL::push(int e)
{
	if(isempty())
	{
		top=new node(e,NULL);
	}
	else
	{
		node* temp=new node(e,top);
		top=temp;	
	}
}
void stackLL::pop()
{
	if(isempty())
	{
		cout<<"\nEmpty Stack! ";
	}
	else
	{
		node* temp=top;
		top=top->next;
		delete temp;
	}
}
int stackLL::topel()
{
	if(!isempty())
	{
		return top->data;
	}
	return 0;
}
void stackLL::clear()
{
	if(!isempty())
	{	
	node* curr=top;
	node* temp;
	while(curr!=NULL)
	{
		temp=curr;
		curr=curr->next;
		delete temp;
	}
	top=NULL;
	}
}
void stackLL::display()
{
	if(!isempty())
	{
	cout<<"\nStack Is : ";
	stackLL obj;
	while(!isempty())
	{
		int x=topel();
		cout<<x<<" ";
		pop();
		obj.push(x);
	}
	while(!obj.isempty())
	{
		int x=obj.topel();
		obj.pop();
		push(x);
	}
	}
	else
	{
		cout<<"\nEmpty Stack !";
	}
}

int main()
{
	stackLL S;
	int choice;
	int el;
	while(1)
	{
		cout<<"\n1)Push \t2)Pop \t3)Top \t4)Clear \t5)IsEmpty \t6)Exit\nEnter Choice :";
		cin>>choice;
		switch(choice)
			{
				case 1:							cout<<"\nEnter Element :";
												cin>>el;
												S.push(el);
												S.display();
												break;
												
				case 2:							S.pop();
												S.display();
												break;
												
				case 3:							cout<<"\nTop :"<<S.topel();
												break;
												
				case 4:							S.clear();
												break;
												
				case 5:							cout<<"\nEmpty :"<<S.isempty();
												break;
												
				case 6:							S.clear();
												exit(0);
			}					
	}
	return 0;
}

