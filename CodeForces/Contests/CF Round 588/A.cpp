#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c >> d;

    if((a + b == c + d) || (a + c == b + d) || (a + d == b + c) || (a + b + c == d) || (a + b + d == c) || (a + c + d == b) || (b + c + d == a)) {
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}