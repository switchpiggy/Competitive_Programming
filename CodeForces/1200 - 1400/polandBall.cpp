#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, c, z;
vector<ll> v[20005];
bool visited[20005];

void dfs(ll x) {
    visited[x] = 1;
    for(ll i = 0; i < v[x].size(); ++i) {
        if(!visited[v[x][i]]) {
            dfs(v[x][i]);
        }
    }
    return;
}

int main() {
    scanf("%lld", &n);
    for(ll i = 1; i <= n; ++i) {
        scanf("%lld", &z);
        v[i].push_back(z);
        v[z].push_back(i);
    }

    for(ll i = 1; i <= n; ++i) {
        if(!visited[i]) {
            dfs(i);
            c++;
        }
    }

    printf("%lld", c);
}