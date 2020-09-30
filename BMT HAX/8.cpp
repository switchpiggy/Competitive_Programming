#include <bits/stdc++.h>
using namespace std;

typedef long double ll;
ll dp[3000];

ll f(long long int x) {
    if(x == 1) return 2017.0;
    if(dp[x]) return dp[x];

    ll res = 0;
    for(ll i = 1; i < x; ++i) res += f(i);

    // x^2 - 1 * f(x) = res
    //x^2 * f(x) = sigma(1 , n) f(i)

    dp[x] = res/((x + 1.0) * (x - 1.0));

    return dp[x];
}

int main() {
    dp[1] = 2017.0;
    cout << f(2017) << '\n';
    return 0;
}