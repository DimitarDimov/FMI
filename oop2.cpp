//4. зад.  (6 т.) Намерете резултата от изпълнението на програмата. За всеки обект, дефиниран в main, да се напишат стойностите на член-данните му.

#include <iostream>
using namespace std;

class A
{ public:
      A(int = 5, int = 2);
      ~A(){cout << "~A()\n";}
      void print()const;
      int f()const;
      int g()const;
  private:
      int x, y;
};
A::A(int a, int b)
{ x = a+1; y = b+2;
   cout << "A(" << x << ", " << y << ")\n";
}
void A::print()const
{ cout << x << " " << y << endl;
}
int A::f()const
{ return x+5;
}
int A::g()const
{ return y+5;
}

	class B
{ public:
      B(double, A);
      ~B()
      {cout << "~B()\n";
      }
      void print()const;
      double h()const;
      A p()const;
  private:
     A a;
     double b;
};
B::B(double d, A e)
{ b = d+5; a = e;
  cout << "B(" << d << ")\n";
}
void B::print() const
{ a.print();
   cout << b << endl;
}
double B::h() const
{ cout << a.f() << " " << a.g() << endl;
   return b;
}
A B::p() const
{ return a;
}
int main()
{  A a(3, 5), b(5), c;
    b.print();
    B d(1.5, a), e(4.5,c);
    d.print(); e.print();
    return 0;
}
