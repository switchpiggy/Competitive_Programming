#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    vector<ll> v;
    ll t, n;
    scanf("%lld", &t);

    while(t--) {
        v.clear();
        scanf("%lld", &n);

        for(int i = 0; i < n; ++i) {
            ll c;
            scanf("%lld", &c);
            v.push_back(c);
        }

        sort(v.begin(), v.end(), greater<int>());
        for(int i = 0; i < n; ++i) printf("%lld ", v[i]);
        printf("\n");
    }
}