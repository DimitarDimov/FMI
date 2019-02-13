#include <iostream>
using namespace std;
class base
{ protected:
       virtual void f3() const
       { cout << "base::f3() \n";
       }
  public:
     base()
     { cout << "base()\n";
        f1();
        f2();
        f3();
       }
       ~base()
       { cout << "~base()\n";
          f1();
          f2();
          f3();
        }
        void f()const
        { cout << "f()\n";
           f1();
           f2();
           f3();
        }
        virtual void f1()const
        { cout << "base::f1()\n";
        }
    private:
        virtual void f2()const
        {
            cout << "base::f2()\n";
        }
};
class der1 : public base
{ protected:
        void f1()const
        { cout << "der1::f1()\n";
        }
   public:
        void f2()const
        { cout << "der1::f2()\n";
        }
   private:
        void f3()const
        { cout << "der1::f3()\n";
        }
 };
class der2 : public der1
{ protected:
       void f1()const
       { cout << "der2::f1()\n";
       }



	   public:
       void f2()const
       { cout << "der2::f2()\n";
       }
   private:
       void f3()const
       { cout << "der2::f3()\n";
       }
};
int main()
{ base b;
   der1 d1;
   der2 d2;
   base *p = &d1;
   der1 *q = &d2;
   b.f1();
   p->f1();
   //p->f2(); private
   //p->f3(); protected
   //q->base(); konstruktor
   //q->f1(); protected
   q->f2();
   //q->f3(); private
   p = &d2;
   p->f1();
   //p->f2(); privated
   //p->f3(); protected
   der1 *r = new der2;
   //r->f1(); protected
   r->f2();
   //r->f3(); private$
   p->f();
   q->f();
   r->f();
   delete r;
   return 0;
}

