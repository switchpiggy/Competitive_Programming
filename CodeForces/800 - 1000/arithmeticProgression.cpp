/*
ID: alanxia1
PROG: ariprog
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

// open files
FILE *fin = fopen ("ariprog.in", "r");
FILE *fout = fopen ("ariprog.out", "w");

// global variables
unsigned int N, M, maxMM;
unsigned int numbers [65000];
unsigned int number_size = 0;
unsigned char num_available [125001];
unsigned char dist_available [125001];
int have_res = 0;
int skipstep = 1;

// read the input

int read_input () {
    fscanf (fin, "%d %d", &N, &M);
    return 0;
}

int cmp_int (const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void asm_num (int a, int b) {
    for (unsigned int n = 1; n < N; n++)
        if (num_available [a + n * b] == 0) return;

    fprintf (fout, "%d %d\n", a, b);
    have_res ++;
    if (have_res==1)
        skipstep = b;

}

void asm_num () {
    for (unsigned int b = 1; b < maxMM; b+=skipstep) {
        if (dist_available [b]) {
            for (unsigned int p = 0; p < number_size && numbers [p] + (N -
1) * b <= maxMM; p++)
                asm_num (numbers [p], b);
        }
    }
}

int process () {
    memset (num_available, 0, sizeof (unsigned char) * 125001);
    memset (dist_available, 0, sizeof (unsigned char) * 125001);

    for (unsigned int m1 = 0; m1 <= M; m1++) {
        for (unsigned int m2 = m1; m2 <= M; m2++) {
            int n = m1 * m1 + m2 * m2;

            if (!num_available [n]) {
                num_available [n] = 1;
                numbers [number_size++] = n;
            }
        }
    }

    qsort (numbers, number_size, sizeof (unsigned int), cmp_int);

    maxMM = M * M + M * M;
    for (unsigned int n1 = 0; n1 < number_size; n1++) {
        unsigned int _n1 = numbers [n1];
        for (unsigned int n2 = n1 + 1; n2 < number_size && _n1 + (numbers
[n2] - _n1) * (N - 1) <= maxMM; n2++) {
            assert (numbers [n2] - _n1 >= 0 && numbers [n2] - _n1 < 125001);
            if (num_available [_n1 + (numbers [n2] - _n1) * (N - 1)] &&
                num_available [_n1 + (numbers [n2] - _n1) * (N - 2)])
                dist_available [numbers [n2] - _n1] = true;
        }
    }

    asm_num ();

    if (!have_res) fprintf (fout, "NONE\n");

    return 0;
}

int main () {
    read_input ();
    process ();
    fclose (fin);
    fclose (fout);
    return 0;
}