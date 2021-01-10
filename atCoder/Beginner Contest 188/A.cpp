
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y;
    cout << (min(x, y) + 3 > max(x, y) ? "Yes\n": "No\n");
    return 0;
}