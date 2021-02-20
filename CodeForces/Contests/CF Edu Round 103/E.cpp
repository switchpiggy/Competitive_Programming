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
#define mn(x) memset(x, -1, sizeof(x))
#define inf(x) memset(x, 0x3f, sizeof(x))
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll n, m, k, in[100007], p[100007];
vector<ll> v;
set<string> pat[16];
map<string, ll> ind;
vector<ll> adj[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ll mask = 0;
        for(ll i = 0; i < k; ++i) {
            if(s[i] != '_') mask += (1 << i);
        }

        pat[mask].insert(s);
        ind[s] = i + 1;
    }

    for(ll i = 0; i < m; ++i) {
        string s;
        ll x;
        cin >> s >> x;

        bool ok = 0;
        for(ll i = 0; i < (1 << k); ++i) {
            string t;
            for(ll j = 0; j < k; ++j) if(i & (1 << j)) t += s[j];
            else t += '_';

            if(pat[i].find(t) != pat[i].end()) {
                if(ind[t] == x) ok = 1;
                else adj[x].push_back(ind[t]), in[ind[t]]++;
            }
        }

        if(!ok) {
            cout << "NO\n";
            return 0;
        }
    }
    
    benq<ll> ben;
    ll cnt = 0;
    for(ll i = 1; i <= n; ++i) if(!in[i]) ben.push(i), v.push_back(i), p[i] = ++cnt;

    while(!ben.empty()) {
        ll f = ben.front();
        ben.pop();

        for(ll i : adj[f]) {
            --in[i];
            if(!in[i]) {
                p[i] = ++cnt;
                v.push_back(i);
                ben.push(i);
            }
        }
    }

    for(ll i = 1; i <= n; ++i) {
        if(!p[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for(ll i : v) cout << i << ' ';
    cout << '\n';
    return 0;
}