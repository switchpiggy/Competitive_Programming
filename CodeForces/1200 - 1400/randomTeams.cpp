#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
ll n, m;
 
main()
{
	cin >> n >> m;
	cout << m*(n/m)*(n/m-1)/2+(n/m)*(n%m) << " " << (n-m)*(n-m+1)/2;
}