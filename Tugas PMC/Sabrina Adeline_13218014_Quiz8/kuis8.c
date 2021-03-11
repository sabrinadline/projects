//Sabrina Adeline 13218014
//kuis 8
//menukar nilai pada matrix 10 x 10 pada diagonal

#include <stdio.h>
#include <time.h>

int main()
{
    int A[10][10];
    int temp[10][10];
    int i,j;

    //mengisi nilai-nilai pada matrix
    srand(time(0));

    for (i=0; i<10; i++){
        for (j=0; j<10; j++){
            A[i][j] = (rand()%21)-10;
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    //memindahkan angka pada matrix
    for (i=0; i<10; i++){
        for (j=0; j<10; j++){
            if(i<=3 && j<=(8-i) && j>=(i+1)){//segitiga atas
                temp[9-i][j] = A[i][j];
            }else if(i>=6 && j<=(i-1) && j>=(10-i)){//segitiga bawah
                temp[9-i][j] = A[i][j];
            }else if(j<=3 && i<=(8-j) && i>=(j+1)){//segitiga kiri
                temp[i][9-j] = A[i][j];
            }else if(j>=6 && i<=(j-1) && i>=(10-j)){//segitiga kanan
                temp[i][9-j] = A[i][j];
            }else{
                temp[i][j] = A[i][j];
            }
        }
    }

    printf("transformasi matriks menjadi\n");
    for(i=0; i<10; i++){
        for(j=0; j<10; j++){
            printf("%d ", temp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
