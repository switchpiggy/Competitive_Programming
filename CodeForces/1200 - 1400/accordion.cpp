#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
string s;

void remove(char c){
    auto pos = s.find(c);

    if(pos == string::npos) {
        printf("-1\n");
        exit(0);
    }

    s.erase(0, pos + 1);
}

int main() {
    cin >> s;
    remove('[');
    remove(':');
    reverse(s.begin(), s.end());
    remove(']');
    remove(':');

    printf("%d\n", count(s.begin(), s.end(), '|') + 4);
}