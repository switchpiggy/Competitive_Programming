#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, c;
set<ll> s;

int main() {
    scanf("%lld %lld", &n, &m);
    for(ll i = 0; i < m; ++i) {
        scanf("%lld", &c);
        s.clear();

        bool flag = false;

        for(ll j = 0; j < c; ++j) {
            ll temp;
            scanf("%lld", &temp);
            if(s.count(temp * -1)) flag = 1;
            s.insert(temp);
        }

        if(!flag) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");

    return 0;
}