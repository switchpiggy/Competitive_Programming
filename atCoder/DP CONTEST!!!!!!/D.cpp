#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, w, dp[100007];

int main() {
    cin >> n >> w;
    for(ll i = 0; i < n; ++i) {
        ll weight, value;
        cin >> weight >> value;

        for(ll j = w - weight; j >= 0; --j) {
            dp[j + weight] = max(dp[j + weight], dp[j] + value); 
        }
    }

    cout << dp[w] << endl;
    return 0;
}