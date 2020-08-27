#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n, m, k, a[100007], temp;

int main() {
    scanf("%lld %lld %lld", &n, &k, &m);

    vector<ll> ans[m];
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &temp);
        ans[temp%m].push_back(temp);
    }

    bool flag = false;

    for(ll i = 0; i < m; ++i) {
        if(ans[i].size() >= k) {
            flag = 1;
            printf("Yes\n");
            for(ll j = 0; j < k; ++j) {
                printf("%lld ", ans[i][j]);
            }
            printf("\n");
            break;
        }
    }

    if(!flag) printf("No\n");

    return 0;
}