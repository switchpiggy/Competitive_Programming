#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(i%2 == 0 && s[i] != 'R' && s[i] != 'U' && s[i] != 'D') {
            cout << "No\n";
            return 0;
        }

        if(i%2 == 1 && s[i] != 'L' && s[i] != 'U' && s[i] != 'D') {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    return 0;
}