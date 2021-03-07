#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c >> d;
    if(a == b + c + d || b == a + c + d || c == a + b + d || d == a + b + c || a + b == c + d || a + c == b + d || a + d == b + c ) {
        cout << "Yes\n";
    } else cout << "No\n";

    return 0;
}