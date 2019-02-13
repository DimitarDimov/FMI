#include<iostream>
using namespace std;

void Sorted(int &a, int &b, int &c)
{
	if(a < b)
	{
		swap(a,b);
	}
	if(a < c)
	{
		swap(a,c);
	}
	if(b < c)
	{
		swap(b,c);
	}
}
void maximum(int &a, int &b, int &c, int max_A, int max_B, int max_C)
{
	if(a > b && a > c)
	{
		a = max_A;
		b = 0;
		c = 0;
	}
	if(b > c && b > a)
	{
	    a = 0;
		b = max_B;
		c = 0;
	}
	if(c > b && c > a)
	{
		a = 0;
        b = 0;
        c = max_C;
	}
}

void Poason(int a,int b,int c,int d,int max_A,int max_B,int max_C)
{
	cout << a << ' '<< b << ' ' << c << endl;
	if(a == d || b == d || c == d)
	{
		return;
	}

	if(b == 0 )
	{
		 Poason(a-max_B,max_B,c,d,max_A,max_B,max_C);
	}
	else if(c != max_C)
	{
		if(b+c >= max_C)
		{
			 Poason(a,(b + c)-max_C,max_C,d,max_A,max_B,max_C);
		}
		else
		{
		      Poason(a,0,b+c,d,max_A,max_B,max_C);
		}
	}
	else if(a != max_A)
	{
		if (a + c <= max_A)
		{
			 Poason(a+c,b,0,d,max_A,max_B,max_C);
		}
		else
		{
			 Poason(max_A,b,max_A-(a+c),d,max_A,max_B,max_C);
		}
	}
	else
		return;
}




int main()
{
	int a,b,c,d,max_A, max_B, max_C;
	cin >> max_A >> max_B >> max_C;
	cin >> d;
	a = max_A;
	b = max_B;
	c = max_C;

	Sorted(a,b,c);
	Sorted(max_A,max_B,max_C);
    maximum(a,b,c,max_A,max_B,max_C);
    Poason(a,b,c,d,max_A,max_B,max_C);
    return 0;
}
