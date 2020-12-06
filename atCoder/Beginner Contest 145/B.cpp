#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    if(n%2 == 0 && s.substr(0, n/2) == s.substr(n/2)) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}