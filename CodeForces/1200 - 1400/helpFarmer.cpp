#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
const int ms = 1e9 + 7;
int main()
{
   int n;
   cin >> n;
   ll mins = -1 , maxs = -1;
   for(int i = 1 ;i * i * i <= n ; i ++)
   {
       for(int j = 1 ; j * j * i <= n ; j ++ )
       {
           if(n % i == 0 && n / i % j == 0)
           {
               ll k = n / i / j ;
                ll a1 = (i + 1) * (j + 2) * (k + 2);
                ll a2 = (i + 2) * (j + 2) * (k + 1);
                ll a3 = (i + 2) * (j + 1) * (k + 2);
                if(mins == -1) mins = maxs = a1;
                mins = min(mins,min(a1,min(a2,a3)));
                maxs = max(maxs,max(a1,max(a2,a3)));
          }
       }
   }
   cout << mins - n << " " << maxs - n;
    return 0;
}