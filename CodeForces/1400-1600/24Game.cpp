#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    cin >> n;
    if(n < 4) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    if(n%2 == 0) {
        cout << "1 * 2 = 2\n2 * 3 = 6\n4 * 6 = 24\n";
        for(ll i = 5; i + 1 <= n; i += 2) {
            cout << i + 1 << " - " << i << " = 1" << '\n';
            cout << "1 * 24 = 24" << '\n';
        }
    } else {
        cout << "2 - 1 = 1\n1 + 3 = 4\n4 * 5 = 20\n20 + 4 = 24\n";
        for(ll i = 6; i + 1 <= n; i += 2) {
            cout << i + 1 << " - " << i << " = 1" << '\n';
            cout << "1 * 24 = 24" << '\n';
        }
    }

    return 0;
}