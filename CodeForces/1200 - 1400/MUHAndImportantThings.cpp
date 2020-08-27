#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<pair<ll, ll>> h, swaps;

int main() {
    scanf("%lld", &n);
    for(ll i = 1; i <= n; ++i) {
        ll temp;
        scanf("%lld", &temp);
        h.push_back(make_pair(temp, i));
    }
    
    sort(h.begin(), h.end());

    for(ll i = 0; i < h.size() - 1; ++i) {
        if(h[i].first == h[i + 1].first) swaps.push_back(make_pair(i, i + 1));
    }

    if(swaps.size() < 2) {
        printf("NO\n");
        return 0;
    }
    
	printf("YES\n");
    for(ll i = 0; i < h.size(); ++i) printf("%lld ", h[i].second);
    printf("\n");
    swap(h[swaps[0].first], h[swaps[0].second]);

    for(ll i = 0; i < h.size(); ++i) printf("%lld ", h[i].second);
    printf("\n");
    swap(h[swaps[1].first], h[swaps[1].second]);

    for(ll i = 0; i < h.size(); ++i) printf("%lld ", h[i].second);
    printf("\n");

    return 0;
}