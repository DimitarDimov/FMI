#include<iostream>
#include<cstring>
using namespace std;
void change(char* s,char* s1,int lenght)
{
    // word swap
    int j=0;
    for(int i=lenght-1;i>=0;i--)
    {
        s1[j] = s[i];
        j++;
    }
    s1[j]='\0';
    return;
}


int main()
{
    //char s[100],s1[100],s2[]="Hello!",s3[]="Hi",s4[]="Hello!";


    //cin>>s;
    //change(s,s1,strlen(s));
    //cout<<s1<<endl;
    //strcat(s,s1);
    //cout<<s;
    //cin.getline(s2,15);
    //cout<<"broqt na bukvite e: "<< count_letter<< endl;
    //change(s,strlen(s));
    /*int lenght=strlen(s);
    int j=0;
    for(int i=lenght;i>=0;i--)
    {
        s1[j] = s[i];
    }
    s1[j]='\0';
    cout<< s1;*/
     char s[]= "vsichki srichki na edna duma";
     int counter=0;
     for(int i =0; i < strlen(s);i++)
     {
         if(s[i]!=' ' && s[i+1]!=' ')
         {
             counter++;
             i++;
             cout<< counter <<' ';
         }
     }
    return 0;
}
