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
ll t, n, s, cnt[100007], w[100007], cur;
vector<pair<ll, ll>> adj[100007];
pbenq<pair<ll, ll>> pen;

void dfs(ll x, ll p) {
    if(sz(adj[x]) == 1 && p != -1) {
        cnt[x] = 1;
        cur += w[x];
        pen.push({w[x] - w[x]/2, x});
        //cout << w[x] << '\n';
        return;
    }

    for(pair<ll, ll> i : adj[x]) {
        //if(i.first == p)
        if(i.first == p) continue;
        w[i.first] = i.second;
        //cout << w[i.first] << '\n';
        dfs(i.first, x);
        cnt[x] += cnt[i.first];
    }

    if(p != -1) {
        cur += w[x] * cnt[x];
        pen.push({w[x] * cnt[x] - w[x]/2 * cnt[x], x});
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        while(!pen.empty()) pen.pop();

        cin >> n >> s;
        for(ll i = 1; i <= n; ++i) {
            adj[i].clear();
            cnt[i] = 0;
            w[i] = 0;
        }

        for(ll i = 0; i < n - 1; ++i) {
            ll a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
            //cout << a << ' ' << b << ' ' << w << '\n';
        }

        cur = 0;
        dfs(1, -1);

        ll ans = 0;
        //cout << cur << '\n';
        while(!pen.empty() && cur > s) {
            pair<ll, ll> f = pen.top();
            pen.pop();
            cur -= f.first;
            ans++;

            if(cur <= s) break;

            w[f.second] /= 2;
            pen.push({w[f.second] * cnt[f.second] - w[f.second]/2 * cnt[f.second], f.second});
        }

        cout << ans << '\n';
    }

    return 0;
}