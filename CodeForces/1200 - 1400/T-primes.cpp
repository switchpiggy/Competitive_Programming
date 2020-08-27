#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, i;

//Easy Prime check: iterate through all numbers between 2 and sqrt(x) (x is the number we find out to be prime or not) and see if it divides into x. If need for faster algorithm, use sieve of Erasthones

int main() {
    scanf("%lld", &n);
    
    while(n--) {
        scanf("%lld", &x);

        ll y = sqrt(x);
        for(i = 2; i * i <= y; ++i) {
            if(y%i == 0) break;
        }
        if(i * i > y && y * y == x && x > 1) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}