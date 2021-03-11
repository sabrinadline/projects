#include <stdio.h>
#include <math.h>

int main()
{
   float V0x, V0y;
   float x, y;
   float t;
   float xmax, tmax;

   /* menghitung kecepatan awal dalam sumbu x dan y*/
    V0x = 50*0.5; /* V0x = V0*cost */
    V0y = 50*0.866; /* V0y = V0*sint */
    printf("V0x = %2.3f m/s\n", V0x);
    printf("V0y = %2.3f m/s\n", V0y);

    /* menghitung waktu maksimum yang dicapai benda sampai ke tanah*/
    tmax = (2*(50*0.866)/10)*1000; /* tmax = (2(V0*sint)/g)*1000 ms */
    printf("tmax = %2.3f ms\n", tmax);

    /* kondisi awal */
    t = 0;

    while (t <= tmax)
    {
        x = V0x*t/1000;
        y = (V0y*t/1000)-(0.5*10*t*t/1000000);
        printf("posisi setiap 10 ms = %2.3f , %2.3f\n", x, y);

        t = t + 10;
    }

    /* menghitung jarak maksimum yang dicapai benda sampai kembali ke tanah*/
    xmax = (50*50*2*0.866*0.5)/10; /* xmax = (V0*V0*2*sint*cost)/g meter*/
    printf("jarak terjauh = %2.3f m\n", xmax);

    return(0);
}
