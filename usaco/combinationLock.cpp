#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

set<pair<ll, pair<ll, ll>>> s;
ll fj[3], master[3];
ll cnt = 0;

bool valid(ll a, ll b, ll c, ll a1, ll b1, ll c1) {
    if((abs(a - a1) <= 2 || abs(a - a1) >= n - 2) && (abs(b - b1) <= 2 || abs(b - b1) >= n - 2) && (abs(c - c1) <= 2 || abs(c - c1) >= n - 2)) return true;
    return false;
}

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < 3; ++i) scanf("%lld", &fj[i]);
    for(ll i = 0; i < 3; ++i) scanf("%lld", &master[i]);

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            for(ll k = 1; k <= n; ++k) {
                if(valid(i, j, k, fj[0], fj[1], fj[2]) || valid(i,j, k, master[0], master[1], master[2])) cnt++;
            }
        }
    }
    
    printf("%lld\n", cnt);

    return 0;
}