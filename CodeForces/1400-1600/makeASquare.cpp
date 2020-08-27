#include <bits/stdc++.h>
using namespace std;
//FILE *fi=freopen("1.txt","r",stdin);
string s;
int n;
long long pp[20];
 
int main()
{
    cin>>s;
    pp[0]=1;
    for(int i=1;i<=10;i++)
        pp[i]=pp[i-1]*10LL;
    int n = s.length();
    int kq=-1;
    for(int mask = 0;mask < (1<<n) ; mask++)
    {
        vector <int> u;
        for(int i = 0;i<n;i++)
        {
            if(mask&(1<<i))
                u.push_back(s[i]-'0');
        }
        long long x = 0;
        bool ok=false;
        for(int i=0;i<u.size();i++)
        {
            if(ok==false&&u[i]==0)
            {
                break;
            }
            ok=true;
            x += u[i]*pp[u.size()-i-1];
        }
        if(!ok)
            continue;
        long long t = sqrt(x);
        if(t*t==x)
        {
            kq = max(kq , __builtin_popcount(mask));
        }
 
    }
    if(kq==-1)
        cout<<-1;
    else cout<<s.length()-kq;
    return 0;
}