#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, t;
string dir;

int main() {
    scanf("%lld", &n);

    ll v = 0, h = 0;

    for(ll q = 0; q < n; ++q) {
        cin >> t >> dir;
        if(dir == "South") {
            v += t;
            if(v > 20000) {
                printf("NO\n");
                return 0;
            }
        } else if(dir == "North") {
            v -= t;
            if(v < 0) {
                printf("NO\n");
                return 0;
            }
        } else if(v == 0 || v == 20000) {
            printf("NO\n");
            return 0;
        }
    }

    if(v) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
}