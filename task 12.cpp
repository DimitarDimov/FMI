#include<iostream>
#include<stack>
#include<cstring>
#include<cmath>

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


double value(char* s)
{
    stack<double> st;
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
            st.push(temp);
            temp = 0;
            continue;
        }

        else if(s[i] =='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^')
        {
            y = st.top();
            st.pop();
            x = st.top();
            st.pop();
            switch(s[i])
            {
                case '+': z = x + y; break;
                case '-': z = x - y; break;
                case '*': z = x * y; break;
                case '/': z = x / y; break;
                case '^': z = pow(x,y);
            }
            st.push(z);
        }
        i++;
    }
    z = st.top();
    st.pop();
    return z;
}
int main() {

	char s[200];
	cin >> s;
	char s1[200];
	translate(s,s1);
	for(int i = 0; i < 20;i++) cout<< s1[i];
	cout<< endl;
	cout << value(s1);
	return 0;
}
