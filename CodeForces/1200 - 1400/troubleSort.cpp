#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main() {
	ll t;
	
    scanf("%lld", &t);

    while(t--) {
    	bool zero = 0, one = 0, sorted = 1;
    	ll n, a[505], b[505];
    	
        scanf("%lld", &n);
        for(ll i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
            if(i >= 1 && a[i] < a[i - 1]) sorted = 0;
        }
        for(ll i = 0; i < n; ++i) {
            scanf("%lld", &b[i]);
            if(b[i]) one = 1;
            else zero = 1;
        }

        if((zero && one) || (sorted)) printf("YES\n");
        else printf("NO\n");
    }
}