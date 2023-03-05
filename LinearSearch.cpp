//Given a list of N elements, which follows no particular arrangement, you are required to search an
//element x in the list. The list is stored using array data structure. If the search is successful, the output
//should be the index at which the element occurs, otherwise returns -1 to indicate that the element is
//not present in the list. Assume that the elements of the list are all distinct. Write a program to perform
//the desired task. 


#include<iostream>
using namespace std;

class LinearSearch
{
	int n;
	int i;
	int *A;
	public:
		int enter();
		int print();
		int linearSearch(int f);
		int DeleteArray();
};

int LinearSearch::enter()
{
	
	cin>>n;
	
	A= new int[n];
	
	for(i=0;i<n;i++)
	{
		
		cin>>A[i];
		for(int x=i-1;x>=0;x--)
		{
				if(A[i]==A[x])
				{
					cout<<"\nELement "<<A[i]<<" already Exists!\nEnter Again an Element which does not repeat :";	
					cin>>A[i];		
				}
		}
	}
}

int LinearSearch::print()
{
	for(i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
	
}

int LinearSearch::linearSearch(int f)
{
	int e=-1;
	for(i=0;i<n;i++)
	{
		if(A[i]==f)
			{
				e=i;				
				break;
			}
	}
	return e;

}

int LinearSearch::DeleteArray() 		//function delete the memory space taken
{
	delete A;
	cout<<"\nMemory Released.";
}

int main()
{
	int f;
	LinearSearch obj;
	cout<<"Enter Number of Elements :";
	obj.enter();
	cout<<"\n\nThe Elements are as follows :";
	obj.print();
	cout<<"\nEnter the element you want to find :";
	cin>>f;
	int x=obj.linearSearch(f);
	if(x>=0)
	cout<<"\nElement found at postition "<<x;
	else
	{
		cout<<"\nElement at postition "<<x;
		cout<<"\nie Element Not Found .";
	}
	obj.DeleteArray();						//separate function called to delete the memory
}
