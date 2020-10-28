#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];
vector<ll> diff;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    for(ll i = 1; i < n; ++i) diff.push_back(a[i] - a[i - 1]);

    sort(diff.begin(), diff.end());

    if(diff.empty()) {
        cout << "-1\n";
        return 0;
    }

    if((ll)diff.size() == 1) {
        if(a[0] == a[1]) {
            cout << 1 << '\n' << a[0] << '\n';
            return 0;
        }
        ll ans = 2 + (diff[0]%2 == 0);
        cout << ans << '\n';
        cout << a[0] - diff[0] << ' ';
        if(abs(diff[0])%2 == 0) cout << a[0] + diff[0]/2 << ' ';
        cout << a[1] + diff[0] << ' ';
        return 0;
    }

    if(diff[0] == diff.back()) {
        if(a[0] == a[n - 1]) {
            cout << 1 << '\n' << a[0] << '\n';
            return 0;
        }
        cout << 2 << '\n';
        cout << a[0] - diff[0] << ' ' << a[n - 1] + diff[0] << '\n';
        return 0;
    }

    if(!(diff[0] == diff[n - 3] && diff[n - 2] == diff[n - 3] * 2)) {
        cout << 0 << '\n';
        return 0;
    }

    cout << 1 << '\n';
    for(ll i = 0; i < n - 1; ++i) {
        if(a[i + 1] - a[i] == diff[n - 2]) {
            cout << a[i] + diff[n - 3] << '\n';
            return 0;
        }
    }

    return 0;
}