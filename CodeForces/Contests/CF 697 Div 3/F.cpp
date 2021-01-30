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
ll t, n, a[1007][1007], b[1007][1007];

bool check(ll c[1007][1007]) {
    //m0(c);
    for(ll i = 0; i < n; ++i) {
        if(c[0][i]^b[0][i]) {
            for(ll j = 0; j < n; ++j) c[j][i] ^= 1;
        }
    }

    for(ll i = 0; i < n; ++i) {
        ll x = c[i][0] ^ b[i][0];
        for(ll j = 1; j < n; ++j) {
            if((c[i][j]^b[i][j]) != x) return 0;
        }
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        m0(a);
        m0(b);
        for(ll i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for(ll j = 0; j < n; ++j) a[i][j] = s[j] - '0';
        }

        for(ll i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for(ll j = 0; j < n; ++j) b[i][j] = s[j] - '0';
        }

        if(check(a)) cout << "YES\n";
        else {
            for(ll i = 0; i < n; ++i) {
                a[0][i] ^= 1;
            }

            if(check(a)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}