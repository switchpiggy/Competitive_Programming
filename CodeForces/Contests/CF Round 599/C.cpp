#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
bool composite[1000001];
ll n, ans;

int main() {
    cin >> n;
    ans = n;

    for(ll i = 2; i * i <= n; ++i) {
        if(composite[i]) continue;
        ans -= n/i - 1;
        for(ll j = i * 2; j <= n; j += i) composite[j] = 1;
    }

    cout << ans << endl;
    return 0;
}