#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, deg[507];
bool used[507];
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll sum = 0;
    for(ll i = 1; i <= n; ++i) {
        cin >> deg[i];
        sum += deg[i];
    }

    if(sum < 2 * n - 2) {
        cout << "NO\n";
        return 0;
    }

    ll prev = -1, res = 0;
    for(ll i = 1; i <= n; ++i) {
        if(deg[i] > 1) {
            prev = i;
            used[i] = 1;
            break;
        }
    }

    for(ll i = 1; i <= n; ++i) {
        if(deg[i] > 1 && !used[i]) {
            deg[prev]--;
            deg[i]--;
            v.push_back({prev, i});
            prev = i;
            used[i] = 1;
            res++;
        }
    }

    if(v.empty()) {
        for(ll i = 1; i <= n; ++i) if(i != prev) v.push_back({i, prev});
        cout << "YES 2\n" << (ll)v.size() << '\n';
        for(ll i = 0; i < (ll)v.size(); ++i) cout << v[i].first << ' ' << v[i].second << '\n';
        return 0;
    }

    bool e = 0, f = 0;
    for(ll i = 1; i <= n; ++i) {
        if(deg[i] != 1 || used[i]) continue;

        if(deg[v[0].first] && !e) {
            deg[v[0].first]--;
            deg[i] = 0;
            v.push_back({v[0].first, i});
            used[i] = 1;
            e = 1;
            continue;
        }

        if(deg[v.back().second] && !f) {
            deg[v.back().second]--;
            deg[i] = 0;
            v.push_back({v.back().second, i});
            used[i] = 1;
            f = 1;
            continue;
        }

        for(ll j = 1; j <= n; ++j) {
            if(deg[j] && used[j]) {
                deg[j]--;
                v.push_back({j, i});
                deg[i] = 0;
                used[i] = 1;
                break;
            }
        }
    }

    for(ll i = 1; i <= n; ++i) if(!used[i]) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES " << res + e + f << '\n' << (ll)v.size() << '\n';
    for(ll i = 0; i < (ll)v.size(); ++i) cout << v[i].first << ' ' << v[i].second << '\n';
    return 0;
}