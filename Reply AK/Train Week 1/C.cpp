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
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll t, n[4], m;
string s[4];
set<string> st[4];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.in", "r", stdin);
    cin >> t;

    for(ll tc = 1; tc <= t; ++tc) {
        for(ll i = 0; i < 4; ++i) cin >> n[i], st[i].clear();
        cin >> m;
        for(ll i = 0; i < 4; ++i) cin >> s[i];

        for(ll i = 0; i < 4; ++i) {
            for(ll j = 0; j + m - 1 < n[i]; ++j) {
                st[i].insert(s[i].substr(j, m));
            }
        }

        string a;
        for(ll i = 0; i + m - 1 < n[0]; ++i) {
            string cur = s[0].substr(i, m);
            if(st[0].count(cur) && st[1].count(cur) && st[2].count(cur) && st[3].count(cur)) {
                a = cur;
                break;
            } 
        }

        cout << "Case #" << tc << ": ";
        for(ll i = 0; i < 4; ++i) {
            for(ll j = 0; j + m - 1 < n[i]; ++j) {
                if(s[i].substr(j, m) == a) {
                    cout << j << ' ';
                    break;
                }
            }
        }

        cout << '\n';
    }

    return 0;
}