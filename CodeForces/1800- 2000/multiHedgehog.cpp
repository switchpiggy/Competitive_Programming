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
ll n, k, dp[100007], x, y, deg[100007];
map<ll, ll> res;
vector<ll> adj[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mn1(dp);
    cin >> n >> k;
    for(ll i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }

    benq<ll> ben;
    for(ll i = 1; i <= n; ++i) {
        if(deg[i] == 1) {
            dp[i] = 0;
            ben.push(i);
        }
    }

    while(!ben.empty()) {
        ll f = ben.front();
        ben.pop();

        //if(dp[f] != -1) continue;
        ll cnt = 0;
        for(ll i : adj[f]) {
            if(dp[i] != -1) {
                cnt++;
                if(dp[f] == -1) dp[f] = dp[i] + 1;
                else if(dp[i] != dp[f] - 1) {
                    cout << "No\n";
                    return 0;
                }
            }
            deg[i]--;
            if(deg[i] == 1) ben.push(i);
        }

        if(dp[f] && cnt < 3) {
            cout << "No\n";
            return 0;
        }

        //if(dp[f] == -1) dp[f] = 0;
    }

    for(ll i = 1; i <= n; ++i) {
        res[dp[i]]++;
    }

    cout << (res[k] == 1 ? "Yes\n" : "No\n");
    return 0;
}