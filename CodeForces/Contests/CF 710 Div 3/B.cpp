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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k >> s;
        ll ans = 0, fst = -1, lst = -1;

        for(ll i = 0; i < sz(s); ++i) {
            if(s[i] == '*') {
                if(fst == -1) fst = i;
                lst = i;
            }
        }    

        s[fst] = s[lst] = 'x';
        ans += 1 + (fst != lst);

        for(ll i = fst; i < lst; ++i) {
            if(s[i] != 'x') continue;
            bool ok = 0;
            ll nxt = lst;
            for(ll j = i + 1; j <= min(lst, i + k); ++j) {
                if(s[j] == 'x') {
                    ok = 1;
                    break;
                }

                if(s[j] == '*') nxt = j;
            }

            if(ok) continue;
            s[nxt] = 'x';
            ans++;
        } 

        cout << ans << '\n';
    }

    return 0;
}