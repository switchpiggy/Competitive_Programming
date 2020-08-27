#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, arr[1007];

int main() {
    scanf("%lld", &t);

    while(t--) {
        scanf("%lld", &n);
        for(ll i = 0; i < n; ++i) scanf("%lld", &arr[i]);

        ll alice = 0, bob = 0, prev = 0, a = 0, b = n - 1, step = 0;

        while(a <= b) {
            step++;
            ll cur = 0;
            if(step%2 == 1) {
                while(cur <= prev && a <= b) {
                    cur += arr[a];
                    a++;
                }
                alice += cur;
            } else {
                while(cur <= prev && b >= a) {
                    cur += arr[b];
                    b--;
                }
                bob += cur;
            }
            prev = cur;
        } 

        printf("%lld %lld %lld\n", step, alice, bob);  
    }
}