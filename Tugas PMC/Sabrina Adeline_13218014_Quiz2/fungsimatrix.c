#include <stdio.h>
#include <math.h>

int main()
{
    float A[2][2];
    float B[1][2];
    float C[1][2];
    float invA[2][2];

    /* inisiasi matrix A dan C yang memuat variabel dan hasil persamaan linier dua variabel*/
    /* -2x + y = 2
       -4x + y = -4*/
    A[0][0] = -2;
    A[1][0] = 1;
    A[0][1] = -4;
    A[1][1] = 1;

    C[0][0] = 2;
    C[0][1] = -4;

    /* mmebuat invers matrix A*/
    invA[0][0] = (1/((A[0][0] * A[1][1])-(A[1][0] * A[0][1])))*A[1][1];
    invA[1][0] = (-1/((A[0][0] * A[1][1])-(A[1][0] * A[0][1])))*A[1][0];
    invA[0][1] = (-1/((A[0][0] * A[1][1])-(A[1][0] * A[0][1])))*A[0][1];
    invA[1][1] = (1/((A[0][0] * A[1][1])-(A[1][0] * A[0][1])))*A[0][0];

    /* fungsi perkalian untuk mendapatkan matrix B (x,y)*/
    B[0][0] = (invA[0][0]*C[0][0])+(invA[1][0]*C[0][1]);
    B[0][1] = (invA[0][1]*C[0][0])+(invA[1][1]*C[0][1]);

    /* menampilkan output matrix B (x,y) */
    printf("(x , y) = ( %1.f , %1.f )", B[0][0], B[0][1]);
}
