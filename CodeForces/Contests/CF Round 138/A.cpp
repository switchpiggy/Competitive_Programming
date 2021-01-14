#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll a, b, c;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    cout << 4 * ((ll)sqrt((a * c)/b) + (ll)sqrt((a * b)/c) + (ll)sqrt((b * c)/a)) << '\n';
    return 0;
}