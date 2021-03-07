#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    if(s == "MON") cout << 6 << '\n';
    if(s == "TUE") cout << 5 << '\n';
    if(s == "WED") cout << 4 << '\n';
    if(s == "THU") cout << 3 << '\n';
    if(s == "FRI") cout << 2 << '\n';
    if(s == "SAT") cout << 1 << '\n';
    if(s == "SUN") cout << 7 << '\n';
    return 0;
}