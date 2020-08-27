#include<bits/stdc++.h>
 
using namespace std;

typedef long long int ll;
 
ll n, ans, a[209];
 
int main () {
 
scanf ("%lld", &n);
for (ll i = 1; i <= 2 * n; i++)
    scanf ("%lld", &a[i]);
for (ll i = 1; i <= 2 * n; i += 2)
    if (a[i] != a[i + 1])
    {
        ll j = i + 1;
        while (a[j] != a[i])
            j ++;
        while (j > i + 1)
            swap (a[j - 1], a[j]), j --, ans++;
    }
printf ("%lld\n", ans);
return 0;
}