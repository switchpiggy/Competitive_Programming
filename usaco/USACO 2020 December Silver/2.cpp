#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
ll n, pref[2507][2507];
vector<pair<ll, ll>> p;
map<ll, ll> cx, cy;

bool comp(pair<ll, ll> x, pair<ll, ll> y) {
    return x.second < y.second;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        p.push_back({a, b});
    }

    sort(p.begin(), p.end());

    ll cnt = 0;
    for(ll i = 0; i < n; ++i) {
        cx[p[i].first] = ++cnt;
    }

    cnt = 0;
    sort(p.begin(), p.end(), comp);
    for(ll i = 0; i < n; ++i) {
        cy[p[i].second] = ++cnt;
    }

    for(ll i = 0; i < n; ++i) {
        pref[cx[p[i].first]][cy[p[i].second]]++;
    }   

    /*for(ll i = 1; i <= n; ++i) {
        pref[1][i] += pref[1][i - 1];
        pref[i][1] += pref[i - 1][1];
    }*/

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    sort(p.begin(), p.end());
    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = i; j < n; ++j) {
            ll a = cx[p[j].first], b = cx[p[i].first], c = cy[min(p[j].second, p[i].second)], d = cy[max(p[i].second, p[j].second)];
            ll num = pref[a][n] - pref[a][d - 1] - pref[b - 1][n] + pref[b - 1][d - 1];
            ll num2 = pref[a][c] - pref[b - 1][c];
            //cout << i << ' ' << j << ' ' << num << ' ' << num2 << '\n';
            ans += num * num2;
        }
    }

    cout << ans + 1 << '\n';
    return 0;
}