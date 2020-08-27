#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<ll> v;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        ll temp;
        scanf("%lld", &temp);
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    swap(v[0], v[n - 1]);

    for(ll i = 0; i < n; ++i) printf("%lld ", v[i]);

    return 0;
}