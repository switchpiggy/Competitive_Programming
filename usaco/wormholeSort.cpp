#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, p[100007], r[100007], a[100007];
vector<pair<ll, pair<ll, ll>>> v;

ll get(ll x) {return p[x] = (p[x] == x ? x : get(p[x]));}

void uni(ll x, ll y) {
    x = get(x);
    y = get(y);
    if(r[x] == r[y]) r[x]++;
    if(r[x] > r[y]) swap(x, y);
    p[x] = y;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) {
        p[i] = i;
        cin >> a[i];
        //pos[a[i]] = i;
    }

    for(ll i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, {a, b}});
    }

    sort(v.begin(), v.end(), greater<pair<ll, pair<ll, ll>>>());

    bool ok = 1;
    for(ll i = 1; i <= n; ++i) {
        if(get(i) != get(a[i])) {
            ok = 0;
            break;
        }
    }

    if(ok) {
        cout << "-1\n";
        return 0;
    }

    for(ll i = 0; i < m; ++i) {
        ll x = v[i].second.first, y = v[i].second.second;
        if(get(x) != get(y)) uni(x, y);

        bool ok = 1;
        for(ll i = 1; i <= n; ++i) {
            if(get(i) != get(a[i])) {
                ok = 0;
                break;
            }
        }

        if(ok) {
            cout << v[i].first << '\n';
            return 0;
        }
    }

    return 0;
}