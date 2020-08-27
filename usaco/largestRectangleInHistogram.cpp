#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007];
stack<ll> s;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);

    ll maxn = 0, i = 0;

    while(i < n) {
        if(s.empty() || a[i] >= a[s.top()]) s.push(i++);
        else {
            ll t = s.top();
            s.pop();
            if(!s.empty()) maxn = max(maxn, (i - s.top() - 1) * a[t]);
            else maxn = max(maxn, a[t] * i);
        }
    }

    while(!s.empty()) {
        ll t = s.top();
        s.pop();
        if(!s.empty()) maxn = max(maxn, (i - s.top() - 1) * a[t]); 
        else maxn = max(maxn, a[t] * i);
    }

    printf("%lld\n", maxn);

    return 0;
}