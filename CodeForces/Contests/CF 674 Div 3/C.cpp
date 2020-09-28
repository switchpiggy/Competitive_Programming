#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        ll s = sqrt(n);

        cout << s + (n + s - 1)/s - 2 << '\n';
    }

    return 0;
}