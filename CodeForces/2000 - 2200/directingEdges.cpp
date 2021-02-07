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
ll t, n, m, pos[200007], in[200007];
vector<ll> adj[200007];
vector<pair<ll, pair<ll, ll>>> e;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        e.clear();
        cin >> n >> m;
        for(ll i = 1; i <= n; ++i) {
            pos[i] = -1;
            adj[i].clear();
            in[i] = 0;
        }

        for(ll i = 0; i < m; ++i) {
            ll x, y, c;
            cin >> c >> x >> y;
            if(c) {
                in[y]++;
                adj[x].push_back(y);
            }

            e.push_back({c, {x, y}});
        }

        bool ok = 1;
        benq<ll> ben;

        for(ll i = 1; i <= n; ++i) {
            if(!in[i]) ben.push(i);
        }

        ll cnt = 0;
        while(!ben.empty()) {
            ll f = ben.front();
            ben.pop();
            pos[f] = cnt++;

            for(ll i : adj[f]) {
                in[i]--;
                if(!in[i]) ben.push(i);
            }
        }

        for(ll i = 1; i <= n; ++i) {
            if(pos[i] == -1) {
                ok = 0;
                break;
            }
        }

        if(!ok) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for(pair<ll, pair<ll, ll>> i : e) {
            if(i.first) cout << i.second.first << ' ' << i.second.second << '\n';
            else {
                if(pos[i.second.first] > pos[i.second.second]) swap(i.second.first, i.second.second);
                cout << i.second.first << ' ' << i.second.second << '\n';
            }
        }

    }

    return 0;
}