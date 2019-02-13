#include<iostream>
#include<cmath>
using namespace std;

class Figure
{
protected:
    double a;
    double b;
    double c;
public:

    Figure(): a(0),b(0),c(0)
    {

    }
    virtual double area(){return 0;};

};
class Triangle : public Figure
{
public:
Triangle (double _a, double _b, double _c)
 {
  a = _a;
  b = _b;
  c = _c;
 }
 double area()
 {
  double p = (a+b+c)/2;
  return  sqrt (p*(p-a)*(p-b)*(p-c));
 }
};
class Rectangle : public Figure
{
public:
 Rectangle(double width, double height)
 {
  a = width;
  b = height;
 }
 double area()
 {
  return  a * b;
 }
};


class Circle : public Figure{

public:
 Circle(double radius)
 {
        a = radius;
 }
 double area ()
 {
  return (3.14)*a*a;
 }
};
int main()
{
    Rectangle r1 (2,3);
    Circle c1(4);
    Triangle t1 (3,4,5);
    Rectangle r2 (3,4);
    Circle c2(5);
    Triangle t2 (7,8,9);
    Rectangle r3 (4,5);
    Circle c3 (6);
    Triangle t3 (8,9,10);
    Rectangle r4 (24,8);

    Figure* figures[10];
    figures[0] = &r1;
    figures[1] = &c1;
    figures[2] = &t1;
    figures[3] = &r2;
    figures[4] = &c2;
    figures[5] = &t2;
    figures[6] = &r3;
    figures[7] = &c3;
    figures[8] = &t3;
    figures[9] = &r4;

    for(int i = 0; i < 10; i++)
    {
        cout << figures[i] -> area() << endl;
    }

return 0;
}
