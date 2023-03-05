#include<iostream>
using namespace std;

class node
{
	int value;
	node* next;
	public:

	node(int x,node *temp)
	{
		value=x;
		next=temp;
	}
	friend class SLL;
};


class SLL
{
	node* head;
	public:
	
		SLL()
		{
			head=NULL;
		}
		void addAThead  (int x);
		void addATpos   (int x,int pos);
		void addATend   (int x);
		void display    ();
		int  removehead ();
		int  removepos  (int);
		int removeend	();
		node*  search      (int x);
		int Concatenate (SLL);
		void Delete();
		~SLL()
		{
			void Delete();
			cout<<"Memory Deleted !";
		}
};

void SLL::addAThead(int x)
{
	if(head==NULL)
	{
		node *temp=new node(x,NULL);
		head=temp;
	}
	else
	{

		node *temp=new node(x,head);
		head=temp;
	}
}
void SLL::addATend(int x)
{
	if(head)
	{
		node *temp=head;
		for(;temp->next!=NULL;temp=temp->next);
		node *n=new node(x,temp->next);
		temp->next=n;
	}
	else
	{
		addAThead(x);
	}
}
void SLL::addATpos(int x,int pos)
{
    if(head)
    {
        node* temp=head;
        int c=1;
        for(;temp->next!=NULL && c<pos-1;temp=temp->next,c++);
        node* n=new node(x,temp->next);
        temp->next=n;
    }
    else
    {
        addAThead(x);
    }
}
int SLL::removehead()
{
    if(head)
    {
        node* temp=head;
        int x=temp->value;
        head=head->next;
        delete temp;
        return x;
    }
    else
    {
        cout<<"\nUnderflow !";
        return 0;
    }
}
int SLL::removeend()
{
    if(head==NULL)
    {
         cout<<"\nUnderflow !";
         return 0;
    }
    else if(head->next==NULL)
    {
    	int x=head->value;
        delete head;
        head=NULL;
        cout<<"\nList is Now Empty";
        return x;
    }
    else
    {
        node*temp=head;
        for(;temp->next->next!=NULL;temp=temp->next);
        int x=temp->next->value;
        delete (temp->next);
        temp->next=NULL;
        return x;
    }
}
int SLL::removepos(int pos)
{
    if(head)
    {
        node*temp=head;
        int c=1;
        for(;temp->next!=NULL && c<pos-1;temp=temp->next,c++);
        if(temp->next!=NULL)
        {
        	
		
        	node *N2= new node(temp->next->next->value,temp->next->next->next);
        	int x=temp->next->value;
        	delete(temp->next);
        	temp->next=N2;
        	return x;
    	}
    	else
    	cout<<"\nInvalid Position Mentioned !";
    	return -1;
    }
    else
    {
        cout<<"\nEmpty List !";
        return 0;
    }

}
node* SLL::search(int x)
{
	if(head)
	{

		node*temp=head;
		for(;temp!=NULL;temp=temp->next)
		{
			if((temp->value)==x)
			{
				return temp;
			}
		}
		return NULL;
	}
	else
	{
		return NULL;
	}
}
int SLL::Concatenate(SLL objx)
{
	while(objx.head)
	{
		addATend(objx.removehead());
	}
	display();
	return 0;
}
void SLL::display()
{
	if(head)
	{
	node *temp=head;
	cout<<endl;
	for(;temp!=0;temp=temp->next)
	{
		cout<<temp->value<<" ";
	}
	}
	else
	{
		cout<<"\nList Empty !";
	}
}
void SLL::Delete()
{
	node* temp=head;
	node* next;
	while(temp!=NULL)
	{
		next=temp->next;
		delete(temp);
		temp=next;
	}
}
int main()
{
	SLL obj;
	int c=1,x;
	while(c==1)
	{
		cout<<"\n1)Enter Head \t4)Remove Head \t7)Search \n2)Enter Tail \t5)Remove Tail \t8)Concatenate \n3)Enter Pos \t6)Remove Pos \t9)Exit";
		cout<<"\nEnter Choice :";
		cin>>c;
		switch(c)
		{
				case 1:				cout<<"\nEnter Value :";
								cin>>c;
								obj.addAThead(c);
								obj.display();
								break;
			case 2:				cout<<"\nEnter Value :";
								cin>>c;
								obj.addATend(c);
								obj.display();
								break;
			case 3:				cout<<"\nEnter Value and Position :";
								cin>>c>>x;
								obj.addATpos(c,x);
								obj.display();
								break;

			case 5:				x=obj.removeend();
								if(x!=0)
								{
									cout<<endl<<x<<" Removed.";
								}
								obj.display();
								break;

			case 4:				x=obj.removehead();
								if(x!=0)
								{
									cout<<endl<<x<<" Removed.";
								}
								obj.display();
								break;

			case 6:				cout<<"\nEnter Position :";
								cin>>x;
								int y=obj.removepos(x);
								if(y!=(-1) || y!=0)
								{
									cout<<endl<<x<<" Removed";
								}
								obj.display();
								break;
			case 7:				{
									obj.display();
									node* f;
						   			cout<<"Enter Element to Search :";
									cin>>x;
									f=obj.search(x);
									if(f!=NULL)
									{
										cout<<"\nFound ! Address :"<<f;

									}
									else
									{
										cout<<"\nNot Found !";
										//delete n;
									}
									break;
								}
			case 8:				{
									SLL obj2;int s;
									cout<<"\nEnter Size :";
									cin>>s;
									cout<<"\nEnter ELements for a new Linked List :";
									for(int i=0;i<s;i++)
									{
										cin>>x;
										obj2.addATend(x);
									}
									obj2.display();
									cout<<"\n\n1)Concatenate LL1 to LL2\n2)Concatenate LL2 to LL1 :";
									cin>>c;
									if(c==1)
									{
										obj2.Concatenate(obj);
									}
									else
									{
										obj.Concatenate(obj2);
									}
									break;
								}

			case 9:			exit(0);

		}
		cout<<"\nContinue ? 1/0 :";
		cin>>c;

	}
	return 0;
}
