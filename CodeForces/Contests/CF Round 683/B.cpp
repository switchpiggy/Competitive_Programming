#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, t, a[17][17];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;

        ll mins = INT_MIN, x = 0, sum = 0;
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < m; ++j) {
                cin >> a[i][j];
                if(abs(a[i][j]) < abs(mins)) mins = a[i][j];
                if(a[i][j] < 0) x++;
                sum += abs(a[i][j]);
            }
        }

        if(x%2 == 0) cout << sum << '\n';
        else cout << sum - 2 * abs(mins) << '\n';
    }

    return 0;
}