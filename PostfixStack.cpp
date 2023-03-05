/*
		This prgram is written using Standard Template Library
		Akshita Gupta
		0854
*/
#include<iostream>
#include<stack>			//for stack class
#include<string>		//for string functions
#include<ctype.h>		//isspace isdigit
#include<math.h>		//power function
#include <bits/stdc++.h> 	//stack
using namespace std;

int main()
{
	stack <int> s; 
	string str;
	cout<<"Enter the expression :";
	getline(cin,str);
	int x=0;
	
	
	
	
	for(int i=0;i<str.length();i++)
	{
		if(isdigit(str[i]))
		{
			x=(x*10)+ int(str[i])-48;		//48 has been subtracted 'cause int[str[i]]takes ascii value, hence we subtract ascii of 0
					
		}
		else if(isspace(str[i]))
		{		
			if(isdigit(str[i-1]))
			{
				s.push(x);
				x=0;			
			}
		}
		else
		{		
				int varA=s.top();
					s.pop();				//pop function here does not return any value
					int varB=s.top();
					s.pop();
					char c=str[i];
				switch(c)
					{
						case '+':	s.push(varA+varB);
								break;	
						case '-':	s.push(varB-varA);
								break;	
						case '*':	s.push(varA*varB);
								break;	
						case '/':	s.push(varB/varA);
								break;		
						case '^':	s.push(pow(varB,varA));
								break;	
					}	
		}					
	}
cout<<endl<<"Result :"<<s.top();
}

	
