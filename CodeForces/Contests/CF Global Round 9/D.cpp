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
ll t, n, a[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while(t--) {
        cin >> n;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        vector<ll> res;
        set<ll> s;
        for(ll i = 0; i < n; ++i) {
            s.clear();
            for(ll j = 0; j < n; ++j) s.insert(a[j]); //cout << a[j] << ' ';
            ll mex = 0;
            for(ll j = 0; j <= n; ++j) {
                if(s.find(j) == s.end()) {
                    mex = j;
                    break;
                }
            }

            if(mex == n) {
                bool ok = 0;
                for(ll j = 0; j < n; ++j) {
                    if(a[j] != j) {
                        ok = 1;
                        res.push_back(j + 1);
                        //a[j] = n;
                        mex = a[j];
                        a[j] = n;
                        break;
                    }
                }

                if(!ok) break;
            }

            if(a[mex] != mex) {
                //cout << mex << '\n';
                res.push_back(mex + 1);
                a[mex] = mex;
            }
        }

        cout << sz(res) << '\n';
        for(ll i : res) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}