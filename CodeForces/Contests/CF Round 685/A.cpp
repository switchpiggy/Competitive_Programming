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
        if(n == 1) cout << 0 << '\n';
        else if(n == 2) cout << 1 << '\n';
        else if(n%2 == 0) {
            cout << min(n - 1, 2ll) << '\n';
        } else cout << min(n - 1, 3ll) << '\n';
    }

    return 0;
}