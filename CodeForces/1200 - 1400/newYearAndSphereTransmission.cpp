#include <bits/stdc++.h>
using namespace std;

//Come back to this later to study. I don't know the full solution yet.

typedef long long int ll;
ll n;

int main() {
    scanf("%lld", &n);
    vector<ll> res;
    for(ll i = 1; i * i <= n; ++i) {
        if(n%i == 0) {
            res.push_back((n * (i - 1)/2) + i);
            if(i != n/i) {
                res.push_back((n * (n/i - 1)/2) + n/i);
            }
        }
    }

    sort(res.begin(), res.end());

    for(ll i = 0; i < res.size(); ++i) {
        printf("%lld ", res[i]);
    }
    printf("\n");
    return 0;
}