#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[1007], x = 0, y = 0;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);
    
    for(ll i = 0; i < n; ++i) {
        if(i < n - 1 && a[i] > a[i + 1]) {
            ll j = i;
            while(j < n - 1 && a[j] > a[j + 1]) j++;
            reverse(a + i, a + j + 1);
            x = i + 1;
            y = j + 1;
            break;
        }
    }

    for(ll i = 0; i < n - 1; ++i) {
    	//cout << a[i] << ' ';
        if(a[i] > a[i + 1]) {
            printf("0 0\n");
            return 0;
        }
    }

    printf("%lld %lld\n", x, y);
    return 0;
}