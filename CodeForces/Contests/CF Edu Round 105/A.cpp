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
ll t, n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        bool f = 0;
        for(ll i = 0; i < 2; ++i) {
            for(ll j = 0; j < 2; ++j) {
                for(ll k = 0; k < 2; ++k) {
                    ll cnt = 0;
                    bool ok = 1;
                    for(ll a = 0; a < sz(s); ++a) {
                        if(s[a] == 'A') {
                            if(i) cnt++;
                            else cnt--;
                        } else if(s[a] == 'B') {
                            if(j) cnt++;
                            else cnt--;
                        } else {
                            if(k) cnt++;
                            else cnt--;
                        }

                        if(cnt < 0) {
                            ok = 0;
                            break;
                        }
                    }

                    if(cnt != 0) ok = 0;
                    if(ok) {
                        f = 1;
                        break;
                    }
                }

                if(f) break;
            }

            if(f) break;
        }

        cout << (f ? "YES\n" : "NO\n");
    }

    return 0;
}