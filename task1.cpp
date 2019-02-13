#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

void print_binary(int number)
{
    cout << "number: " << number << endl;
    stack<int> binary_number;
    while(number > 0)
    {
      binary_number.push(number % 2);
      number/=2;
    }
    cout << "binary_number: ";
    while( !binary_number.empty())
    {
        cout << binary_number.top();
        binary_number.pop();
    }
    cout << endl;
}

int main()
{
    print_binary(233);
    print_binary(32);
    print_binary(34);
    print_binary(128);
    print_binary(1024);
    return 0;

}
