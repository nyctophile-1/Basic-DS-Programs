#include<iostream>
using namespace std;

class diagonalMatrix{
	int n;					//size
	int *A;
	public:
		~diagonalMatrix()
		{
			delete A;
			cout<<"\nMemory Released !";
		}
		int diagonalStart();
		int setDiagonal(int,int,int);
		int getDiagonal(int,int);
		int displayDiagonal();
		};
int diagonalMatrix::diagonalStart(){
	int c,val;
	int i,j;
	cout<<"\nEnter Size of Matrix N :";
	cin>>n;
	A= new int[n]{};
	do{
	cout<<"\n1)Set\n2)Get\n3)Display\n4)Exit\nEnter Choice :";
	cin>>c;
	switch(c)
	{
		case 1:			cout<<"\n\nEnter Row(i) and Column(i) Index :";
						cin>>i>>j;
						cout<<"\nEnter Value to Enter :";
						cin>>val;
						setDiagonal(i,j,val);
						break;
						
		case 2:			cout<<"\n\nEnter Row(i) and Column(i) Index To Retrieve Value:";
						cin>>i>>j;
						val= getDiagonal(i,j);
						if(val!=-1)
						cout<<"\nValue :"<<val;
						break;
						
		case 3:			displayDiagonal();
						break;
						
		case 4:			return 0;
	}
	}
	while(1);
}
int diagonalMatrix::setDiagonal(int i,int j,int val){
	if(i<=0 || j<=0 || i>n || j>n)
		cout<<"\nIndex Out Of Bounds !";	
	else if(i!=j && val!=0)
		cout<<"\nERROR !\nDiagonal Matrices 0 for i!=j";	
	else
		A[i-1]=val;	
}
int diagonalMatrix::getDiagonal(int i,int j){
	if(i<0 || j<0 || i>n || j>n){
		cout<<"\nIndex Out Of Bounds !";
		return -1;
	}
	else if(i!=j)
		return 0;
	else
		return(A[i-1]);
}
int diagonalMatrix::displayDiagonal(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j!=i)
				cout<<"0 ";
			else
				cout<<A[i-1]<<" ";
		}
		cout<<endl;
	}
}

class lowerTriMatrix{
	int n;
	int* A;
	int w;
	public:
		~lowerTriMatrix()
		{
			delete A;
			cout<<"\nMemory Released !";
		}
		int lowerTriStart();
		int setLowerTri(int,int,int);
		int getLowerTri(int,int);
		int displayLowerTri();
};
int lowerTriMatrix::lowerTriStart(){
	int c,val;
	int i,j;
	cout<<"\nEnter Size of Matrix N :";
	cin>>c;
	w=c;
	n=((c+1)*c)/2;
	A= new int[n]{};
	do{
	cout<<"\n1)Set\n2)Get\n3)Display\n4)Exit\nEnter Choice :";
	cin>>c;
	switch(c)
	{
		case 1:			cout<<"\n\nEnter Row(i) and Column(i) Index :";
						cin>>i>>j;
						cout<<"\nEnter Value to Enter :";
						cin>>val;
						setLowerTri(i,j,val);
						break;
		
		case 2:			cout<<"\n\nEnter Row(i) and Column(i) Index To Retrieve Value:";
						cin>>i>>j;
						val= getLowerTri(i,j);
						if(val!=-1)
						cout<<"\nValue :"<<val;
						break;
						
		case 3:			displayLowerTri();
						break;
						
		case 4:			return 0;
	}
	}
	while(1);
}
int lowerTriMatrix::setLowerTri(int i,int j,int val){
	if(i<=0 || j<=0 || i>w || j>w)
		cout<<"\nIndex Out Of Bounds !";
	if(i<j && val!=0)
		cout<<"ERROR ! \nLower Triangular Matrices are 0 for j>i";
	else{
		int r=(i*(i-1))/2;
		int c=j-1;
		A[r+c]=val;
	}
}
int lowerTriMatrix::getLowerTri(int i,int j){
	if(i<0 || j<0 || i>n || j>n){
		cout<<"\nIndex Out Of Bounds !";
		return -1;
	}
	else if(j>i)
		return 0;
	else{
		int r=((i-1)*i)/2;
		int c=j-1;
		return A[r+c];
	}
}
int lowerTriMatrix::displayLowerTri(){
	int k=0;
	for(int i=1;i<=w;i++){
		for(int j=1;j<=w;j++){
			if(j>i)
				cout<<"0 ";
			else
				cout<<A[k++]<<" ";
		}
		cout<<endl;
	}
}

