#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	char input;
	cin>>input;
	cout<<input<<endl;
	switch(input)
	{
		case 48:
		case 49:
		case 50:
		case 51:
		case 52:
		case 53:
		case 54:
		case 55:
		case 56:
		case 57:
			cout<<"valid input"<<endl;
		break;

		default : 
			cout<<"Invalid input"<<endl;
	}
	return 0;
}
