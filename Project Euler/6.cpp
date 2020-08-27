#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        cout << abs((n * n * (n + 1) * (n + 1))/4 - (n * (n + 1) * (2 * n + 1))/6) << endl;
    }

    return 0;
}