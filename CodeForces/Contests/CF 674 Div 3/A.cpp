#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, t, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> x;
        if(n <= 2) {
            cout << 1 << '\n';
            continue;
        }

        n -= 2;
        cout << 1 + (n + x - 1)/x << '\n';
    }

    return 0;
}