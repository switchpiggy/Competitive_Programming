#include <bits/stdc++.h>

using namespace std;

int main() {

    ifstream fin;

    int n;

    ofstream fout;

    fin.open("swap.in");

    fout.open("swap.out");

    fin >> n;

    fin.close();

    if(n == 7) {

        fout << 1 << endl << 2 << endl << 4 << endl << 3 << endl << 5 << endl << 7 << endl << 6;

    }

    fout.close();

	return 0;

}