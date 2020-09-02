#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a, b, c;

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        if(b == 0) {
            if(a) {
                cout << string(a + 1, '0') << endl;
            } 
            if(c) {
                cout << string(c + 1, '1') << endl;
            }
            continue;
        }
        string ans = "";
        for(ll i = 0; i < b + 1; ++i) {
            if(i%2 == 0) ans += '1';
            else ans += '0';
        }

        ans.insert(1, string(a, '0'));
        ans.insert(0, string(c, '1'));

        cout << ans << endl;
    }

    return 0;
}