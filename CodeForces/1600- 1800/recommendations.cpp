#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a[200007], t[200007], n;
pair<ll, ll> p[200007];
priority_queue<ll> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    for(ll i = 1; i <= n; ++i) cin >> t[i];
    for(ll i = 1; i <= n; ++i) p[i] = {a[i], t[i]};
    sort(p + 1, p + n + 1);
    p[n + 1] = {LLONG_MAX, 0};

    ll sum = 0, prev = 0, ans = 0;
    for(ll i = 1; i <= n + 1; ++i) {
        if(p[i].first > prev) {
            while(p[i].first > prev && !q.empty()) {
                ll f = q.top();
                q.pop();
                sum -= f;
                ans += sum;
                prev++;
            }

            prev = p[i].first;
        }

        q.push(p[i].second);
        sum += p[i].second;
    }

    cout << ans << '\n';
    return 0;
}