//Sabrina Adeline Lukita 13218014
//kuis 5
//hitung rata-rata nilai
//sort dari nilai tertinggi sampai terendah
//masukkan ke txt atau excel

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//define struct
typedef struct {
    int NIM;
    char Nama[20];
    int Nilai;
} data;

typedef struct {
    data d[10];
} ArrayData;

//fungsi getMean untuk mencari rata-rata
float getMean (ArrayData nilai){
    int i;
    float jumlah;
    float rata;
    jumlah = 0;
    for (i = 0; i < 10; i++){
        jumlah = jumlah + nilai.d[i].Nilai;
    }
    rata = jumlah / 10 ;
    return rata;
}

int main()
{
    ArrayData tab;
    float mean;
    int i,j;
    data temp;

    FILE *myfile1;
    FILE *myfile2;
    //myfile1 untuk sebelum disort
    //myfile2 untuk setelah disort
    myfile1 = fopen("mahasiswa.csv", "w");
    myfile2 = fopen("mahasiswa2.csv", "w");

    //memeasukkan nama, nomor, nim ke dalam data
    strcpy(tab.d[0].Nama, "Yason");
    strcpy(tab.d[1].Nama, "Mogi");
    strcpy(tab.d[2].Nama, "Scott");
    strcpy(tab.d[3].Nama, "Lio");
    strcpy(tab.d[4].Nama, "Tasya");
    strcpy(tab.d[5].Nama, "Vito");
    strcpy(tab.d[6].Nama, "Ben");
    strcpy(tab.d[7].Nama, "Syahri");
    strcpy(tab.d[8].Nama, "Michel");
    strcpy(tab.d[9].Nama, "Jovan");

    tab.d[0].NIM = 13218001;
    tab.d[1].NIM = 13218002;
    tab.d[2].NIM = 13218003;
    tab.d[3].NIM = 13218004;
    tab.d[4].NIM = 13218005;
    tab.d[5].NIM = 13218006;
    tab.d[6].NIM = 13218007;
    tab.d[7].NIM = 13218008;
    tab.d[8].NIM = 13218009;
    tab.d[9].NIM = 13218010;

    //input random nilai
    srand(time(0));

    for (int i=0; i<10; i++){
        tab.d[i].Nilai = (rand()%51)+50 ;
    }

    for (int i=0; i<10; i++){
        printf("%d %d %s %d\n", (i+1), tab.d[i].NIM , tab.d[i].Nama , tab.d[i].Nilai);
        fprintf(myfile1, "%d , %d , %s , %d\n", (i+1), tab.d[i].NIM , tab.d[i].Nama ,tab.d[i].Nilai);
    }

    mean = getMean(tab);
    printf("rata-rata nilai adalah %.2f\n", mean);

    //sortinga
    for (i=0; i<10; i++) {
        for (j=i+1; j<10; j++){
            if (tab.d[i].Nilai < tab.d[j].Nilai){
                temp.Nilai = tab.d[i].Nilai;
                tab.d[i].Nilai = tab.d[j].Nilai;
                tab.d[j].Nilai = temp.Nilai;

                temp.NIM = tab.d[i].NIM;
                tab.d[i].NIM = tab.d[j].NIM;
                tab.d[j].NIM = temp.NIM;

                strcpy(temp.Nama, tab.d[i].Nama);
                strcpy(tab.d[i].Nama, tab.d[j].Nama);
                strcpy(tab.d[j].Nama, temp.Nama);
            }
        }
    }

    for (i=0; i<10; i++){
        printf("%d %d %s %d\n", (i+1), tab.d[i].NIM , tab.d[i].Nama , tab.d[i].Nilai);
        fprintf(myfile2, "%d , %d , %s , %d\n", (i+1), tab.d[i].NIM , tab.d[i].Nama ,tab.d[i].Nilai);
    }

    return 0;
}
