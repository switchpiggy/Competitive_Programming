#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a;
vector<ll> pos[100007];
set<ll> ans;

int main() {
    vector<pair<ll, ll>> res;

    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &a);
        ans.insert(a);
        pos[a].push_back(i);
    }

    for(auto itr = ans.begin(); itr != ans.end(); ++itr) {
        ll x = *itr;
        if(pos[x].size() == 1) {
            res.push_back(make_pair(x, 0));
            continue;
        }

        bool flag = false;
        ll diff = pos[x][1] - pos[x][0];

        for(ll i = 1; i < pos[x].size(); ++i) {
            if(pos[x][i] - pos[x][i - 1] != diff) {
                flag = true;
                break;
            }
        }

        if(!flag) res.push_back(make_pair(x, diff));
    }

    cout << res.size() << endl;
    for(ll i = 0; i < res.size(); ++i) {
        printf("%lld %lld\n", res[i].first, res[i].second);
    }
}