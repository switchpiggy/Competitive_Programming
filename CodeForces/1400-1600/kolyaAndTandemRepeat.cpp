#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s >> k;

    ll ans = 0;
    for(ll i = 0; i < (ll)s.length() + k; ++i) {
        for(ll j = i; j < (ll)s.length() + k; ++j) {
            bool ok = 1;
            
            for(ll l = i; l <= j; ++l) {
                if((l + (j - i + 1) < (ll)s.length() && s[l + (j - i+ 1)] != s[l]) || l + (j - i + 1) >= (ll)s.length() + k) {
                    ok = 0;
                    break;
                } 
            }

            if(ok) ans = max(ans, 2 * (j - i + 1));
        }
    }

    cout << ans << '\n';
    return 0;
}