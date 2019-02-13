#include<iostream>
#include<cstring>
using namespace std;

class Vehicle
{
public:

    Vehicle(char* ="", char* ="", float =0.0, float =0.0);
    virtual ~Vehicle();
    Vehicle(const Vehicle& other);
    Vehicle &operator=(const Vehicle& other);

    bool  canPassUnderBridge(float) const;
    bool  canPassOverBridge(float) const;

    void print()const
    {
        cout <<"Name: "<< name <<endl;
        cout <<"Model: "<< model<<endl;
        cout <<"Height: "<< height<<endl;
        cout <<"Weight: "<< weight<<endl;
        help();
    }
protected:
    virtual void help() const
    {};


private:
    char* name;
    char* model;
    float height;
    float weight;
};

Vehicle :: Vehicle(char* n, char* m, float h, float w)
{
   this-> name = new char[strlen(n)+1];
    strcpy(name, n);
    model = new char[strlen(m)+1];
    strcpy(model, m);
    height = 0.0;
    weight = 0.0;
}
Vehicle :: ~Vehicle()
{
    delete [] name;
    delete [] model;
}
Vehicle :: Vehicle(const Vehicle &other)
{

        this -> name = new char[strlen(other.name)+1];
        strcpy(this-> name, other.name);
        this -> model = new char[strlen(other.model)+1];
        strcpy(this->model, other.model);
        this->height = other.height;
        this->weight = other.weight;

}
Vehicle& Vehicle :: operator=(const Vehicle& other)
{
    if(this != &other)
    {
        delete name;
        delete model;
        this -> name = new char[strlen(other.name)+1];
        strcpy(this-> name, other.name);
        this -> model = new char[strlen(other.model)+1];
        strcpy(this->model, other.model);
        this->height = other.height;
        this->weight = other.weight;
    }
    return *this;
}
bool Vehicle :: canPassUnderBridge(float border) const
{
    if(this-> height < border)
    {
        return true;
    }
    else return false;
}
bool Vehicle :: canPassOverBridge(float maxi) const
{
    if(this -> weight < maxi)
    {
        return true;
    }
    else return false;
}

class LandVehicle : virtual public Vehicle
{
public:
    LandVehicle(char* name="",char* model="", float height=0.0, float weight=0.0, float maxS=0.0, float maxH=0.0) : Vehicle(name, model, height, weight)
    {
        maxSpeed = maxS;
        maxHp = maxH;
    }
    float getTime(float km) const
    {
        return (km / (this -> maxSpeed));
    }
protected:
    virtual void help()const
    {
        cout<<"MaxSpeed: "<< maxSpeed<<endl;
        cout<<"MaxHP: "<<maxHp<<endl;
    }

private:
    float maxSpeed;
    float maxHp;

};

class WaterVehicle : virtual public Vehicle
{
public:
    WaterVehicle(char* name="",char* model="", float height=0.0, float weight=0.0, float watr=0.0, float maxSV=0.0) : Vehicle(name, model, height, weight)
    {
        waterr = watr;
        maxSpeedV = maxSV;
    }
    float getSpeedUpStream(float speedStream) const
    {
        return ((this->maxSpeedV) - speedStream);
    }
    float getSpeedDownStream(float s) const
    {
        return ((this->maxSpeedV) + s);
    }
    float getTimeUpStream(float mil, float tech) const
    {
        return mil / (getSpeedUpStream(tech)) ;
    }
    float getTimeDownStream(float mil, float tech) const
    {
        return mil / (getSpeedDownStream(tech));
    }
protected:
virtual void help()const
    {
        cout<<"Waterr: "<< waterr<<endl;
        cout<<"MaxHP: "<< maxSpeedV <<endl;
    }
private:
    float waterr;
    float maxSpeedV;
};
class AmphibiousVehicle : public LandVehicle, public WaterVehicle
{
public:
    AmphibiousVehicle(char* name="",char* model="", float height=0.0, float weight=0.0, float maxS=0.0, float maxH=0.0, float watr=0.0, float maxSV=0.0) : Vehicle(name, model, height, weight),
    LandVehicle(name, model, height, weight, maxS, maxH),
    WaterVehicle(name, model, height, weight, watr, maxSV)
    {};
    bool solve()
    {
        if(canPassUnderBridge(5))
        {
           if(getTime(5) + getTimeUpStream(5,10) < 1)
           {return true;}
          else return false;
        }
        return false;
    }
protected:
    virtual void help()const
    {
        LandVehicle::help();
        WaterVehicle::help();
    }

};

int main()
{
    Vehicle a("Aaa","ass",1.1,1.2);
    LandVehicle b("Bss","css",1.2,1.3,180,100);
    WaterVehicle c("Css","css",1.3,1.4,400,110);
    a.print();
    cout<<endl;
    b.print();
    cout<<endl;
    c.print();
    return 0;
}
