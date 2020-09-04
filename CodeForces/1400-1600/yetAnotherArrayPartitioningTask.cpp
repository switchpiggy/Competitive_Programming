#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, a[200007];

int main() {
    cin >> n >> m >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    vector<ll> v(a, a + n);
    sort(v.begin(), v.end(), greater<ll>());

    ll ans = 0;
    map<ll, ll> s;
    for(ll i = 0; i < m * k && i < n; ++i) {
        ans += v[i];
        s[v[i]]++;
    }

    vector<ll> res;
    ll cnt = 0;
    for(ll i = 0; i < n; ++i) {
        if(s[a[i]]) {
            cnt++;
            if(cnt == m) {
                cnt = 0;
                res.push_back(i + 1);
            }
            s[a[i]]--;
        }
        if(res.size() == k - 1) break;
    }

    cout << ans << endl;
    for(ll i = 0; i < res.size(); ++i) cout << res[i] << ' ';
    return 0;
}