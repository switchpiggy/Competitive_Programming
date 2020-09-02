#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    cin >> n;
    if(n <= 2) {
        cout << "-1" << endl;
        return 0;
    }

    if(n%2 == 0) {
        cout << (n * n)/4 + 1 << ' ' << (n * n)/4 - 1 << endl;
    } else {
        cout << (n * n + 1)/2 << ' ' << (n * n - 1)/2 << endl;
    }

    return 0;
}