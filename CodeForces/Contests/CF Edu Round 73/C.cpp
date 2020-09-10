#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        ll mins = min(a, b);

        cout << min(mins, (a + b + c)/3) << '\n';
    }

    return 0;
}