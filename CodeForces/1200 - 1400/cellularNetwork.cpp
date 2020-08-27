#include <bits/stdc++.h>
using namespace std;
int n,m,p,r,c[100000],t[100000];
int main()
{
    cin>>n>>m;
    p=0;
    for(int i=0;i<n;i++)cin>>c[i];
    for(int i=0;i<m;i++)cin>>t[i];
    for(int i=0;i<n;i++)
    {
        while((abs(t[p]-c[i])>=abs(t[p+1]-c[i]))&&(p<m-1))
            p++;
        if(abs(t[p]-c[i])>r) r=abs(t[p]-c[i]);
    }
    cout<<r;
}