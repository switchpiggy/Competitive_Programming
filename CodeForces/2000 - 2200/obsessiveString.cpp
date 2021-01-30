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
#define MOD 1000000007

string s, t;
ll q1[100007], q2[100007], a[100007];
bool g[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> t;
    string cur = s.substr(0, sz(t));

    if(cur == t) g[sz(cur)] = 1;
    for(ll i = sz(cur); i < sz(s); ++i) {
        cur.erase(0, 1);
        cur += s[i];

        if(cur == t) g[i + 1] = 1;
    }

    for(ll i = 1; i <= sz(s); ++i) {
        if(!g[i]) {
            a[i] = a[i - 1];
            q1[i] = (q1[i - 1] + a[i])%MOD;
            q2[i] = (q2[i - 1] + q1[i])%MOD;
            continue;
        }

        a[i] = (q2[i - sz(t)] + (i - sz(t) + 1))%MOD;
        q1[i] = (q1[i - 1] + a[i])%MOD;
        q2[i] = (q2[i - 1] + q1[i])%MOD;
    }

    //for(ll i = 1; i <= sz(s); ++i) cout << q1[i] << ' ';

    cout << q1[sz(s)] << '\n';
    return 0;
}