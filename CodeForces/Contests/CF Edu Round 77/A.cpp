#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, c, sum;

int main() {
    cin >> n;
    while(n--) {
        cin >> c >> sum;

        ll res = 0;
        for(ll i = 0; i < sum%c; ++i) res += (sum/c + 1) * (sum/c + 1);
        for(ll i = 0; i < c - sum%c; ++i) res += (sum/c) * (sum/c);

        cout << res << endl;
    }

    return 0;
}