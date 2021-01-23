#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m0(x) memset(x, 0, sizeof(x))
#define m1(x) memset(x, 1, sizeof(x))
#define mn1(x) memset(x, -1, sizeof(x))
#define flout cout << fixed << setprecision(12)
vector<ll> app[300007];
ll n, q, s;
bool used[300007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    ll last = 0, cur = 0, cnt = 0;
    while(q--) {
        ll type;
        cin >> type;
        if(type == 3) {
            ll tt;
            cin >> tt;
            for(ll i = last; i < tt; ++i) {
                if(!used[i]) {
                    used[i] = 1;
                    cur--;
                }
            }

            last = max(last, tt);
        } else if(type == 1) {
            cin >> s;
            app[s].push_back(cnt++);
            cur++;
        } else {
            cin >> s;
            for(ll i : app[s]) {
                if(!used[i]) {
                    cur--;
                    used[i] = 1;
                }
            }

            app[s].clear();
        }

        cout << cur << '\n';
    }

    return 0;
}