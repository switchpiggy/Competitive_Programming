#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x >> y;
    if(abs(x - y) + min(x - 1, y - 1) <= abs(y - x) + min(n - x, n - y)) cout << "White\n";
    else cout << "Black\n";
    return 0;
}