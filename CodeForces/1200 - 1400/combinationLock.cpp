/*
 ID: alanxia1
 PROG: combo
 LANG: C++
 */
#include <bits/stdc++.h>

using namespace std;

void print(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

bool close(int a, int b, int n) {
    if (abs(a-b) <= 2) return true;
    if (abs(a-b) >= n-2) return true;
    return false;
}

bool close_enough(int n1, int n2, int n3,
                  int c1, int c2, int c3, int n) {
    return close(n1,c1,n) && close(n2,c2,n) && close(n3,c3,n);
}

ifstream fin;

ofstream fout;

int main() {

    fin.open("combo.in");

    fout.open("combo.out");

    int n, temp;
    fin >> n;

    vector<int> key, master;
    for (int i = 0; i < 3; i++) {
        fin >> temp;
        key.push_back(temp);
    }
    for (int i = 0; i < 3; i++) {
        fin >> temp;
        master.push_back(temp);
    }

    fin.close();

    // what I did originally
    set<std::vector<int>> s;
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            for (int k = -2; k <= 2; k++) {
                int a = (key[0]+i)%n, b = (key[1]+j)%n, c = (key[2]+k)%n;
                if (a <= 0) { a += n; }
                if (b <= 0) { b += n; }
                if (c <= 0) { c += n; }
                s.insert({a, b, c});

                a = (master[0]+i)%n, b = (master[1]+j)%n, c = (master[2]+k)%n;
                if (a <= 0) { a += n; }
                if (b <= 0) { b += n; }
                if (c <= 0) { c += n; }
                s.insert({a, b, c});
            }
        }
    }

    // simpler idea is, official solution
    int total = 0;
    for (int n1=1; n1<=n; n1++) {
        for (int n2=1; n2<=n; n2++) {
            for (int n3=1; n3<=n; n3++) {
                if (close_enough(n1,n2,n3,key[0],key[1],key[2],n) ||
                    close_enough(n1,n2,n3,master[0],master[1],master[2],n))
                    total++;
            }
        }
    }
    fout << total << endl;
    //printf("%ld\n", s.size());
    return 0;
}