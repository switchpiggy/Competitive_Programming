/*
ID: alanxia1
PROG: skidesign
LANG: C++
*/


#include <bits/stdc++.h>

using namespace std;

int n, h[1005];

int main() {

    ifstream fin;

    ofstream fout;

    fin.open("skidesign.in");

    fout.open("skidesign.out");

    fin >> n;
    for(int i=0; i<n; ++i) fin >> h[i];
    sort(h, h + n);

    fin.close();

    long long int mins = 1000000000;

    for(int i = 1; i <= 83; ++i) {

        long long int count = 0;
        
        for(int j = 0; j < n; ++j) {
            if(h[j] < i) count += (i - h[j]) * (i - h[j]);
            else if(h[j] > i + 17) count += (h[j] - (i + 17)) * (h[j] - (i + 17));
            else count += 0;
        }

        mins = min(count, mins);

    }

    fout << mins << endl;

    fout.close();

    return 0;

}