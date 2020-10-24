#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[100007];
pair<ll, ll> cur[1007];
bool res[200001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(ll i = 1; i <= n; ++i) cin >> a[i];

    ll last = 0, cnt = 0;
    for(ll t = 0; t <= 150000; ++t) {
        for(ll i = 1; i <= k; ++i) {
            if(a[cur[i].second] == cur[i].first) {
                if(cur[i].second <= n && cur[i].second >= 1) cnt++;
                cur[i].second = ++last;
                cur[i].first = 0;
            }
        }

        ll d = round((100.0 * cnt)/(1.0 * n));
        for(ll i = 1; i <= k; ++i) {
            if(cur[i].second <= n && cur[i].second >= 1 && cur[i].first + 1 == d) res[cur[i].second] = 1;
            cur[i].first++;
        }
    }

    ll sum = 0;
    for(ll i = 1; i <= n; ++i) sum += res[i];

    cout << sum << '\n';
    return 0;
}