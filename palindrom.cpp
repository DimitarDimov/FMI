#include<iostream>
#include <string>
using namespace std;
string w,tmp,rtmp;
int main()
{
	int n,i,sz,j;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>w;
		sz=w.size();
		tmp=rtmp="";// string null
		for(j=0;j<sz;j++) if(w[j]!='a'&&w[j]!='o'&&w[j]!='e'&&w[j]!='i')
		tmp+=w[j];
		rtmp=tmp;
		reverse(rtmp.begin(),rtmp.end());//reverse use
		if(rtmp==tmp)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;

	}
	return 0;
}
