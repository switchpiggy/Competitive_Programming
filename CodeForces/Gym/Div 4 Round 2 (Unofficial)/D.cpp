#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string a, s;
map<char, ll> occ;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> s;
    for(ll i = 0; i < (ll)s.length(); ++i) occ[a[i]]++;

    if((ll)s.length() > (ll)a.length() + 1) {
        cout << "NO\n";
        return 0;
    }

    bool ok = 1, ok2 = 0;
    ll i = 1;
    if((ll)s.length() > (ll)a.length()) {
        ll d = 10 * (s[0] - '0') + (s[1] - '0') - (a[0] - '0');
        if(occ[d + '0']) {
            occ[d + '0']--;
            i = 2;
            ok2 = 1;
        } else {
            cout << "NO\n";
            return 0;
        }
    } else if(s[0] == a[0]) {
        cout << "NO\n";
        return 0;
    }

    for(; i < (ll)s.length(); ++i) {
        if(s[i] - '0' >= a[i - ok2] - '0' && occ[s[i] - a[i - ok2] + '0']) {
            occ[s[i] - a[i - ok2] + '0']--;
        } else {
            ok = 0;
            break;
        }
    }

    cout << (ok?"YES\n":"NO\n");
    return 0;
}