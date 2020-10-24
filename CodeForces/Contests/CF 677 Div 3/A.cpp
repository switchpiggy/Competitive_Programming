#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> s;
        ll n = (ll)s.length();

        if(s[0] == '1') {
            cout << (n * (n + 1))/2 << '\n';
            continue;
        }

        cout << 10 * (s[0] - '0' - 1) + (n * (n + 1))/2 << '\n';
    }

    return 0;
}