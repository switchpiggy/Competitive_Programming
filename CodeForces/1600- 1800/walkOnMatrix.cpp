#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    cout << "2 3\n";
    cout << (1 << 17) + k << ' ' << (1 << 17) << ' ' << 0 << '\n';
    cout << k << ' ' << (1 << 17) + k << ' ' << k << '\n';
    return 0;
}