#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if(n%2 == 1) cout << "black\n";
    else cout << "white\n1 2\n";

    return 0;
}