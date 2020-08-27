#include <bits/stdc++.h>

using namespace std;

#define s(n) fin >> n;

int main() {

    int n, k, berry[1005], b[10005];

    ifstream fin;

    ofstream fout;

    fin.open("berries.in");

    fout.open("berries.out");

    s(n);

    s(k);

    for(int i = 0; i < n; ++i) {

        s(berry[i]);

    }

    sort(berry, berry + n, greater<int>());

    for(int i = 0; i < k; ++i) {

        b[i] = berry[i];

    }

    for(int i = 0; i < k; ++i) {

        if(b[i]/2 >= b[(k/2)]) b[k - 1] = b[i]/2;

        sort(b, b + k, greater<int>());

    }

    int sum = 0;

    for(int i = k - 1; i >= floor(k/2); i--) {

        sum += b[i];

    }

    fout << sum << endl;

    fin.close();

    fout.close();

}