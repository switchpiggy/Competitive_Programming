#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007], l[200007], r[200007], ans[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        r[i] = n;
        l[i] = -1;
    }

    stack<ll> s;
    for(ll i = 0; i < n; ++i) {
        while(!s.empty() && a[s.top()] >= a[i]) s.pop();
        if(!s.empty()) l[i] = s.top();
        s.push(i);
    }

    while(!s.empty()) s.pop();
    for(ll i = n - 1; i >= 0; --i) {
        while(!s.empty() && a[s.top()] >= a[i]) s.pop();
        if(!s.empty()) r[i] = s.top();
        s.push(i);
    }

    for(ll i = 0; i < n; ++i) {
        ans[r[i] - l[i] - 1] = max(ans[r[i] - l[i] - 1], a[i]);
    }

    for(ll i = n - 1; i >= 1; --i) ans[i] = max(ans[i], ans[i + 1]);
    for(ll i = 1; i <= n; ++i) cout << ans[i] << ' ';
    return 0;
}