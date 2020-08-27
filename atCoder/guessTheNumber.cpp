#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a, b, digits[10];

int main() {
    cin >> n >> m;

    memset(digits, -1, sizeof(digits));

    for(ll i = 0; i < m; ++i) {
        cin >> a >> b;
        //cout << a << ' ' << b << endl;
        if(digits[a - 1] != -1 && digits[a - 1] != b) {
            cout << "-1" << endl;
            return 0;
        }

        if(a == 1 && b == 0 && n > 1) {
            cout << "-1" << endl;
            return 0;
        }

        digits[a - 1] = b;
        //cout << digits[a - 1] << endl;
    }

    if(digits[0] == -1 && n > 1) digits[0] = 1;

    for(ll i = 0; i < n; ++i) {
        if(digits[i] == -1) digits[i] = 0;
    }

    for(ll i = 0; i < n; ++i) cout << digits[i];
    return 0;
}