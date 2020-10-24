#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, xx;
vector<pair<ll, ll>> ff, cc;

ll solve(ll s) {
    ll x = xx;
    ll ans = 0, step = s;

    vector<pair<ll, ll>> f(ff);
    vector<pair<ll, ll>> c(cc);

    while(!f.empty() || !c.empty()) {
        if((f.empty() && step) || (c.empty() && !step)) break;
        if((!step && c[0].first > x) || (step && f[0].first > x) || (x < f[0].first && x < c[0].first)) break;
        ans++;
        if(step) {
            ll cur = 0;
            for(ll i = 0; i < (ll)f.size(); ++i) {
                if(f[i].first <= x && f[i].second > f[cur].second) {
                    cur = i;
                } else if(f[i].first > x) break;
            }
            //cout << f[cur].first << ' ' << f[cur].second << '\n';
            x += f[cur].second;
            f.erase(f.begin() + cur);
        } else {
            ll cur = 0;
            for(ll i = 0; i < (ll)c.size(); ++i) {
                if(c[i].first <= x && c[i].second > c[cur].second) {
                    cur = i;
                } else if(c[i].first > x) break;
            }
            //cout << c[cur].first << ' ' << c[cur].second << '\n';
            x += c[cur].second;
            c.erase(c.begin() + cur);
        }

        step = 1 - step;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> xx;
    for(ll i = 0; i < n; ++i) {
        ll t, h, m;
        cin >> t >> h >> m;
        if(t) ff.push_back({h, m});
        else cc.push_back({h, m});
    }

    sort(ff.begin(), ff.end());
    sort(cc.begin(), cc.end());

    //step = 1 - step;

    cout << max(solve(0), solve(1)) << '\n';
    return 0;
}