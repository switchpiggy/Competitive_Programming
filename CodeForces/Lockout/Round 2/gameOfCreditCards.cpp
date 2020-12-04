#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s >> t;
    sort(s.begin(), s.end(), greater<ll>());
    ll ans = 0, ans2 = 0;
    string v = t;
    sort(v.begin(), v.end());
    for(ll i = 0; i < (ll)s.length(); ++i) {
        bool ok = 0;
        for(ll j = 0; j < n; ++j) {
            if(isdigit(v[j]) && v[j] - '0' >= s[i] - '0') {
                v[j] = '-';
                ok = 1;
                break;
            }
        }

        if(!ok) {
            ans++;
            for(ll j = 0; j < n; ++j) if(isdigit(v[j])) {
                v[j] = '-';
                break;
            }
        }
    }

    for(ll i =0 ; i < n; ++i) {
        //bool ok = 0;
        for(ll j = 0; j < n; ++j) {
            if(isdigit(t[j]) && t[j] - '0' > s[i] - '0') {
                t[j] = '-';
                ans2++;
                break;
            }
        }
    }

    cout << ans << '\n' << ans2 << '\n';
    return 0;
}