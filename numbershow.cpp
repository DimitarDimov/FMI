#include<iostream>
#include<cmath>
using namespace std;
int main ()
{
    int num,a,b,c;
    cin>>num;
    c=num%10;
    b=(num/10)%10;
    a=num/100;
    if((num/10)==1) { cout<<"TEN";}
    if(a==0) {cout << "  ";}
    if(a==1) {cout << "ONE HUNDRED"<< " ";}
    if(a==2) {cout << "TWO HUNDRED"<< " ";}
    if(a==3) {cout << "THREE HUNDRED"<< " ";}
    if(a==4) {cout << "FOUR HUNDRED"<< " ";}
    if(a==5) {cout << "FIVE HUNDRED"<<" ";}
    if(a==6) {cout << "SIX HUNDRED"<<" ";}
    if(a==7) {cout << "SEVEN HUNDRED"<<" ";}
    if(a==8) {cout << "EIGHT HUNDRED"<<" ";}
    if(a==9) {cout << "NINE HUNDRED"<<" ";}
    if(b==0) {cout << "  ";}
    if(b==1)
    {
    if(c==0 && b==1 && a>=1 ) {cout <<" "<<"AND TEN";}
    if(c==1) {cout << " "<<"AND ELEVEN";}
    if(c==2) {cout << " "<<"AND TWELVE";}
    if(c==3) {cout << " "<<"AND THIRTEEN";}
    if(c==4) {cout << " "<<"AND FOURTEEN";}
    if(c==5) {cout << " "<<"AND FIFTEEN";}
    if(c==6) {cout << " "<<"AND SIXTEEN";}
    if(c==7) {cout << " "<<"AND SEVENTEEN";}
    if(c==8) {cout << " "<<"AND EIGHTEEN";}
    if(c==9) {cout << " "<<"AND NINTEEN";}
    }
    if(b==2) {cout << "TWENTY"<<" ";}
    if(b==3) {cout << "THIRTY"<<" ";}
    if(b==4) {cout << "FOURTY"<<" ";}
    if(b==5) {cout << "FIFTY"<<" ";}
    if(b==6) {cout << "SIXTY"<<" ";}
    if(b==7) {cout << "SEVENTY"<<" ";}
    if(b==8) {cout << "EIGHTY"<<" ";}
    if(b==9) {cout << "NINTY"<<" ";}
    if(c==0 && b==0 && a==0) {cout << "ZERO"<<" ";}
    if(c==1 && b!=1) {cout << "ONE"<<" ";}
    if(c==2 && b!=1) {cout << "TWO"<<" ";}
    if(c==3 && b!=1) {cout << "THREE"<<" ";}
    if(c==4 && b!=1) {cout << "FOUR"<<" ";}
    if(c==5 && b!=1) {cout << "FIVE"<<" ";}
    if(c==6 && b!=1) {cout << "SIX"<<" ";}
    if(c==7 && b!=1) {cout << "SEVEN"<<" ";}
    if(c==8 && b!=1) {cout << "EIGHT"<<" ";}
    if(c==9 && b!=1) {cout << "NINE"<<" ";}


    cout << endl;
    return 0;
}
