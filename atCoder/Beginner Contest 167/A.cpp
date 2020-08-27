#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s, t;

int main() {
    cin >> s >> t;
    if(s.length() == t.length() - 1 && t.substr(0, t.length() - 1) == s) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}