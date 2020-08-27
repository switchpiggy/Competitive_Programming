#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

bitset<100050> r;
vector<ll> v[100050];
vector<ll> ans;
ll n, p, c;

int main() {
    scanf("%lld", &n);

    for(int i = 1; i <= n; ++i) {
        scanf("%lld %lld", &p, &c);
        if(p != -1) {
            v[p].push_back(i);
        }
        r[i] = c;
    }

    for(int i = 1; i <= n; ++i) {
        ll count = 0;
        ll s = v[i].size();

        for(int j = 0; j < s; ++j) {
            count += r[v[i][j]];
        }
        if(r[i] && count == s) {
            ans.push_back(i);
        }
    }

    if(ans.empty()) {
        printf("-1\n");
        return 0;
    } 

    for(int i = 0; i < ans.size(); ++i) printf("%lld ", ans[i]);
}