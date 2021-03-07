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
ll t, n, k;
string s;
ll pref[100007][26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k >> s;
        for(ll i = 0; i < sz(s); ++i) {
            for(ll j = 0; j < 26; ++j) pref[i][j] = 0;
        }
        for(ll i = 0; i < sz(s); ++i) pref[i][s[i] - 'a']++;
        for(ll i = 1; i < sz(s); ++i) {
            for(ll j = 0; j < 26; ++j) {
                pref[i][j] += pref[i - 1][j];
            }
        }

        bool ok = 0;
        for(ll i = sz(s) - 1; i >= 0; --i) {
            // pref[i][s[i] - 'a']--;
            for(ll j = (s[i] - 'a') + (i != sz(s) - 1); j < 26; ++j) {
                // pref[i][j]++;
                ll cnt = 0;
                for(ll l = 0; l < 26; ++l) {
                    if(i ? pref[i - 1][l] + (j == l) : (j == l)) cnt += (k - (i ? (pref[i - 1][l] + (j == l))%k : (j == l)))%k;
                    // if(i) cout << pref[sz(s) - 1][l] << ' ';
                }

                if(sz(s) >= cnt + (i + 1) && (sz(s) - (i + 1) - cnt)%k == 0) {
                    ok = 1;
                    // cout << cnt << ' ';
                    if(i) cout << s.substr(0, i);
                    cout << char(j + 'a');
                    if(i + 1 + cnt <= sz(s)) cout << string((sz(s) - (i + 1) - cnt), 'a');
                    for(ll l = 0; l < 26; ++l) {
                        if(i ? pref[i - 1][l] + (j == l) : (j == l)) cout << string((k - (i ? (pref[i - 1][l] + (j == l))%k : (j == l)))%k, l + 'a');
                    }
                    cout << '\n';
                    break;
                }

                // pref[i][j]--;
            }

            if(ok) break;
            // pref[i][s[i] - 'a']++;
        }

        if(!ok) cout << "-1\n";
    }

    return 0;
}