#include<iostream>
using namespace std;

template <class X>
class Sort
{
	private:
		int size;
		X *array;
	public:
		Sort()
		{
			size=0;
			array=NULL;
		}	 
		void Input(int);
		void Display();
		
		void BubbleSort();
		void InsertionSort();
		void SelectionSort();
		~Sort()
		{
			cout<<"\nDeleting Heap ";
			delete array;
		}
};

template <typename X>
void Sort<X>::Input(int s)
{
	size=s;
	array= new X[size];
	for(int i=0;i<size;i++)
	{
		cin>>array[i];
	}
}

template <typename X>
void Sort<X>::Display()
{
//	cout<<"\nThe Array is :";
	for(int i=0;i<size;i++)
	{
		cout<<array[i]<<"\t";
	}
}

template <typename X>
void Sort<X>::BubbleSort()
{
	int i,j;
	for(i=0;i<size-1;i++) 
	{
		for(j=0;j<size-i-1;j++) 
		{
			if(array[j]>array[j+1]) 
			{
				X temp=array[j+1];
				array[j+1]=array[j];
				array[j]=temp;
			}
		}
		cout<<"\nPass "<<i+1<<" :";
		Display();
	}
	
}
template <typename X>
void Sort<X>::InsertionSort()
{
    int i,j;
	X temp;  int count=0;
    for (i =1;i<size;i++) 
    {  
        temp=array[i];  
        j=i-1;  
        while(j>=0&&array[j]>temp) 
        {
            array[j+1]=array[j];  
            j=j-1;
            count++;
            cout<<"\nC :"<<count<<" :";
			Display();  
        }  
        array[j+1]=temp; 
		count++;
        cout<<"\nC :"<<count<<" :";
		Display();   
    }
}

template <typename X>
void Sort<X>::SelectionSort()
{
	int i,j,min;
	X temp;
	for (i=0;i<size-1;i++)
	{
		min=i;
		for(j=i+1;j<size;j++)
		{
			if (array[j]<array[min])
			{
				min=j;
			}
		}
		temp=array[i];
		array[i]=array[min];
		array[min]=temp;
		cout<<"\nPass "<<i+1<<" :";
		Display();
	}

}
int main()
{
	int size,choice1,choice2=0;
	do
	{
		
	Sort<int> obj;
	
	cout<<"\nEnter the Size of Array :";
	cin>>size;
	
	cout<<"\nEnter Elements :";
	obj.Input(size);
	
	cout<<"\n1)Bubble-Sort\n2)Insertion-Sort\n3)Selection-Sort\nEnter Choice :";
	cin>>choice1;
	
	switch(choice1)
	{
		case 1:				obj.BubbleSort();
							break;
							
		case 2:				obj.InsertionSort();
							break;
							
		case 3:				obj.SelectionSort();
							break;	
	}
	cout<<"\n\nDo You Want To Continue ?1/0 :";
	cin>>choice2;
	}while(choice2==1);
	return 0;
}

