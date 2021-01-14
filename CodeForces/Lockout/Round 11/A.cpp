#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
vector<string> d = {"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if(isdigit(s[0])) {
            ll x = stoll(s);
            if(x >= 18) continue;
            ans++;
        } else {
            for(ll j = 0; j < (ll)d.size(); ++j) {
                if(d[j] == s) {
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
    return 0;
}