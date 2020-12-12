#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, p[300007];

ll get(ll x) {return p[x] = (p[x] == x ? x : get(p[x]));}

void uni(ll x, ll y) {
    x = get(x);
    y = get(y);
    p[x] = y;
}

void park(ll x) {
    ll y = get(x);
    cout << y << ' ';
    if(y == n) uni(y ,1);
    else uni(y, y + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    iota(p + 1, p + n + 1, 1);

    for(ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        park(a);
    }

    return 0;
}