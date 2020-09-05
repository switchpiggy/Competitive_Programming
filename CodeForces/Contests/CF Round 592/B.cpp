#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> s;
        ll pos = -1, pos2 = -1;
        for(ll i = 0; i < s.length(); ++i) {
            if(s[i] == '1') pos = i;
            if(s[i] == '1' && pos2 == -1) pos2 = i;
        }

        if(pos == -1 && pos2 == -1) {
            cout << n << endl;
            continue;
        }
        
        cout << max((pos + 1) * 2, (n - pos2) * 2) << endl;
    }

    return 0;
}