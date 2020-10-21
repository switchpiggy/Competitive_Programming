#include <bits/stdc++.h>
using namespace std;

int n, w, k;

int main() {
    //w 
    //k, 2k ,3k ,4k
    //(1 + 2 + 3 + 4.. w) * k

    cin >> k >> n >> w;
    cout << max(0, (w * (w + 1) * k)/2 - n) << '\n';
    return 0;
}