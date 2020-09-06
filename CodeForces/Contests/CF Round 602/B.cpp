#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, q[100007], ans[100007];
bool used[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        memset(used, 0, sizeof(used));
        memset(ans, 0, sizeof(ans));

        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> q[i];
        ans[0] = q[0];
        used[q[0]] = 1;
        for(ll i = 1; i < n; ++i) {
            if(q[i] > q[i - 1]) {
                ans[i] = q[i];
                used[ans[i]] = 1;
            }
        }

        ll cur = 1;
        while(used[cur]) cur++;
        for(ll i = 1; i < n; ++i) {
            if(ans[i] == 0 && cur < q[i - 1]) {
                ans[i] = cur;
                used[cur] = 1;
                while(used[cur]) cur++;
            }
        }

        bool ok = 1;
        for(ll i = 1; i <= n; ++i) {
            if(!used[i]) {
                ok = 0;
                break;
            }
        }

        if(!ok) {
            cout << -1 << endl;
            continue;
        }

        for(ll i = 0; i < n; ++i) cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}