#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];
bool comp[1000007];
vector<ll> p;

ll fastpow(ll x, ll y) {
    if(!y) return 1;
    ll recurse = fastpow(x, y/2);
    if(y%2) return recurse * recurse * x;
    return recurse * recurse;
}

void sieve() {
    for(ll i = 2; i <= 1000000; ++i) {
        if(comp[i]) continue;
        for(ll j = 2 * i; j <= 1000000; j += i) comp[j] = 1;
    }

    for(ll i = 2; i <= 1000000; ++i) if(!comp[i]) p.push_back(i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll maxn = 0;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    sieve();
    //cout << comp[5] << '\n';
    //for(ll i : p) cout << i << ' ';

    ll ans = 1;
    for(ll i = 0; i < (ll)p.size(); ++i) {
        if(maxn < p[i]) break;
        ll min1 = LLONG_MAX, min2 = LLONG_MAX, cnt = 0;
        for(ll j = 0; j < n; ++j) {
            ll cur = 0;
            while(a[j]%p[i] == 0) {
                a[j] /= p[i];
                cur++;
            }

            if(!cur) cnt++;
             {
                if(cur <= min1) {
                    min2 = min1;
                    min1 = cur;
                } else if(cur <= min2) {
                    min2 = cur;
                }
            }

            if(cnt >= 2) break;
        }

        if(cnt < 2 && min2 != LLONG_MAX) {
            ans *= fastpow(p[i], min2);
        }
    }

    cout << ans << '\n';

    return 0;
}