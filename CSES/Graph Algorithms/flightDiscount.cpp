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
ll n, m, a, b, c, dist[100007][2];
vector<pair<ll, ll>> adj[100007];
pbenq<pair<ll, pair<ll, bool>>> ben;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while(m--) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    inf(dist);
    dist[1][0] = 0;
    ben.push({0, {1, 0}});

    while(!ben.empty()) {
        auto t = ben.top();
        ben.pop();
        t.first *= -1;
        if(t.first > dist[t.second.first][t.second.second]) continue;
        for(auto i : adj[t.second.first]) {
            if(!t.second.second) {
                if(dist[i.first][1] > t.first + i.second/2) {
                    dist[i.first][1] = t.first + i.second/2;
                    ben.push({-dist[i.first][1], {i.first, 1}});
                }
            }

            if(dist[i.first][t.second.second] > t.first + i.second) {
                dist[i.first][t.second.second] = t.first + i.second;
                ben.push({-dist[i.first][t.second.second], {i.first, t.second.second}});
            }
        }
    }

    cout << min(dist[n][0], dist[n][1]) << '\n';
    return 0;
}