#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    string s = string(200, '9');
    s.append(string(199, '0'));
    s += '1';
    string t = string(200, '9');

    cout << s << '\n' << t << '\n';
}