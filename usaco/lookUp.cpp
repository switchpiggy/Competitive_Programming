#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, h[100007], res[100007];

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &h[i]);

    stack<ll> s;
    for(ll i = 0; i < n; ++i) {
        while(!s.empty() && h[i] > h[s.top()]) {
            res[s.top()] = i + 1;
            s.pop();
        }

        s.push(i);
    }

    for(ll i = 0; i < n; ++i) printf("%lld\n", res[i]);

    return 0;
}