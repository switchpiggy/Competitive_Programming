/*
ID: alanxia1
TASK: sort3
LANG: C++
*/



#include <bits/stdc++.h>
using namespace std;

#define MAXN 	1000

int n;
int have[MAXN];
int want[MAXN];

int
intcmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int i, j, k, n, nn[4], nswap, nbad;
    FILE *fin, *fout;

    fin = fopen("sort3.in", "r");
    fout = fopen("sort3.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d", &n);

    for(i=0; i<n; i++) {
	fscanf(fin, "%d", &have[i]);
	want[i] = have[i];
    }
    qsort(want, n, sizeof(want[0]), intcmp);

    /* swaps that correct two elements */
    nswap = 0;
    for(i=0; i<n; i++)
    for(j=0; j<n; j++) {
	if(have[i] != want[i] && have[j] != want[j]
	        && have[i] == want[j] && have[j] == want[i]) {
	    have[i] = want[i];
	    have[j] = want[j];
	    nswap++;
	}
    }

    /* remainder are pairs of swaps that correct three elements */
    nbad = 0;
    for(i=0; i<n; i++)
	if(have[i] != want[i])
	    nbad++;

    assert(nbad%3 == 0);
    nswap += nbad/3 * 2;

    fprintf(fout, "%d\n", nswap);
    exit(0);
}