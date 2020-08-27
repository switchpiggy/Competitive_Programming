#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll h1, h2, a, b;

int main() {
    cin >>  h1 >> h2 >> a >> b;
    if(h1 + a * 8 >= h2) {
        cout << "0" << endl;
        return 0;
    }
    if(a <= b) {
        cout << "-1" << endl;
        return 0;
    }

    ll c = h2 - h1 - 8 * a, d = 12 * (a - b);
    cout << (c + d - 1)/d << endl;
    return 0;
}