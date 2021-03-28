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
ll n, m, a, b, pos[100007], in[100007];
vector<ll> v;
vector<ll> adj[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }

    benq<ll> ben;
    for(ll i = 1; i <= n; ++i) if(!in[i]) ben.push(i);

    while(sz(ben)) {
        ll f = ben.front();
        ben.pop();
        v.push_back(f);
        in[f]++;

        for(ll i : adj[f]) {
            in[i]--;
            if(!in[i]) ben.push(i);
        }
    }

    if(sz(v) < n) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    for(ll i : v) cout << i << ' ';
    cout << '\n';
    return 0;
}