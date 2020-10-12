#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007], occ[200007];
bool visited[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ll maxn = 0;
    for(ll i = 1; i <= n; ++i) {
        cin >> a[i];
        occ[a[i]]++;
        maxn = max(maxn, a[i]);
    }

    vector<ll> v;
    for(ll i = 1; i <= n; ++i) if(occ[i] == 0) {
        v.push_back(i);
        //cout << i << '\n';
    }

    ll cur = 0, ans = 0;
    for(ll i = 1; i <= n; ++i) {
        if(occ[a[i]] == 1 || cur >= (ll)v.size()) continue;
        if(visited[a[i]] || a[i] > v[cur]) {
            occ[a[i]]--;
            occ[v[cur]]++;
            a[i] = v[cur];
            cur++;
            ans++;
        }

        visited[a[i]] = 1;
    }

    cout << ans << '\n';
    for(ll i = 1; i <= n; ++i) cout << a[i] << ' ';
    cout << '\n';

    return 0;
}