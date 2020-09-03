#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    cin >> n;
    if(n * (n + 1) > 1000000000 || n <= 1) {
        cout << "-1" << endl;
        return 0;
    }

    cout << n << ' ' << n + 1 << ' ' << n * (n + 1) << endl;
    return 0;
}