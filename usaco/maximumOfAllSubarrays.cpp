#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[100007];
deque<ll> q;

int main() {
    scanf("%lld %lld", &n, &k);
    for(ll i = 0; i < n; ++i) scanf("%lld", &a[i]);

    ll i;

    for(i = 0; i < k; ++i) {
        while(!q.empty() && a[i] >= a[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    for(; i < n; ++i) {
        printf("%lld ", a[q.front()]);
        while(!q.empty() && q.front() <= i - k) q.pop_front();

        while(!q.empty() && a[i] >= a[q.back()]) q.pop_back();

        q.push_back(i);
    }

    printf("%lld", a[q.front()]);
    
    return 0;
}