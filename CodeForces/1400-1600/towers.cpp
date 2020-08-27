#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[107];
vector<pair<ll, ll>> ans;
ll maxn, minn;

int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &a[i]);
        maxn = max(maxn, a[i]);
        minn = min(minn, a[i]);
    }

    if(maxn == minn || n == 1) {
        printf("0 0\n");
        return 0;
    }

    for(ll t = 0; t < k; ++t) {
        pair<ll, ll> mins = make_pair(INT_MAX, INT_MAX);
        pair<ll, ll> maxs = make_pair(-1, -1);

        for(ll i = 0; i < n; ++i) {
            if(mins.first > a[i]) {
                mins.first = a[i];
                mins.second = i;
            }

            if(maxs.first < a[i]) {
                maxs.first = a[i];
                maxs.second = i;
            }
        }
        if(maxs.first == mins.first) break;
        a[maxs.second]--;
        a[mins.second]++;
        ans.push_back(make_pair(maxs.second + 1, mins.second + 1));
    }

    sort(a, a + n);

    printf("%lld %lld\n", a[n - 1] - a[0], (ll)ans.size());
    for(ll i = 0; i < ans.size(); ++i) printf("%lld %lld\n", ans[i].first, ans[i].second);

    return 0;
}