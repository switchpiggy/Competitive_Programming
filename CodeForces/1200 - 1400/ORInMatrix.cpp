#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll m, n, temp, a[107][107], b[107][107];

int main() {
    scanf("%lld %lld", &m, &n);

    for(ll i = 0; i < m; ++i) {
        for(ll j = 0; j < n; ++j) {
            scanf("%lld", &a[i][j]);
        }
    }

    for(ll i = 0; i < m; ++i) {
        for(ll j = 0; j < n; ++j) {
            bool flag = 1;
            for(ll k = 0; k < m; ++k) if(!a[k][j]) flag = 0;
            for(ll k = 0; k < n; ++k) if(!a[i][k]) flag = 0;
            if(flag) b[i][j] = 1;
        }
    }

    for(ll i = 0; i < m; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(b[i][j]) {
                for(ll k = 0; k < m; ++k) a[k][j] = 0;
                for(ll k = 0; k < n; ++k) a[i][k] = 0;
            }
        }
    }

    for(ll i = 0; i < m; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(a[i][j]) {
                printf("NO\n");
                return 0;
            }
        }
    }
	printf("YES\n");
    for(ll i = 0; i < m; ++i) {
        for(ll j = 0; j < n; ++j) printf("%lld ", b[i][j]);
        printf("\n");
    }

    
}