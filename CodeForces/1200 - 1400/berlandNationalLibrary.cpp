#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
map<ll, bool> cur;

int main() {
	ll n, temp;
	char c;
	ll distinct = 0, ans = 0;
	
    scanf("%lld", &n);

    for(ll i = 0; i < n; ++i) {
    	cin >> c >> temp;
        if(c == '-') {
            if(!cur[temp]) ans++;
            else {
            	cur[temp] = 0;
            	distinct--;
            }
        } else {
            cur[temp] = 1;
            distinct++;
        }
        
        ans = max(ans, distinct);
    }

    printf("%lld\n", ans);

    return 0;
}