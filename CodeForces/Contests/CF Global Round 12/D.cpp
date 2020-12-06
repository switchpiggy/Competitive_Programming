#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[300007], cnt[300007], l[300007], r[300007];
bool ok[300007];
map<pair<ll, ll>, bool> found;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        found.clear();
        cin >> n;
        for(ll i = 1; i <= n; ++i) cin >> a[i];
        memset(cnt, 0, sizeof(cnt));
        memset(ok, 1, sizeof(ok));

        for(ll i = 0; i <= n; ++i) {
            l[i] = 0, r[i] = n + 1;
        }

        stack<ll> s;
        for(ll i = 1; i <= n; ++i) {
            while(!s.empty() && a[s.top()] >= a[i]) s.pop();
            if(!s.empty()) l[i] = s.top();
            s.push(i);
        }

        while(!s.empty()) s.pop();

        for(ll i = n; i >= 1; --i) {
            while(!s.empty() && a[s.top()] >= a[i]) s.pop();
            if(!s.empty()) r[i] = s.top();
            s.push(i);
        }

        

        cout << '\n';
    }

    return 0;
}