#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, c, k;

int main() {
    cin >> a >> b >> c >> k;
    if(k <= a) cout << k << endl;
    else if(k <= a + b) cout << a << endl;
    else cout << a - min(c, (k - (a + b))) << endl;

    return 0;
}