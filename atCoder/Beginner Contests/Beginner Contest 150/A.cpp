#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll k, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> x;
    cout << ((k * 500 >= x) ? "Yes\n" : "No\n");
    return 0;
}