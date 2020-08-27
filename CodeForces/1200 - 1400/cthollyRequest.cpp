#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll k, p;

ll getAns(ll x) {
    vector<ll> digits;
    while(x) {
        digits.push_back(x%10);
        x /= 10;
    }

    reverse(digits.begin(), digits.end());
    for(ll i = digits.size() - 1; i >= 0; --i) {
        digits.push_back(digits[i]);
    }

    ll ans = 0;
    for(ll i = 0; i < digits.size(); ++i) {
        ans = (ans * 10 + digits[i]) % p;
    }

    return ans;
}

int main() {
    scanf("%lld %lld", &k, &p);
    ll sum = 0;

    for(ll i = 1; i <= k; ++i) {
        sum = (sum + getAns(i)) % p;
        sum %= p;
    }

    printf("%lld\n", sum%p);

    return 0;
}