#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    cin >> s;   
    if(s.size() == 1) {
        cout << s << endl;
        return 0;
    }
    for(ll i = s.length() - 2; i >= 0; --i) if(s[i] == s[i + 1]) s.erase(i, 2);

    cout << s << endl;

    return 0;
}