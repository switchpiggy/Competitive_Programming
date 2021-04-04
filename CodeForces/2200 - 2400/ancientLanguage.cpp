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
ll n, k, p, in[1007], cnt;
vector<string> u[1007], v;
vector<ll> adj[30];
bool occ[30];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        cin >> p;
        for(ll j = 0; j < k; ++j) {
            string s;
            cin >> s;
            u[p].push_back(s);
            for(char c : s) if(!occ[c - 'a']) {
                occ[c - 'a'] = 1;
                cnt++;
            }
        }
    }

    for(ll i = 0; i < n; ++i) {
        for(auto j : u[i]) v.push_back(j);
    }

    for(ll i = 0; i < n * k - 1; ++i) {
        string s = v[i], t = v[i + 1];
        bool ok = 0;
        for(ll j = 0; j < min(sz(s), sz(t)); ++j) {
            if(s[j] != t[j]) {
                adj[s[j] - 'a'].push_back(t[j] - 'a');
                in[t[j] - 'a']++;
                ok = 1;
                break;
            }
        }

        if(!ok && sz(t) < sz(s)) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    vector<ll> ans;
    benq<ll> ben;
    for(ll i = 0; i < 26; ++i) {
        if(!in[i] && occ[i]) ben.push(i);
    }

    while(!ben.empty()) {
        ll x = ben.front();
        ben.pop();

        ans.push_back(x);
        for(ll i : adj[x]) {
            in[i]--;
            if(!in[i]) ben.push(i);
        }
    }

    if(sz(ans) < cnt) cout << "IMPOSSIBLE\n";
    else {
        for(ll i : ans) cout << char(i + 'a');
        cout << '\n';
    }

    // cout << cnt << ' ' << sz(ans) << '\n';
    return 0;
}