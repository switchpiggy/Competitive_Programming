#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ll x, y;
    bool flag = false;
    string s;
    cin >> s;
    string t(s);

    for(ll i = 0; i < t.length()- 1; ++i) {
        if((t[i] - '0')%2 == 0 && t[i] - '0' < t[t.length() - 1] - '0') {
            swap(t[i], t[t.length() - 1]);
            cout << t << endl;
            return 0;
        }
    }
    
    for(ll i = s.length()- 1; i >= 0; i--) {
        if((s[i] - '0')%2 == 0) {
            swap(s[i], s[s.length() - 1]);
            cout << s << endl;
            return 0;
        }
    }
    
    printf("-1\n");

    return 0;
}