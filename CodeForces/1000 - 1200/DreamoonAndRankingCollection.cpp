#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, x, temp;
vector<bool> nums(205);

int main() {

    scanf("%lld", &t);

    while(t--) {
        fill(nums.begin(), nums.end(), 0);

        ll ans, count = 0;

        scanf("%lld %lld", &n, &x);

        for(ll i = 0; i < n; ++i) {
            scanf("%lld", &temp);
            nums[temp] = 1;
        }

        for(ll i = 1; i <= n + x; ++i) {
            if(nums[i]) count++;
            if(count + x >= i) ans = i;
        }

        printf("%lld\n", ans);

    }
}