#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c, d;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c >> d;
    ll misha = max((3 * a)/10, a - (a/250) * c), vasya = max((3 * b)/10, b - (b/250) * d);

    if(misha > vasya) cout << "Misha\n";
    else if(misha == vasya) cout << "Tie\n";
    else cout << "Vasya\n";

    return 0;
}