#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    if(s[0] == ')' || s.back() == '(' || n == 1) {
        cout << ":(\n";
        return 0;
    }
}