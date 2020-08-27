#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, p[100007];
vector<ll> ans;

int main() {
    scanf("%lld", &t);

    while(t--) {
        ans.clear();

        scanf("%lld", &n);
        for(ll i = 0; i < n; ++i) scanf("%lld", &p[i]);
        
        ans.push_back(p[0]);

        for(ll i = 1; i < n - 1; ++i) {
            if((p[i] > p[i - 1] && p[i] < p[i + 1]) || (p[i] < p[i - 1] && p[i] > p[i + 1])) continue;
            ans.push_back(p[i]);
        }
        
        ans.push_back(p[n - 1]);

        printf("%lld\n", ans.size());

        for(ll i = 0; i < ans.size(); ++i) printf("%lld ", ans[i]);
        
        if(ans.size()) printf("\n");
    }
}