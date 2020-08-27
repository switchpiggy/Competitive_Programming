#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll comp(pair<ll, ll>x, pair<ll, ll>y) {
    if(x.first == y.first) {
        return x.second < y.second;
    }
    return x.first < y.first;
}


ll n;
vector<pair<ll, ll>> v;
vector<int> edge[100005];
bool visited[100005];

void dfs(ll j) {

    if(visited[j]) {
        return;
    } else visited[j] = 1;

    for(int i = 0; i < edge[j].size(); ++i) {
        if(!visited[edge[j][i]]) dfs(edge[j][i]);
    }

    return;

}



int main() {
    freopen("moop.in", "r", stdin);
    freopen("moop.out", "w", stdout);
    scanf("%lld", &n);
    for(int i = 0; i < n; ++i) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        v.push_back(make_pair(x, y));
    }
    //for(int i = 0; i < v.size(); ++i) printf("%lld %lld\n", v[i].first, v[i].second);
    sort(v.begin(), v.end(), comp);

    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(v[i].first <= v[j].first && v[i].second <= v[j].second) {
            	edge[i].push_back(j);
            	edge[j].push_back(i);
            }
            
        }
    }

    ll ans = 0;

    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {
            dfs(i);
            ans++;
        }
    }

    printf("%lld\n", ans);

}