#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
long double a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    if(a < b) {
        cout << "-1\n";
        return 0;
    }

    cout << fixed << setprecision(12) << (a + b)/(2. * (floor((a + b)/(2. * b)))) << '\n';
}