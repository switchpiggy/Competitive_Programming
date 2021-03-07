#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    if((a == b && b != c) || (a == c && b != c) || (b == c && a != c)) {
        cout << "Yes\n";
    } else cout << "No\n";

    return 0;
}