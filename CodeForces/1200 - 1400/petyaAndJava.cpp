#include <bits/stdc++.h>
using namespace std;
unsigned long long n;
main ()
{
	cin>>n;
	
	if (n<=127) cout<<"byte"<<endl;
		else
	if (n<=32767) cout<<"short"<<endl;
		else
	if (n<=2147483647) cout<<"int"<<endl;
		else
	if (n<=9223372036854775807) cout<<"long"<<endl;
		else cout<<"BigInteger"<<endl;
}