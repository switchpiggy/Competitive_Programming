#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if(n%2 == 0) {
        cout << n/2 << '\n';
        return 0;
    }

    for(ll i = 2; i * i <= n; ++i) {
        if(n%i == 0) {
            cout << 1 + (n - i)/2 << '\n';
            return 0;
        }
    }

    cout << 1 << '\n';
    return 0;
}