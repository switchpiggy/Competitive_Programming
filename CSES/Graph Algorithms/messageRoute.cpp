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
ll n, m, a, b, p[100007];
vector<ll> adj[100007];
ll d[100007];
benq<ll> ben;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    memset(d, -1, sizeof(d));

    for(ll i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ben.push(1);
    d[1] = 0;
    while(!ben.empty()) {
        ll f = ben.front();
        ben.pop();

        for(ll i : adj[f]) {
            if(d[i] != -1) continue;
            d[i] = d[f] + 1;
            p[i] = f;
            ben.push(i);
        }
    }

    if(d[n] == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << d[n] + 1 << '\n';
    ll cur = n;
    vector<ll> res = {n};
    while(cur != 1) {
        cur = p[cur];
        res.push_back(cur);
    }

    reverse(all(res));
    for(ll i : res) cout << i << ' ';
    cout << '\n';
    return 0;
}