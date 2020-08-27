#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c, d;

int main() {
    cin >> a >> b >> c >> d;
    while(a > 0 && c > 0) {
        a -= d;
        c -= b;
    }

    if(a <= 0 && c <= 0) cout << "Yes" << endl;
    else if(a <= 0) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}