#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
char res[4][107];

int main() {
    scanf("%lld", &n);

    if(n%2 == 0) {
        for(ll i = 1; i <= n/2; ++i) {
            if(i%2 == 0) printf("aa");
            else printf("bb");
        }
        printf("\ny");
        for(ll i = 1; i < n/2; ++i) {
            if(i%2 == 0) printf("cc");
            else printf("dd");
        }
        printf("x\ny");
        for(ll i = 1; i < n/2; ++i) {
            if(i%2 == 0) printf("ee");
            else printf("ff");
        }
        printf("x\n");
        for(ll i = 1; i <= n/2; ++i) {
            if(i%2 == 0) printf("gg");
            else printf("hh");
        }
    } else {
        for(ll i = 1; i <= n/2; ++i) {
            if(i%2 == 0) printf("aa");
            else printf("bb");
        }
        printf("y\n");
        for(ll i = 1; i <= n/2; ++i) {
            if(i%2 == 0) printf("cc");
            else printf("dd");
        }
        printf("y\nx");
        for(ll i = 1; i <= n/2; ++i) {
            if(i%2 == 0) printf("ee");
            else printf("ff");
        }
        printf("\nx");
        for(ll i = 1; i <= n/2; ++i) {
            if(i%2 == 0) printf("gg");
            else printf("hh");
        }

    }
    return 0;
}