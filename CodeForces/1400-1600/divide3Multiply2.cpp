#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
vector<pair<ll, ll>> a;

ll count(ll x) {
    ll res = 0;
    while(x%3 == 0) {
        res++;
        x /= 3;
    }

    return res;
}

int main() {

    scanf("%lld", &n);

    for(int i = 0; i < n; ++i) {
        ll temp;
        scanf("%lld", &temp);

        a.push_back(make_pair(-1 * count(temp), temp));
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < n; ++i) {
        printf("%lld ", a[i].second);
    }

}