class upperTriMatrix{
	int n;
	int* A;
	int w;
	public:
		~upperTriMatrix()
		{
			delete A;
			cout<<"\nMemory Released !";
		}
		int upperTriStart();
		int setUpperTri(int,int,int);
		int getUpperTri(int,int);
		int displayUpperTri();
};
int upperTriMatrix::upperTriStart(){
	int c,val;
	int i,j;
	cout<<"\nEnter Size of Matrix N :";
	cin>>c;
	w=c;
	n=((c+1)*c)/2;
	A= new int[n]{};
	do{
	cout<<"\n1)Set\n2)Get\n3)Display\n4)Exit\nEnter Choice :";
	cin>>c;
	switch(c)
	{
		case 1:			cout<<"\n\nEnter Row(i) and Column(i) Index :";
						cin>>i>>j;
						cout<<"\nEnter Value to Enter :";
						cin>>val;
						setUpperTri(i,j,val);
						break;
		
		case 2:			cout<<"\n\nEnter Row(i) and Column(i) Index To Retrieve Value:";
						cin>>i>>j;
						val= getUpperTri(i,j);
						if(val!=-1)
						cout<<"\nValue :"<<val;
						break;
						
		case 3:			displayUpperTri();
						break;
						
		case 4:			return 0;
	}
	}
	while(1);
}
int upperTriMatrix::setUpperTri(int i,int j,int val){
	if(i<=0 || j<=0 || i>w || j>w)
		cout<<"\nIndex Out Of Bounds !";
	if(i>j && val!=0)
		cout<<"ERROR ! \nLower Triangular Matrices are 0 for j<i";
	else{
		i--;
		j--;
		int x=(w*i)+j-((i*(i+1)))/2;
		A[x]=val;
	}
}
int upperTriMatrix::getUpperTri(int i,int j){
	if(i<=0 || j<=0 || i>w || j>w)
		cout<<"\nIndex Out Of Bounds !";
	if(i>j)
		return 0;
	else{
		i--;
		j--;
		int x=(w*i)+j-((i*(i+1)))/2;
		return A[x];
	}
}
int upperTriMatrix::displayUpperTri(){
	int k=0;
	for(int i=1;i<=w;i++){
		for(int j=1;j<=w;j++){
			if(j<i)
				cout<<"0 ";
			else
				cout<<A[k++]<<" ";
		}
		cout<<endl;
	}
}

class symmetricMatrix{
	int n;
	int* A;
	int w;
	public:
		~symmetricMatrix()
		{
			delete A;
			cout<<"\nMemory Released !";
		}
		int symmetricStart();
		int setSymmetric(int,int,int);
		int getSymmetric(int,int);
		int displaySymmetric();
};
int symmetricMatrix::symmetricStart(){
	int c,val;
	int i,j;
	cout<<"\nEnter Size of Matrix N :";
	cin>>c;
	w=c;
	n=((c+1)*c)/2;
	A= new int[n]{};
	do{
	cout<<"\n1)Set\n2)Get\n3)Display\n4)Exit\nEnter Choice :";
	cin>>c;
	switch(c)
	{
		case 1:			cout<<"\n\nEnter Row(i) and Column(i) Index :";
						cin>>i>>j;
						cout<<"\nEnter Value to Enter :";
						cin>>val;
						setSymmetric(i,j,val);
						break;
		
		case 2:			cout<<"\n\nEnter Row(i) and Column(i) Index To Retrieve Value:";
						cin>>i>>j;
						val= getSymmetric(i,j);
						if(val!=-1)
						cout<<"\nValue :"<<val;
						break;
						
		case 3:			displaySymmetric();
						break;
						
		case 4:			return 0;
	}
	}
	while(1);
}
int symmetricMatrix::setSymmetric(int i,int j,int val){
	if(i<=0 || j<=0 || i>w || j>w)
		cout<<"\nIndex Out Of Bounds !";
	else{	
			if(i<j)
			{
				int r=j;
				int c=i;
				int x=(r*(r-1))/2;
				int y=c-1;
				A[x+y]=val;
			}
			else
			{
				int x=(i*(i-1))/2;
				int y=j-1;
				A[x + y]=val;
			}
		}
}
int symmetricMatrix::getSymmetric(int i,int j){
	if(i<=0 || j<=0 || i>w || j>w)
		cout<<"\nIndex Out Of Bounds !";
	else
	{
		if(i<j)
		{
			int r=j;
			int c=i;
			int x=(r*(r-1))/2 + c-1;
			return A[x];
		}
		else
		{
			
			int x=(i*(i-1))/2 + j-1;
			return A[x];
		}
	}
}
int symmetricMatrix::displaySymmetric(){
	int k=0;
	int x,r,c;
	for(int i=1;i<=w;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(i<j)
			{
				r=j;
				c=i;
			x=((r*(r-1))/2)+c-1;
			cout<<A[x]<<" ";
			}
			else
			{
				cout<<A[k++]<<" ";
			}
		}
		cout<<endl;
	}
}

int main()
{
	
	int c;
	cout<<"\n1)Diagonal Matrix\n2)Lower Triangular\n3)Upper Triangular\n4)Symmetric Matrix";
	cout<<"\n\nEnter Choice :";
	cin>>c;
	switch(c)
	{
		case 1:					{
									diagonalMatrix obj;
									obj.diagonalStart();
										break;
								}
		case 2:					{	
									lowerTriMatrix obj1;
									obj1.lowerTriStart();
										break;
								}	
		case 3:					{	
									upperTriMatrix obj2;
									obj2.upperTriStart();
										break;
								}
		case 4:					{	
									symmetricMatrix obj3;
									obj3.symmetricStart();
										break;
								}												
	}
}
