#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, p[1000007], r[1000007];

ll get(ll x) {
    if(p[x] == -1) return -1;
    return p[x] = (p[x] == x ? x : get(p[x]));
}

void uni(ll x, ll y) {
    x = get(x);
    y = get(y);

    p[x] = y;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    iota(p + 1, p + 1 + n, 1);

    for(ll i = 0; i < m; ++i) {
        char t;
        cin >> t;
        if(t == '?') {
            ll a;
            cin >> a;
            cout << get(a) << '\n'; 
        } else {
            ll a;
            cin >> a;
            if(a == n) p[a] = -1;
            else uni(a, a + 1);
        }
    }
}