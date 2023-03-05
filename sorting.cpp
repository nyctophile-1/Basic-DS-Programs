#include<iostream>
using namespace std;
template <typename E>
class Sorting
{		E size;
		E *array;
	public:
		Sorting(E arr[], int s);
		void input();
		void display();
		void selectionSort();
		void bubbleSort();
		void insertionSort();
};

template <typename E>
Sorting<E>::Sorting(E arr[], int s) 
{
	array= new E[s];
	size= s;
	for(int i=0;i<size;i++)
	array[i]= arr[i];
	
}

template <typename E>
void Sorting<E>::input() 
{
cout<<"\n ENTER THE DATA YOU WANT TO SORT :";
	for(int i = 0; i<size; i++)	
	{
		cin>>array[i];
	}
}
template <typename E>
void Sorting<E>::display() 
{
   for(int i = 0; i<size; i++)
   cout << array[i] << " ";
   cout << endl;
}

template <typename E>
void Sorting<E>::selectionSort() 
{
E temp;
for(int i=0;i<size;i++)
{
  for(int j=i+1;j<size;j++)
  {
   if(array[i]>array[j])
   {
    temp=array[i];
    array[i]=array[j];
    array[j]=temp;
   }
  }
}
}

template <typename E>
void Sorting<E>:: bubbleSort() 
{	
E temp;
for(int i=0;i<size;i++)
{
  for(int j=0;j<size-i-1;j++)
  {
   if(array[j]>array[j+1])
   {
    temp=array[j];
    array[j]=array[j+1];
    array[j+1]=temp;
   }
  }
}
} 

template <typename E>
void Sorting<E>:: insertionSort()
{
E tmp;
int j;
for(int i=1;i<size;i++)
{
  tmp=array[i];
  j=i-1;
  while(tmp<array[j])
  {
   array[j+1]=array[j];
   j--;
  }
  array[j+1]=tmp;
}
}

int main()
{
	int choice, n;
	int*arr=NULL;
	cout<<"\n \t\t\t\t\tSORTING TECHNIQUES\n\n";
	cout<<"\n enter size of the array :  ";
  	cin>>n;
  	arr= new int[n];
	Sorting<int>st(arr,n) ;
    
    do
    {	cout<<"****************************"<<endl;
        cout<<"1 - SELECTION SORTING"<<endl;
        cout<<"2 - BUBBLE SORTING"<<endl;
        cout<<"3 - INSERTION SORTING "<<endl;
        cout<<"4 - Exit"<<endl;
        cout<<"****************************"<<endl;
        cout<<"Enter your choice: "<<endl;
        cin>>choice;
         
        switch(choice)
		{
		    case 1: 
					cout<<"\n==================================================================\n"<<endl;
					st.input();
					cout << "\nArray before Sorting: "<<endl;
   					st.display();
    	    		st.selectionSort();
  					cout << "\nArray after Selection Sorting: "<<endl;
   					st.display();
   					cout<<"\n==================================================================\n"<<endl;

		    break;
                 
            case 2:
                	cout<<"\n==================================================================\n"<<endl;
					st.input();
					cout << "\nArray before Sorting: "<<endl;
   					st.display();
					st.bubbleSort();
   					cout << "\nArray after Bubble Sorting:\n ";
   					st.display();
   					cout<<"\n==================================================================\n"<<endl;

            break;
             
            case 3:
                	cout<<"\n==================================================================\n"<<endl;
					st.input();
					cout << "\nArray before Sorting: "<<endl;
   					st.display();
					st.insertionSort();
  					cout << "\nArray after Insertion Sorting:\n ";
   					st.display();
   					cout<<"\n==================================================================\n"<<endl;
            
            case 4:
				
				break;
            
            default:
                cout<<"An Invalid choice."<<endl;
        }   
    }while(choice!=0);
 
    return 0;
} 

