#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    cin >> n;

    ll res = 0;
    for(ll i = 1; i <= n; ++i) {
        if(i%3 != 0 && i%5 != 0) res += i;
    }

    cout << res << endl;

    return 0;
}