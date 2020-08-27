#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

bool checkPrime(ll x) {
    for(ll i = 2; i <= sqrt(x); ++i) {
        if(x%i == 0) return 0;
    }

    return 1;
}

int main() {
    scanf("%lld", &t);

    while(t--) {
        scanf("%lld", &n);

        if(n == 1) {
            printf("FastestFinger\n");
            continue;
        }

        if(n%2 == 0 && n > 2) {
            if(n == (n & (~(n - 1))) || (n%4 && checkPrime(n/2))) {
                printf("FastestFinger\n");
                continue;
            } 
        }

        printf("Ashishgup\n");
        
    }

    return 0;
}