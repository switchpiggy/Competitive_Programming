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
set<pair<ll, ll>> v;
ll n, m, p[600007], p2[600007];

pair<ll, ll> poly_hash(string s) {
    ll res = 0, res1 = 0;
    for(ll i = 0; i < sz(s); ++i) {
        res = (res + ((s[i] - 'a' + 1) * p[i])%MOD)%MOD;
        res1 = (res1 + ((s[i] - 'a' + 1) * p2[i])%MOD)%MOD;
    }

    return {res, res1};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    p[0] = 1;
    for(ll i = 1; i <= 600000; ++i) p[i] = (p[i - 1] * 3)%MOD;
    p2[0] = 1;
    for(ll i = 1; i <= 600000; ++i) p2[i] = (p2[i - 1]  * 7)%MOD;

    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.insert(poly_hash(s));
    }

    //sort(all(v));

    while(m--) {
        string s;
        cin >> s;
        bool ok = 0;
        pair<ll, ll> q = poly_hash(s);

        for(ll i = 0; i < sz(s); ++i) {
            //char c = s[i];
            for(char a = 'a'; a <= 'c'; ++a) {
                if(s[i] == a) continue;
                pair<ll, ll> cur = q;
                cur.first -= ((s[i] - 'a' + 1) * p[i])%MOD;
                cur.first = (cur.first + MOD)%MOD;
                cur.first += ((a - 'a' + 1) * p[i])%MOD;
                cur.first %= MOD;

                cur.second -= ((s[i] - 'a' + 1) * p2[i])%MOD;
                cur.second = (cur.second + MOD)%MOD;
                cur.second += ((a - 'a' + 1) * p2[i])%MOD;
                cur.second %= MOD;

                //s[i] = c;
                if(v.count(cur)) {
                    ok = 1;
                    break;
                }
            }

            if(ok) break;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}