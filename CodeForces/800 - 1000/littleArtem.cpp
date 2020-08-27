#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m;

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld %lld", &n, &m);
        for(ll i = 0; i < n; ++i) {
            for(ll j = 0; j < m; ++j) {
                if(i == 0 && j == 0) printf("W");
                else printf("B");
            }
            printf("\n");
        }
    }
}