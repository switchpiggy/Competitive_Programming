#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, t;

int main() {
    cin >> n >> x >> t;
    cout << ((n + x - 1)/x) * t << endl;
}