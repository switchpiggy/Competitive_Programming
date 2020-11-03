#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, d[3007];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i < m; ++i) cin >> d[i];

    sort(d, d + m);

    if(d[0] == 1 || d[m - 1] == n) {
        cout << "NO\n";
        return 0;
    }

    ll cur = 1;
    for(ll i = 1; i < m; ++i) {
        if(d[i] == d[i - 1] + 1) cur++;
        else {
            if(cur > 2) {
                cout << "NO\n";
                return 0;
            }

            cur = 1;
        }
    }

    if(cur > 2) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    return 0;
}