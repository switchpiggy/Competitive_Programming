#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[500007], res[500007][2];
vector<ll> p;
bool composite[10000007];

void sieve() {
    for(ll i = 2; i <= 10000000; ++i) {
        if(composite[i]) continue;
        p.push_back(i);
        for(ll j = 2 * i; j <= 10000000; j += i) composite[j] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    sieve();
    for(ll i = 0; i < n; ++i) cin >> a[i];

    for(ll i = 0; i < n; ++i) {
        if(!composite[a[i]]) {
            res[i][0] = res[i][1] = -1;
        }

        ll cur = -1;
        for(ll j = 0; j < (ll)p.size(); ++j) {
            if(p[j] * p[j] > a[i]) break;
            if(a[i]%p[j] == 0) {
                cur = p[j];
                break;
            }
        }

        if(cur == -1) {
            res[i][0] = res[i][1] = -1;
            continue;
        }

        ll b = a[i];
        while(b%cur == 0) b /= cur;
        if(b == 1 || b == a[i]) {
            res[i][0] = res[i][1] = -1;
            continue;
        }
        res[i][0] = b, res[i][1] = a[i]/b;
    }

    for(ll i = 0; i < n; ++i) cout << res[i][0] << ' ';
    cout << '\n';
    for(ll i = 0; i < n; ++i) cout << res[i][1] << ' ';
    cout << '\n';

    return 0;
}