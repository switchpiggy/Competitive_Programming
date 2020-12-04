#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, q[100007], p[100007];
bool used[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        memset(used, 0, sizeof(used));
        memset(p, 0, sizeof(p));

        for(ll i = 0; i < n; ++i) cin >> q[i];
        p[0] = q[0];
        used[p[0]] = 1;
        for(ll i = 1; i < n; ++i) {
            if(q[i] > q[i - 1]) {
                p[i] = q[i];
                used[p[i]] = 1;
            }
        }

        vector<ll> v;
        for(ll i = 1; i <= n; ++i) if(!used[i]) v.push_back(i);
        sort(v.begin(), v.end());

        ll cur = 0;
        bool ok = 1;
        for(ll i = 0; i < n; ++i) {
            if(!p[i]) {
                p[i] = v[cur];
                cur++;

                if(cur > (ll)v.size()) {
                    ok = 0;
                    break;
                }
            }
        }

        for(ll i = 0; i < n; ++i) {
            if(p[i] > q[i]) {
                ok = 0;
                break;
            }
        }

        if(!ok) cout << "-1";
        else for(ll i = 0; i < n; ++i) cout << p[i] << ' ';
        cout << '\n';
    }

    return 0;
}