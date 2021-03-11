//Sabrina Adeline Lukita 13218014
//kuis luas lingkaran

#include <stdio.h>
#include <math.h>

double getLuasKali (double r){
    double hasil;
    hasil = 3.14285714*r*r;
    return hasil;
}

double getLuasIntegral (double r, int partisi){
    double hasilawal, hasilakhir;
    double i;
    double selang1, selang2;

    selang1 = r/partisi;
    selang2 = (2*3.14285714)/partisi;
    hasilawal = 0;
    hasilakhir = 0;

    //integral dalam
    for (i=0; i<=r; i+=selang1){
        hasilawal = hasilawal + (selang1*i);
    }

    //integral luar
    for (i=0; i<=(2*3.14285714); i+=selang2){
        hasilakhir = hasilakhir + (selang2*hasilawal);
    }
    return hasilakhir;
}

int main()
{
    double r;
    double LnonInt, LInt;
    double error;
    int partisi;

    printf("r = ");
    scanf("%lf", &r);
    printf("jumlah partisi = ");
    scanf("%d", &partisi);

    LnonInt = getLuasKali(r);
    LInt = getLuasIntegral(r, partisi);
    error = LnonInt - LInt;
    //galat akan semakin kecil bila input partisi semakin besar misalnya 10000

    printf("luas lingkaran hasil perkalian = %lf\n", LnonInt);
    printf("luas lingkaran hasil integral = %lf\n", LInt);
    printf("error = %lf\n", error);


    return 0;
}
