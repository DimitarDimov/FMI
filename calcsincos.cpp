#include<iostream>
#include<stack>
#include<cstring>
#include<cmath>
#include<vector>

using namespace std;

int t(char c)
{
    int p;
    switch(c)
    {
    case '+':
    case '-':
        p = 2;
        break;
    case '*':
    case '/':
        p = 1;
        break;
    case '^':
        p = 0;
        break;
    default:
         p = -1;
    }
    return p;
}
void translate(char* s, char* ns)
{
    stack<char> st;
    st.push('(');
    char x;
    int i = 0, j = -1, n = strlen(s),multiplier =1;
    while(i < n)
    {
        if(s[i] >='0' && s[i] <='9')
        {
            j++;
            ns[j] = s[i];
            if(s[i+1]>='0' && s[i+1]<='9') {}
            else if(s[i+1] !='.')
            {
                j++;
                ns[j] =',';
            }
        }
        else if(s[i]=='.')
        {
            j++;
            ns[j] = s[i];
        }
        else if(s[i] == '(')
                    st.push(s[i]);
        else if(s[i] == ')')
        {
            x = st.top();
            st.pop();
            while(x != '(')
            {
                j++;
                ns[j] = x;
                x = st.top();
                st.pop();
            }
        }
        else if(s[i] =='s')
        {
            if(s[i+1] =='i')
            {
                st.push('s');
                i+=2;
            }
            else
            {
                st.push('q');
                i+=3;
            }
        }
        else if(s[i] =='c' && s[i+1]=='o' && s[i+2]=='s')
        {
            st.push(s[i]);
            i+=2;
        }
        else if(s[i]=='e' && s[i+1]=='x')
        {
            st.push(s[i]);
            i+=2;
        }
        else if(s[i]=='l' && s[i+1]=='o')
        {
            st.push(s[i]);
            i+=2;
        }
        else if(s[i] =='+' || s[i] =='-' || s[i]=='*' || s[i]=='/' || s[i]=='^')
        {
            x = st.top();
            st.pop();
            while(x != '(' && t(x) <= t(s[i]))
            {
                j++;
                ns[j] = x;
                x = st.top();
                st.pop();
            }
            st.push(x);
            st.push(s[i]);
        }

            i++;
    }
        x = st.top();
        st.pop();
        while(x != '(')
        {
            j++;
            ns[j] = x;
            x = st.top();
            st.pop();
        }
        j++;
        ns[j] = '\0';

    }

stack<double> values;

double value(char* s)
{

    double x,y,z;
    double temp =0;
    int multiplier =0;
    bool flag = false;
    unsigned int i = 0, n = strlen(s);
    while(i < n)
    {

        if(s[i] >='0' && s[i]<='9')
        {
            while(s[i]!=',')
            {
                if(s[i]=='.')
                {
                    flag = true;
                    multiplier++;
                    i++;
                }
                if(flag == false)
                {
                    temp = temp*(pow(10.0,bool(multiplier)))+((double)s[i]-(double)'0');
                }
                else
                {
                    temp += ((double)s[i] - (double)'0') / (pow(10.0,multiplier));
                }
                if(s[i+1]>='0' && s[i+1]<='9') multiplier++;
                else multiplier=0;

                i++;
            }
            flag = false;
            values.push(temp);
            temp = 0;
            continue;
        }

        else if(s[i] =='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^')
        {
            y = values.top();
            values.pop();
            x = values.top();
            values.pop();
            switch(s[i])
            {
                case '+': z = x + y; break;
                case '-': z = x - y; break;
                case '*': z = x * y; break;
                case '/': z = x / y; break;
                case '^': z = pow(x,y);
            }
            values.push(z);
        }
        else if(s[i]=='s' || s[i]=='c' || s[i]=='q' ||s[i]=='e' || s[i]=='l')
        {
            x = values.top();
            values.pop();
            switch(s[i])
            {
                case 's': z = sin(x); break;
                case 'c': z = cos(x); break;
                case 'q': z = sqrt(x); break;
                case 'e': z = exp(x); break;
                case 'l': z = log(x); break;
            }
            values.push(z);
        }
        i++;
    }
    z = values.top();
    values.pop();
    return z;
}
bool quit(string s)
{
    if(s.compare("quit")) return false;
    else return true;
}
int main()
{
    //char s3[20];
    //translate("sin6",s3); cout << value(s3);
    double temp= 0.0;
    string tries;
    char s1[200];
    char s2[200];
        while(1)
        {
            cout<<"input: ";
            getline(cin, tries);
            int i;
                for(i = 0; i < tries.length();i++)
                {
                    s1[i] = tries[i];
                }
                s1[i]='\0';



            if(quit(tries)) break;
            else if(!tries.compare("pop")) values.pop();
            else if(!tries.compare("clear"))
            {
                while(!values.empty())
                values.pop();
            }
            else if(tries[0]=='=') {cout << temp<<endl;}
            else if(!tries.compare("show"))
            {
                while(!values.empty())
                {
                    cout << values.top();

                }
            }
            else if(!tries.compare("help"))
            {
                cout<<"Calculator help:"<< endl;
                cout<<"operations: + - * / ^ "<<endl;
                cout<<"sin cos log exp sqrt "<<endl;
                cout<<"commands: pop, clear,"<<endl;
                cout<<" = , show, help, quit"<<endl;
            }
            else
            {

                translate(s1,s2);
                temp = value(s2);
            }

        }
	return 0;
}
