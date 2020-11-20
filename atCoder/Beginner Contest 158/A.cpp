#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for(ll i = 0; i < (ll)s.length() - 1; ++i) {
        if(s[i] != s[i + 1]) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}