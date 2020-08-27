#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[200007];

int main() {
    scanf("%lld", &n);
    for(ll i = 1; i <= n; ++i) scanf("%lld", &a[i]);

    ll mins = INT_MAX;
    for(ll i = 1; i <= n; ++i) mins = min(mins, a[i]);

    vector<ll> ans;
    for(ll i = 1; i <= n; ++i) {
        if(a[i] == mins) ans.push_back(i);
    }

    sort(ans.begin(), ans.end());

    ll maxs = 0;
    for(ll i = 0; i < ans.size() - 1; ++i) {
    	//cout << ans[i] << ' ' << ans[i + 1] << endl;
        maxs = max(maxs, ans[i + 1] - ans[i] - 1);
    }

    maxs = max(maxs, (n - ans[ans.size() - 1]) + (ans[0] - 1));
    
    //cout << ans[ans.size() - 1] << ' ' << ans[0] << endl;    
    //cout << maxs << endl;

    printf("%lld\n", mins * n + maxs);

    return 0;
}