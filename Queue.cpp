#include<iostream>
using namespace std;

class Queue
{
	public:
	int front;
	int rear;
	int size;
	int *Arr;		
		Queue()
		{
			front=-1;
			rear=-1;
		}
		
		void Details(int);		//Not part of Queue Functions
		void enqueue(int v);
		int  dequeue();
		int  Size();
		bool isfull();
		bool isempty();
		void clear();
		int frontel();
		void display();			//Not part of Queue Functions
		void Delete();			//Not part of Queue Functions

};

void Queue::Details(int x)
{
	size=x;
	Arr=new int[size];
}
bool Queue::isempty()
{
	return((front == -1 )&& (rear == -1));
}

bool Queue::isfull()
{
	if(front==(rear+1)%size)
	return 1;
	else
	return 0;		
}

void Queue::enqueue(int v)
{
	if(isempty()==1)
	{
		rear=0;
		front=0;
		Arr[front]=v;
		
	}
	else if(isfull()==1)
	{
		cout<<"Overflow";
	}
	else
	{
		rear=(rear+1)%size;
		Arr[rear]=v;
	}
	
}

int Queue::dequeue()
{
	if(isempty()==1)
	{
		cout<<"Underflow";
		return -1;
	}
	else if(rear==front)
	{
		int x=Arr[rear];
		rear=-1;
		front=-1;
		return x;		
	}
	else
	{
		int x=Arr[front];
		front=(front+1)%size;
		return x;
	}
}

int Queue::Size()
{
	if(front==-1)
	{
		return 0;
	}
	else if(front <=rear)
	{
		return (rear-front + 1);
	}
	else
	{
		return (size-front+rear +1);
	}
}


void Queue::clear()
{
	front=-1;
	rear=-1;
}
int Queue::frontel()
{
	if(!isempty())
	{
		return Arr[front];
	}
	return -1;
}

void Queue::display()
{
	if(!isempty())
	{
	
		int i;
		cout<<"Elements of the Queue are :\n";
		if(front<=rear)
		{
			for(i=front;i<=rear;i++)
			{
				cout<<Arr[i]<<" ";
			}
		}
		else
		{
			for(i=front;i<size;i++)
			{
				cout<<Arr[i]<<" ";
			}
			for(i=0;i<=rear;i++)
			{
				cout<<Arr[i]<<" ";
			}
		}
		return;
	}
	cout<<"\nEmpty List !!";
}
void Queue::Delete()
{
	delete Arr;
}

int main()
{
	Queue Q;
	int x,c;
	int e;
	cout<<"\nEnter Size of Queue :";
	cin>>x;
	Q.Details(x);
	do
	{
	
	cout<<"\n1)Enqueue\t\t3)Isfull\t\t5)Size\t\t7)Frontele\t\t9)Exit\n2)Dequeue\t\t4)IsEmpty\t\t6)Clear\t\t8)Display All\nEnter Choice : ";
	cin>>c;
	switch(c)
		{
			case 1:						cout<<"\nEnter Element :";	
										cin>>e;
										Q.enqueue(e);
										break;
										
			case 2:						x=Q.dequeue();
										if(x==-1)
										{
											cout<<"\nQueue Empty (Underflow)";										
										}
										else
										{
											cout<<"Removing "<<x<<"\n";
										}
										break;
										
			case 3:						x=Q.isfull();
										if(x==1)
										{
											cout<<"\nQueue Is Full";
											
										}
										else
										{
											cout<<"Queue is not Full";
										}
										break;
			case 4:						x=Q.isempty();
										if(x==1)
										{
												cout<<"Queue is Empty";
										}				
										else
										{
												cout<<"Queue is not Empty";
										}
										break;
			case 5:						x=Q.Size();
										cout<<"\nSize is :"<<x;
										break;
			case 6:						Q.clear();
										cout<<"\nQueue Cleared";
										break;
			case 7:						x=Q.frontel();
										if(x!=-1)
											cout<<"\nFrontmost Element :"<<x;
										else
											cout<<"\nQueue Empty";
										break;
			case 8:						Q.display();
										break;						
			case 9:						Q.Delete();
										cout<<"\nMemory Released !";
										exit(0);
		
		}
		
	}while(1);
										
		
}
