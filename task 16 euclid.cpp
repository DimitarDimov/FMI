#include<iostream>
using namespace std;

#include<iostream>
using namespace std;

int euclid_I(int num1, int num2)
{
    while (num1!=num2)
    {
        if (num1>num2) num1-=num2;
        else num2-=num1;
    }
    return num1;
}
int euclid_II (int num1, int num2)
{
 if (num1 != num2)
 {
  if( num1 > num2)
  {
   return euclid_II(num1-num2, num2);
  }
  else
  {
   return euclid_II(num2, num2-num1);
  }
 }
 else
  return num1;
}

int main()

{
    int num1,num2;
    cin>>num1;
    cin>>num2;
    cout<<euclid_I(num1, num2)<<endl;
    cout<<euclid_II(num1, num2)<<endl;
    return 0;
}

