#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const long double pi = 3.141592653589793238462643385028;
long double n;
ll t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(12);
    cin >> t;
    while(t--) {
        cin >> n;
        cout << cos(pi/(4 * n))/sin(pi/(2 * n)) << '\n';
    }
}