#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string a, b;

string mins(string x) {
    if((ll)x.length()%2 == 1) return x;
    string a = mins(x.substr(0, (ll)x.length()/2)), b = mins(x.substr((ll)x.length()/2));
    if(a < b) return a + b;
    return b + a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    cout << ((mins(a) == mins(b)) ? "YES\n" : "NO\n");
    return 0;
}