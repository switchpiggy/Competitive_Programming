#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;
map<char, ll> occ;

int main() {
    cin >> n >> s;

    sort(s.begin(), s.end());

    cout << s << endl;

    return 0;
}