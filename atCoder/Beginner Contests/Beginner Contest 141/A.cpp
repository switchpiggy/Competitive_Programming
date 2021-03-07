#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    if(s == "Sunny") cout << "Cloudy\n";
    else if(s == "Cloudy") cout << "Rainy\n";
    else cout << "Sunny\n";
    return 0;
}