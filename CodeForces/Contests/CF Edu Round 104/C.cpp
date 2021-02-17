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
ll t, n, res[107][107], cnt[107];
vector<ll> v;

bool comp(ll x, ll y) {
    return cnt[x] > cnt[y];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        v.clear();
        inf(res);
        m0(cnt);
        
        ll w;
        if(n%2 == 0) {
            w = ((n * (n - 1))/2 - n/2)/n;
            for(ll i = 1; i + 1 <= n; i += 2) {
                res[i][i + 1] = res[i + 1][i] = 0;
            }
        } else w = ((n * (n - 1))/2)/n;
        
        for(ll i = 1; i <= n; ++i) v.push_back(i);

        for(ll i = 1; i <= n; ++i) {

            sort(all(v), comp);
            for(ll k = 0; k < n; ++k) {
                ll j = v[k];
                if(j != i && cnt[i] < w && res[i][j] == INF) {
                    res[i][j] = 1, res[j][i] = -1;
                    cnt[i]++;
                } else if(j != i && res[i][j] == INF && cnt[j] < w) {
                    res[i][j] = -1, res[j][i] = 1;
                    cnt[j]++;
                }
            }
        }

        for(ll i = 1; i <= n; ++i) {
            for(ll j = i + 1; j <= n; ++j) cout << res[i][j] << ' ';
        }

        //cout << '\n';
        //for(ll i = 1; i <= n; ++i) cout << cnt[i] << ' ';

        cout << '\n';
    }

    return 0;
}