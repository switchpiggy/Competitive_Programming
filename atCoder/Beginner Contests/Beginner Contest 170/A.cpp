#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ll i = 1;
    while(cin >> n) {
        if(n == 0) {
            printf("%lld\n", i);
            return 0;
        }

        i++;
    }

    return 0;
}