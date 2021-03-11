//sabrina adeline lukita 13218014
//kuis 7
//keran mengeluarkan air 1 L/dtk, ada bocor diameternya 5 cm
//dari volume 0 ke penuh totalnya 1m kubik berapa t nya
//grafik

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float Vin;
    float Vout;
    float Qin;
    float Qout;
    float r_lubang;
    float h,t,dt,Volume,v,A,phi,g;

    FILE *myfile;
    myfile = fopen("kuis7.csv", "w");

    Qin = 0.001; //1L/dtk
    r_lubang = 0.025; //diameter 5cm , radius 2.5cm
    phi = 3.1428;
    g = 9.8;
    dt = 0.1;
    t = 0;
    h = 0;
    Volume = 0;
    A = phi*r_lubang*r_lubang;//luas lubang

    //mencari h setiap waktu hingga mencapai h maksimum
    //saat h maksimum Vin = Vout
    while((Volume <= 1) && (t<150)){
        Vin = Qin*dt; //V = Q*t
        h = Volume;
        Vout = A*sqrt(2*g*h)*dt; // V = A*v*t karena Q = A*v
        Volume = Volume + (Vin - Vout);
        t = t+dt;
        printf("%f , %.3f\n", h, t);
        fprintf(myfile, "%f ; %.3f\n", h, t);
    }

    fclose(myfile);

    return 0;
}
