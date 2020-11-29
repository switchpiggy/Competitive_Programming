#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll h, a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> a;
    cout << (h + a - 1)/a << '\n';
    return 0;
}