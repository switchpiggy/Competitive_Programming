#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define r 1e9
int main()
{
int a,b,c,d;
cin>>a>>b>>c>>d;
int ans1,ans2,mx,div;
ans1=a*d-c*b;
ans2=b*c-a*d;
mx=max(ans1,ans2);
 
if(mx==ans1){
    div=__gcd(ans1,a*d);
    cout<<ans1/div<<"/"<<a*d/div;
}
else if(mx==ans2){
    div=__gcd(ans2,b*c);
    cout<<ans2/div<<"/"<<b*c/div;
}
return 0;
}