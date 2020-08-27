/*
ID: alanxia1
PROG: sprime
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll n;

bool primeCheck(ll x) {

    if(x == 2) return true;
    if(x == 1) return false;
    if(x%2 == 0) return false;
    for(ll i = 3; i * i <= x; ++i) {
        if(x%i == 0) return false;
    }

    return true;

}

void superPrime(ll digitsLeft, ll num) {
    if(digitsLeft == 0) {
        printf("%lld\n", num);
        return;
    }

    num *= 10;

    if(primeCheck(num + 1)) superPrime(digitsLeft - 1, num + 1);
    if(primeCheck(num + 3)) superPrime(digitsLeft - 1, num + 3);
    if(primeCheck(num + 7)) superPrime(digitsLeft - 1, num + 7);
    if(primeCheck(num + 9)) superPrime(digitsLeft - 1, num + 9);

    return;
}

int main() {

    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);

    scanf("%lld", &n);

    superPrime(n - 1, 2);
    superPrime(n - 1, 3);
    superPrime(n - 1, 5);
    superPrime(n - 1, 7);

    return 0;
}