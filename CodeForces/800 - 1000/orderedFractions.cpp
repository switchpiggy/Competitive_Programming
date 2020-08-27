/*
ID: alanxia1
TASK: frac1
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll n;

void getFrac(ll n1, ll d1, ll n2, ll d2) {
    if(d1 + d2 > n) return;
    	
    getFrac(n1, d1, n1 + n2, d1 + d2);
    
    printf("%lld/%lld\n", n1 + n2, d1 + d2);
    
    getFrac(n1 + n2, d1 + d2, n2, d2);
}

int main() {
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    scanf("%lld", &n);

    printf("0/1\n");

    getFrac(0, 1, 1, 1);

    printf("1/1\n");
}