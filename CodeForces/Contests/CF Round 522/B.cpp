#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    if((ll)s.length() <= 20) {
        cout << 1 << ' ' << (ll)s.length() << '\n';
        cout << s << '\n';
        return 0;
    }

    ll row = (((ll)s.length() + 19)/20);
    ll col = ((ll)s.length() + row - 1)/row;
    ll it = 0;

    cout << row << ' ' << col << '\n';
    for(ll i = 0; i < row; ++i) {
        ll cur = ((row * col) - (ll)s.length())/row + (i < ((row * col) - (ll)s.length())%row);
        for(ll j = 0; j < col; ++j) {
            if(j < cur) {
                cout << '*';
                //it++;
            } else {
                cout << s[it];
                it++;
            }
        }

        cout << '\n';
    }

    return 0;
}