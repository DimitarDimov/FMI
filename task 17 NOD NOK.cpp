#include<iostream>
using namespace std;

int NOD(int num1, int num2)
{
	if (num2 == 0)
		return num1;
	else
		return NOD(num2,num1 % num2);
}

int NOK(int num1,int num2)
{
	return (num1*num2) / NOD(num1,num2);
}

int NOK_n(int* array, int s)
{
	if (s == 2)
	{
		return NOK(array[0],array[1]);
	}

	int save;
	save = NOK(array[0], array[1]);
	for(int i = 2; i < s; ++i)
	{
				  save *= array[i] / (NOD(save, array[i]));
	}
	return save;
}

int main()
{
	int array[100] = {0};
	int s = 0;
	cout << "Numbers: ";
	cin >> s;

	for (int i = 0; i < s; i++)
	{
		cin >> array[i];
	}

	cout<<"NOK: "<< NOK_n(array,s) << endl;


	return 0;
}
