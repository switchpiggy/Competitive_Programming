#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, edges[4100], sum[4100];
ll ans = 0;

void dfs(ll v) {
    if(v >= (int)(pow(2, n))) {
        return;
    }

    ll left = edges[v*2];
    ll right = edges[v*2 + 1];

    dfs(v*2);
    dfs(v*2 + 1);

    ans += max(sum[v*2] + left, sum[v*2 + 1] + right) - min(sum[v*2] + left, sum[v*2 + 1] + right);
    sum[v] = max(sum[v*2] + left, sum[v*2 + 1] + right);
}

int main() {

    scanf("%lld", &n);
    for(int i = 2; i <= (int)(pow(2, n + 2)); ++i) scanf("%lld", &edges[i]);

    dfs(1);
    printf("%lld", ans);

}