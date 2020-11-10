#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    string t;
    for(ll i = ((ll)s.length() + 1)/2 - 1; i < (ll)s.length(); ++i) {
        t += s[i];
        if(i != ((ll)s.length() + 1)/2 - 1 && !((ll)s.length()%2 == 0 && i == (ll)s.length() - 1)) t.push_back(s[((ll)s.length() + 1)/2 - 1 - (i - (((ll)s.length() + 1)/2 - 1))]);
        //cout << t << ' ';

    } 

    cout << t << '\n';
    return 0;
}