#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, temp, t;
set<ll> s;

int main() {
	scanf("%lld", &t);
    while(t--) {
        s.clear();
        scanf("%lld %lld", &n, &k);
        for(ll i = 0; i < n; ++i) {
            scanf("%lld", &temp);
            s.insert(temp);
        }

        if(s.size() > k) {
            printf("-1\n");
            continue;
        }

        printf("%lld\n", n * k);

        for(ll a = 0; a < n; ++a) {
            for(auto i = s.begin(); i != s.end(); ++i) {
                printf("%lld ", *i);
            }

            for(ll i = 0; i < k - s.size(); ++i) {
                printf("1 ");
            }
        }

        printf("\n");
    }


}