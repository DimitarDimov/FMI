#include<iostream>
using namespace std;


void print(int n)
{
	if(n>9)
	{
		cout << n%10 <<' ';
		print(n/10);
		cout << n%10 <<' ';
	}
	else
	    cout << n <<' ';
}



int main()
{
	int n;
	cin >> n;
	print(n);
	cout << endl;
	return 0;
}
