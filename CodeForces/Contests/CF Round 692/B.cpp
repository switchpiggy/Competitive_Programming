#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = n; i == i; ++i) {
            bool ok = 1;
            string s = to_string(i);
            for(ll j = 0; j < (ll)s.length(); ++j) {
                if(s[j] != '0' && i%(s[j] - '0') != 0) {
                    ok = 0;
                    break;
                }
            }

            if(ok) {
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}