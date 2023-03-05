//Following functions to be implemented - push, pop, isempty, isfull, topel, clear 
//
//Please upload
//- CPP file
//- output for execution of each operation at least once
//
//
//Please ensure the following :
//- A class stack has been created and not global variables
//- Array is allocated memory dynamically not statically
//- output is not shown using  a stack of size 1, please larger stack expected
//- output with just one push and pop operation is not sufficient for you to check for an error, please test your code correctly and send meaningful outputs
//-Menu driven program expected to execute various operations.
//

#include<iostream>
using namespace std;

#define INVALID -1 

//ASSUMING STACK TAKES POSITIVE INTEGERS 

class Stack
{
	int top;				//top
	int *A;					//array
	int size;				//size of Array
	public:
		Stack()
		{
				top=-1;
		}
		void fillDetails(int );		//size and array initialise
		void push(int e);			//pushing In stack
		int pop();					//popping OUT of stack
		int isclear();				//checking if Stack Clear
		int clear();				//Empty Stack
		int isfull();				//checking if Stack FUll
		int topel();				//topmost element, returns -1 if does not exist
		int print();				//print stack contents in the order LIFO
		int deleteA();				//delete Dyanamic Memory 
};
void Stack::fillDetails(int s)
{
	size=s;
	A= new int[size];
}
int Stack::isfull()
{
	return top==size-1;	
}
int Stack::isclear()
{
	return top==INVALID;
}
int Stack::clear()
{
	top=INVALID;
}
int Stack::topel()
{
	if(top==-1)
	return -1;
	else
	return A[top];
}
void Stack::push(int e)
{
	if(isfull()==1)
	{	
		cout<<"\n\t\tStack Full";	
		return;
	}
	A[++top]=e;
}
int Stack::pop()
{
	if(isclear()==1)
	{
		cout<<"\n\t\tStack Empty";
		return -1;
	}
	return(A[top--]);
}
int Stack::deleteA()
{
	delete A;
	return 1;
}
int Stack::print()
{
	Stack X;
	X.fillDetails(this->size);
	cout<<"\n\t\t The ELements in Stack are: ";
	while(!isclear())
	{
		int z=pop();
		cout<<z<<" ";
		X.push(z);
	}
	while(!X.isclear())
	{
		this->push(X.pop());
	}
	X.deleteA();
}

int main()
{
	Stack S;
	cout<<"Enter Size :";
	int size;
	cin>>size;
	S.fillDetails(size);
	int el,x;
	int n;

	do
	{
		cout<<"\n*******************************\n1.Push  \t\t2.Pop  \t\t\t3.Clear \t4.Check if Full \n5.Check if Empty \t6.Topmost ELement \t7.PRINT \t0.EXIT\n\nEnter Preference : ";
		cin>>n;
		cout<<"\n*******************************";
		switch(n)
		{
			case 1:					cout<<"\nEnter ELement :";
									cin>>el;
									S.push(el);
									break;
									
			case 2:					cout<<"\nPopped Element :"<<S.pop();
									break;
									
			case 3:					S.clear();
									break;
									
			case 4:					x=S.isfull();	
									if(x==1)
									cout<<"\n\t\tStack is Full";
									else
									cout<<"\n\t\tStack not FUll";
									break;
									
			case 5:					x=S.isclear();
									if(x==1)
									cout<<"\n\t\tStack is Empty";
									else
									cout<<"\n\t\tStack is not Empty";
									break;
									
			case 6:					cout<<"\n\t\tTopmost Element :"<<S.topel();						
									break;
									
			case 7:					S.print();
									break;
									
			case 0:					int y=S.deleteA();
									if(y==1)
									cout<<"\nMemory Released";
									return 0;					
									exit(0);				
		}	

	}while(1);				
}


