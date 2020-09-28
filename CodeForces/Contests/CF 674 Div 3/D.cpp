#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007], inf[200007];
map<ll, ll> occ;

int main() {
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    for(ll i = 1; i <= n; ++i) a[i] += a[i - 1];

    ll curInc = 0;

    

    //cout << ans << '\n';
    return 0;
}