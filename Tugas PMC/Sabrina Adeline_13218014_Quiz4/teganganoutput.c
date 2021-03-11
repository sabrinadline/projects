// Sabrina Adeline L 13218014
//kuis mencari tegangan output

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    double i, t, V0, Vs, R, C, V;

    FILE *myfile;
    myfile = fopen("grafik.csv", "w");

    printf("masukkan waktu : ");
    scanf("%lf", &t);

    Vs = 5;
    R = 10000; //10 kOhm
    C = 0.000001; //1 uF

    V0 = 0; //asumsi V0 = 0
    for (i = 0.001; i <= t; i+= 0.001){ //range partisi waktu 1ms
        V = ((Vs*0.001) + V0*R*C)/((R*C)+0.001);
        V0 = V;
        printf("%.3f\n , %.3f\n", V0, i);
        fprintf(myfile, "%.3f\n", V0);
    }

    fclose(myfile);
    return 0;
}
