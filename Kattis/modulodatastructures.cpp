#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benq queue
#define pbenq priority_queue
ll block[2007][2007], a[200007], n, q, p, b, c, d, t;

void update(ll x, ll y, ll e) {
    ll s = (ll)ceil(sqrt(n));
    if(y <= s) {
        block[y][x] += e;
        return;
    }

    if(y > s) {
        for(ll i = x; i <= n; i += y) {
            a[i] += e;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);    
    cin >> n >> q;
    for(ll i = 0; i < q; ++i) {
        cin >> t;
        if(t == 2) {
            cin >> d;
            ll sum = 0, s = (ll)(ceil(sqrt(n)));
            for(ll i = 1; i <= s; ++i) sum += block[i][d%i];
            cout << a[d] + sum << '\n';
        } else {
            cin >> p >> b >> c;
            update(p, b, c);
        }
    }

    return 0;
}