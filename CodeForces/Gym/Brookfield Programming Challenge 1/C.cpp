#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll q, n, s, t[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> q;
    while(q--) {
        cin >> n >> s;
        for(ll i = 0; i < n; ++i) cin >> t[i];

        sort(t, t + n);

        bool ok = 0;
        for(ll i = 1; i < n; ++i) {
            if(t[i] < t[i - 1] + s) {
                cout << "YES\n";
                ok = 1;
                break;
            }
        }

        if(!ok) cout << "NO\n";
    }

    return 0;
}