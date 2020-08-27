#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ll t, n;
    scanf("%lld", &t);

    while(t--) {
        vector<pair<ll, ll>> ans;
        vector<ll> even, odd;
        scanf("%lld", &n);
        
        odd.clear();
        even.clear();

        for(ll i = 0; i < n * 2; i++) {
            ll temp;
            scanf("%lld", &temp);
            //cout << temp << endl;
            if(temp%2 == 1) odd.push_back(i + 1);
            else even.push_back(i + 1);
        }

        for(ll i = 0; i < (int)even.size() - 1; i += 2) {
            ans.push_back(make_pair(even[i], even[i + 1]));
        }

        for(ll i = 0; i < (int)odd.size() - 1; i += 2) {
            ans.push_back(make_pair(odd[i], odd[i + 1]));
        }

        for(ll i = 0; i < n - 1; i++) printf("%lld %lld\n", ans[i].first, ans[i].second);

    }

    return 0;
}