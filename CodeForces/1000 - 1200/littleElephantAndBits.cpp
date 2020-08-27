#include<bits/stdc++.h>
using namespace std;
int t,flag=0;
int main()
{	string a;
 	cin>>a;
 	int n=a.size();
 	for(int i=0;i<n;++i)
 		if(a[i]=='0' && !flag)
 			t=i,flag=1;
 	if(!flag)
 		for(int i=1;i<n;++i)
 			cout<<a[i];
 	else
 		for(int i=0;i<n;++i)
 			if(i!=t)
 				cout<<a[i];
 	cout<<endl;
    return 0;
}