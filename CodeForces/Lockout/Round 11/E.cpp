#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
string s, t;
ll n, last[2007][2007], f, d;
map<string, ll> a;
bool fre[2007][2007];
vector<pair<string, string>> res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d;
    ll cnt = 0;
    for(ll i = 0; i <= 1000; ++i) {
        for(ll j = 0; j <= 1000; ++j) last[i][j] = -1;
    }
    for(ll i = 0; i < n; ++i) {
        cin >> s >> t >> f;
        if(!a[s]) a[s] = ++cnt;
        if(!a[t]) a[t] = ++cnt;
        if(fre[a[s]][a[t]]) continue;
        if(last[a[t]][a[s]] != -1) {
            if(f - last[a[t]][a[s]] <= d && f > last[a[t]][a[s]]) {
                res.push_back({s, t});
                fre[a[s]][a[t]] = fre[a[t]][a[s]] = 1;
                //last[a[s]][a[t]] = last[a[t]][a[s]] = -2;
                continue;
            }
        } else {
            last[a[s]][a[t]] = f;
        }
    }

    cout << (ll)res.size() << '\n';
    for(pair<string, string> i : res) cout << i.first << ' ' << i.second << '\n';
    return 0;
}