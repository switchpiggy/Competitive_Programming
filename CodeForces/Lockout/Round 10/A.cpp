#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    bool ok = 1;
    for(ll i = 1; i < (ll)s.length(); ++i) {
        if(!isupper(s[i])) {
            ok = 0;
            break;
        }
    }

    if(!ok) cout << s << '\n';
    else {
        for(ll i = 0; i < (ll)s.length(); ++i) {
            if(s[i] >= 'A' && s[i] <= 'Z') cout << char(s[i] - 'A' + 'a');
            else cout << char(s[i] - 'a' + 'A');
        }
    }
    return 0;
}