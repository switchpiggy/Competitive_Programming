#include <bits/stdc++.h>

using namespace std;

int main() {

    int a, b, c;

    cin >> a >> b >> c;

    printf("%d\n", max(a, max(b, c)) - min(a, min(b, c)));

}