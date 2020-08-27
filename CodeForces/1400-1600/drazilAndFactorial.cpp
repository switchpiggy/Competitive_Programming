#include <bits/stdc++.h>
using namespace std;
 
string ans, M[] = {"","","2","3","322","5","53","7","7222","7332"};
long long a;
 
int main()
{
	cin>>a>>a;
	
  while(a)
    ans += M[a%10], a/=10;
    
	sort(ans.rbegin(),ans.rend());
	cout<<ans;				
}