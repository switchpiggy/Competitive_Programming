#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define benq queue
#define pbenq priority_queue
#define all(x) (x.begin(), x.end())
ll a, b;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> s;
    ll x = 0, y = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == 'R') x++;
        else if(s[i] == 'L') x--;
        else if(s[i] == 'U') y++;
        else y--;
    }
    
    if((((x == 0 && a == x) || (x != 0 && abs(a)%abs(x) == 0 && a/x >= 0))) && ((y == 0 && b == y) || (y != 0 && abs(b)%abs(y) == 0 && b/y >= 0)) && ((x == 0 || y == 0) || a/x == b/y)) {
        cout << "Yes\n";
        return 0;
    }

    ll curx = 0, cury = 0;
    for(ll i = 0; i < (ll)s.length(); ++i) {
        if(s[i] == 'R') curx++;
        else if(s[i] == 'L') curx--;
        else if(s[i] == 'U') cury++;
        else cury--;

        ll aa = a - curx, bb = b - cury;
        if((((x == 0 && aa == x) || (x != 0 && abs(aa)%abs(x) == 0 && aa/x >= 0))) && ((y == 0 && bb == y) || (y != 0 && abs(bb)%abs(y) == 0 && bb/y >= 0)) && ((x == 0 || y == 0) || aa/x == bb/y)) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}