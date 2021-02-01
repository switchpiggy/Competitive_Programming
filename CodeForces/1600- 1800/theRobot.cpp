#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m1(x) memset(x, 1, sizeof(x))
#define m0(x) memset(x, 0, sizeof(x))
#define inf(x) memset(x, 0x3f, sizeof(x))
#define flout cout << fixed << setprecision(12)
ll t;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        ll x = 0, y = 0;
        pair<ll, ll> ans = {0, 0};
        for(ll i = 0; i < sz(s); ++i) {
            if(s[i] == 'L') x--;
            else if(s[i] == 'R') x++;
            else if(s[i] == 'U') y++;
            else y--;

            ll cx = 0, cy = 0;
            for(ll j = 0; j < sz(s); ++j) {
                if(s[j] == 'L') {
                    if(cx - 1 == x && cy == y) continue;
                    cx--;
                } else if(s[j] == 'R') {
                    if(cx + 1 == x && cy == y) continue;
                    cx++;
                } else if(s[j] == 'U') {
                    if(cy + 1 == y && cx == x) continue;
                    cy++;
                } else {
                    if(cy - 1 == y && cx == x) continue;
                    cy--;
                }
            }

            if(cx == 0 && cy == 0) {
                ans = {x, y};
                break;
            }
        }

        cout << ans.first << ' ' << ans.second << '\n';
    }

    return 0;
}