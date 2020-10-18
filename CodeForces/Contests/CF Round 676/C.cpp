#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    cout << 3 << '\n';
    cout << "L 2\nR 2\nR ";
    cout << 2 * (ll)s.length() - 1 << '\n';

    return 0;
}