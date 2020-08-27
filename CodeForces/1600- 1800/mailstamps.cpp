#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
map<int, bool> v;
map<int, vector<ll>> deg;
ll n,a ,b;
 
void dfs(ll x) {
    printf("%lld ", x);
    v[x] = 1;
    for(int i = 0; i < deg[x].size(); ++i) {
        if(!v[deg[x][i]]) dfs(deg[x][i]);
    }
    return;
}
 
int main() {
    scanf("%lld", &n);
 
    for(int i = 0; i < n; ++i) {
        scanf("%lld %lld", &a, &b);
        deg[a].push_back(b);
        deg[b].push_back(a);
    }
 
    for(auto itr = deg.begin(); itr != deg.end(); ++itr) {
        if(itr->second.size() == 1) {
            dfs(itr->first);
            break;
        }
    }
 
    printf("\n");
    return 0;
}