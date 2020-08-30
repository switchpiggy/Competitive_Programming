#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    cin >> n;
    if(n == 1) cout << 10 << ' ' << 9 << endl;
    else cout << 3 * n << ' ' << 2 * n << endl;

    return 0;
}