#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    if(a + b + c >= 22) cout << "bust\n";
    else cout << "win\n";
}