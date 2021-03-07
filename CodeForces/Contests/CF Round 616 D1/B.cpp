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
string s;
ll q, l, r, cnt[200007][26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> q;
    for(ll i = 0; i < sz(s); ++i) {
        for(ll j = 0; j < 26; ++j) {
            if(s[i] - 'a' == j) cnt[i + 1][j] = cnt[i][j] + 1;
            else cnt[i + 1][j] = cnt[i][j];
        }
    }

    while(q--) {
        cin >> l >> r;
        ll cur = 0;
        for(ll i = 0; i < 26; ++i) cur += (cnt[r][i] - cnt[l - 1][i] > 0);

        if(s[l - 1] != s[r - 1] || cur >= 3 || r == l) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}