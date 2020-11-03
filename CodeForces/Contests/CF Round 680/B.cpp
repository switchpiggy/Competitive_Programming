#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a, b, c, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d;
        cout << max(a + b, c + d) << '\n';
    }

    return 0;
}