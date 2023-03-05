//Given a list of N elements, which is sorted in ascending order, you are required to search an element x 
//in the list. The list is stored using array data structure. If the search is successful, the output should be 
//the index at which the element occurs, otherwise returns -1 to indicate that the element is not present 
//in the list. Assume that the elements of the list are all distinct. Write a program to perform the desired 
//task.
#include<iostream>
using namespace std;

class BinarySearch
{
	int n;
	int i;
	int *A;
	public:
		int enter();
		int print();
		int binarySearch(int f);
		int DeleteArray();
};

int BinarySearch::enter()
{
	
	cin>>n;
	
	A= new int[n];
	
	for(i=0;i<n;i++)
	{
		
		cin>>A[i];
				if((i!=0)&& (A[i]==A[i-1]))
				{
					cout<<"\nElement should not be repeated. Enter Again!\n";
					cin>>A[i];
				}
				if((i!=0)&& (A[i]<A[i-1]))
				{
					cout<<"\nElement should be added in Ascending Order. Enter Again!\n";
					cin>>A[i];
				}
	}
}

int BinarySearch::print()
{
	for(i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	}
	
}


int BinarySearch::binarySearch(int f)
{
	int e=-1;
	int low=0;
	int high=n-1;
	int mid;
	
	while(high>=low )
	{
		mid=(low+high)/2;
		if(f==A[mid])
		{
			return mid;
		}
		
		else if(f>A[mid])
		{
			low=mid+1;	
		}
		
		else
		{
			high=mid-1;
		}
	}
	return e;
}

int BinarySearch::DeleteArray() 		//function delete the memory space taken
{
	delete A;
	cout<<"\nMemory Released.";
}


int main()
{
	int f;
	BinarySearch obj;
	cout<<"Enter Number of Elements :";
	obj.enter();
	cout<<"\n\nThe Elements are as follows :";
	obj.print();
	cout<<"\nEnter the element you want to find :";
	cin>>f;
	int x=obj.binarySearch(f);
	if(x>=0)
	cout<<"\nElement found at postition "<<x;
	else
	{
		cout<<"\nElement at postition "<<x;
		cout<<"\nie Element Not Found .";
	}
	obj.DeleteArray();						//separate function called to delete the memory
}

