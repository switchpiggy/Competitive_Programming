#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

bool is(char c) {
    if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != ' ') return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    for(ll i = 0; i < (ll)s.length() - 2; ++i) {
        if(is(s[i]) && is(s[i + 1]) && is(s[i + 2]) && !(s[i] == s[i + 1] && s[i + 1] == s[i + 2] && s[i + 2] == s[i])) {
            s.insert(s.begin() + i + 2, ' ');
        }
    }

    cout << s << '\n';
    return 0;
}