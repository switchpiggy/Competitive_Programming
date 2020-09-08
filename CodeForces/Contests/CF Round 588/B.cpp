#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> s;

    if(!k) {
        cout << s << endl;
        return 0;
    }

    if(n == 1) {
        cout << 0 << endl;
        return 0;
    }

    if(s[0] > '1') {
        s[0] = '1';
        k--;
    }

    for(ll i = 1; i < s.length(); ++i) {
        if(!k) break;
        if(s[i] > '0') {
            k--;
            s[i] = '0';
        }
    }

    cout << s << endl;
    return 0;
}