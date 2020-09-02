#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll q, n, out[200007];
bool curved[200007];
string s, t;

int main() {
    cin >> q;
    while(q--) {
        cin >> n >> s >> t;
        memset(out, 0, sizeof(out));

        for(ll i = 1; i <= n; ++i) {
            if(s[i - 1] == '1' || s[i - 1] == '2' || t[i - 1] == '1' || t[i - 1] == '2') curved[i] = 0;
            else curved[i] = 1;
        }

        if((s[0] == '4' || s[0] == '3' || s[0] == '5' || s[0] == '6') && (t[0] == '1' || t[0] == '2')) {
            cout << "NO" << endl;
            continue;
        }

        if(!curved[1]) out[1] = 1;
        else out[1] = 2;
        bool ok = 1;

        for(ll i = 2; i <= n; ++i) {
            if(out[i - 1] == 1 && !curved[i] && (s[i - 1] == '3' || s[i - 1] == '4' || s[i - 1] == '5' || s[i - 1] == '6')) {
                ok = 0;
                break;
            }

            if(out[i - 1] == 2 && !curved[i] && (t[i - 1] == '3' || t[i - 1] == '4' || t[i - 1] == '5' || t[i - 1] == '6')) {
                ok = 0;
                break;
            }

            if(curved[i]) out[i] = 3 - out[i - 1];
            else out[i] = out[i - 1];
        }

        if(out[n] == 2 && ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}