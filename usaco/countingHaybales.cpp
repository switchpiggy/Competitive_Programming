#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q;
vector<ll> h;

int main() {
    scanf("%lld %lld", &n, &q);
    h.clear();
    for(ll i = 0; i < n; ++i) {
    	ll a;
        scanf("%lld", &a);
        h.push_back(a);
    }

    sort(h.begin(), h.end());

    for(ll i = 0; i < q; ++i) {
        ll a, b;
        scanf("%lld %lld", &a, &b);

        ll l = lower_bound(h.begin(), h.end(), a) - h.begin(), r = lower_bound(h.begin(), h.end(), b) - h.begin();
        ll res = r - l + 1;
        if(h[r] > b || r >= (ll)h.size()) res--;
        
        //cout << l << ' ' << r << endl;

        printf("%lld\n", res);
    }

    return 0;
}