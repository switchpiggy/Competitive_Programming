#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m, row[507][507], col[507][507], ans[507];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < m; ++j) cin >> row[i][j];
        }

        for(ll i = 0; i < m; ++i) {
            for(ll j = 0; j < n; ++j) {
                cin >> col[i][j];
            }
        }

        ll firstCol = 0;
        vector<ll> r;

        for(ll i = 0; i < n; ++i) r.push_back(row[i][0]);

        sort(r.begin(), r.end());

        for(ll i = 0; i < m; ++i) {
            bool ok = 1;
            for(ll j = 0; j < n; ++j) {
                if(*lower_bound(r.begin(), r.end(), col[i][j]) != col[i][j]) {
                    ok = 0;
                    break;
                }
            }

            if(ok) {
                firstCol = i;
                break;
            }
        }

        for(ll i = 0; i < n; ++i) {
            ll cur = col[firstCol][i];

            for(ll j = 0; j < n; ++j) {
                if(row[j][0] == cur) {
                    ans[i] = j;
                    break;
                }
            }
        }

        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < m; ++j) {
                cout << row[ans[i]][j] << ' ';
            }

            cout << '\n';
        }
    }

    return 0;
}