#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, dig[4], m, s, c;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 0; i <= 3; ++i) dig[i] = -1;
    for(ll i = 0; i < m; ++i) {
        cin >> s >> c;
        s--;
        if(dig[s] != -1 && dig[s] != c) {
            cout << "-1\n";
            return 0;
        }

        dig[s] = c;
    }

    if(n == 1) {
        cout << max(0ll, dig[0]) << '\n';
        return 0;
    }

    for(ll i = (ll)pow(10, n - 1); i < (ll)pow(10, n); ++i) {
        string t = to_string(i);
        bool ok = 1;

        if(t[0] == '0') continue;

        for(ll j = 0; j < (ll)t.length(); ++j) {
            if(dig[j] != -1 && dig[j] != t[j] - '0') {
                ok = 0;
                break;
            }
        }

        if(ok) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}