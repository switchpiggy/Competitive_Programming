#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[107];
bool dp[100007];

int main() {
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for(ll i = 1; i <= k; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(i - a[j] >= 0) dp[i] |= !dp[i - a[j]];
        }
    }

    if(dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
    
    return 0;
}