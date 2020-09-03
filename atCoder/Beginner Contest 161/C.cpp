#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k;

int main() {
    cin >> n >> k;
    cout << min(n%k, k - n%k) << endl;
    return 0;
}