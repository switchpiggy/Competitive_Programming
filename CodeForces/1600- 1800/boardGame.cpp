#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c >> d;
    if((a <= c && b <= d) || (a + b <= max(c, d))) cout << "Polycarp\n";
    else cout << "Vasiliy\n";

    return 0;
}