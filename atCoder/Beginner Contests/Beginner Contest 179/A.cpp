#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    if(s.back() == 's') {
        cout << s << "es" << '\n';
    } else cout << s << "s" << '\n';

    return 0;
}