#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    reverse(s.begin(), s.end());

    if((s[0] - '0')%2 == 0) cout << 0 << '\n';
    else cout << 1 << '\n';
    return 0;
}