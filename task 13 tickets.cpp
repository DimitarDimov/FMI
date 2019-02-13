#include<iostream>
#include<cstring>
using namespace std;

class Ticket
{
    char* name_t;
    double price;
public:
    Ticket(char* n="", double p=0)
    {
        name_t = new char[strlen(n) +1];
        if(name_t != NULL)
        {
            strcpy(name_t,n);
        }
        price = p;
    }
    ~Ticket()
    {
        delete [] name_t;
    }
    Ticket(const Ticket &other)
    {
        name_t = new char[strlen(other.name_t)+1];
        if(name_t != NULL)
        {
            strcpy(this->name_t,other.name_t);
        }
        this->price = other.price;
    }
    Ticket& operator=(const Ticket& other)
    {
        if(this != &other)
        {
            delete[] this->name_t;
            this->name_t = new char[strlen(other.name_t)+1];
            if(this->name_t != NULL)
            {
                strcpy(this->name_t,other.name_t);
            }
            this-> price = other.price;
        }
        return *this;
    }
    virtual double getPrice()
    {
        return price;
    }
};

class Ticket_discount : public Ticket
{
    char* identity;
public:
    void discount_set(Ticket_discount c)
    {

    }
    Ticket_discount(char* n_t="", double p=0, char* id="") : Ticket(n_t,p)
    {
        identity = new char[strlen(id)+1];
        if(identity != NULL)
        {
            strcpy(identity,id);
        }
    }
    ~Ticket_discount()
    {
        delete[] identity;
    }
    Ticket_discount(const Ticket_discount& other) : Ticket(other)
    {
            identity = new char[strlen(other.identity)+1];
            if(this->identity != NULL)
            {
                strcpy(this->identity,other.identity);
            }
    }
    Ticket_discount& operator=(const Ticket_discount &other)
    {
        if(this != &other)
        {
            Ticket::operator=(other);
            delete[] identity;
            identity = new char[strlen(other.identity)+1];
            if(this->identity != NULL)
            {
                strcpy(this->identity,other.identity);
            }
        }
        return *this;
    }
    double getPrice()
    {
        return (Ticket::getPrice()) /2;
    }
};
double sum_tickets(Ticket** t,int s)
{
    double sum=0;
    for(int i = 0; i < s; i++)
    {
        sum += t[i]->getPrice();
    }
    return sum;
}
int main()
{
    Ticket a("aa",1.2);
    Ticket_discount b("bb",1.4,"asd");
    Ticket* tick[2];
    tick[0] = &a;
    tick[1] = &b;
    cout << sum_tickets(tick,2);
return 0;
}
