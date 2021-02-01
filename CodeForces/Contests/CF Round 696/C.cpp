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
#define INF 0x3f3f3f3f3f3f3f3f
#define flout cout << fixed << setprecision(12)
ll t, n, a[2007];
vector<pair<ll, ll>> ans;
map<ll, ll> cnt, cur;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cnt.clear();
        cin >> n;
        for(ll i = 0; i < 2 * n; ++i) {
            cin >> a[i];
            cnt[a[i]]++;
        }

        sort(a, a + 2 * n);
        bool ok = 0;
        for(ll i = 2 * n - 2; i >= 0; --i) {
            cur.clear();
            ans.clear();
            bool v = 1;
            ll sum = a[2 * n - 1] + a[i];
            for(ll j = 2 * n - 1; j >= 0; --j) {
                if(cur[a[j]] == cnt[a[j]]) continue;
                if(cur[sum - a[j]] >= cnt[sum - a[j]] || (sum - a[j] == a[j] && cur[a[j]] + 2 > cnt[a[j]])) {
                    v = 0;
                    break;
                }

                cur[sum - a[j]]++;
                cur[a[j]]++;
                ans.push_back({a[j], sum - a[j]});
                sum = a[j];
            }

            for(ll j = 0; j < 2 * n; ++j) {
                if(cur[a[j]] < cnt[a[j]]) {
                    v = 0;
                    break;
                }
            }

            if(v) {
                ok = 1;
                cout << "YES\n" << a[i] + a[2 * n - 1] << '\n';
                for(pair<ll, ll> j : ans) cout << j.first << ' ' << j.second << '\n';
                break;
            }
        }

        if(!ok) cout << "NO\n";
    }

    return 0;
}