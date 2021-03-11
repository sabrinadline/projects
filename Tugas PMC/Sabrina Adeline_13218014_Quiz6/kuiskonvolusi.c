//Sabrina Adeline Lukita 13218014
//kuis 5
//menghitung konvolusi dari dua fungsi

#include <stdio.h>

float fx1(float x){
    float fungsi;
    if ((x>=1)&&(x<=3)){
        fungsi = (x-1)/2;
    }else{
        fungsi = 0;
    }
    return fungsi;
}

float fx2(float x){
    float fungsi;
    if((x>=-1)&&(x<0)){
        fungsi = x+1;
    }else if((x>=0)&&(x<1)){
        fungsi = -x+1;
    }else{
        fungsi = 0;
    }
    return fungsi;
}

int main()
{
    float i,j;
    float konvolusi;
    FILE *myfile1;

    myfile1 = fopen("konvolusi.csv", "w");

    printf("waktu , y(t)\n");
    //karena dari t=-1 sampai t=3 dengan dt=0.001
    for (i=0; i<5001; i++){
        konvolusi = 0;
        for (j=-10000; j<10000; j++){
            konvolusi = konvolusi + (fx1(j/1000)*fx2((i-j)/1000));
        }
        printf("%5.3f , %.3f\n", i/1000, konvolusi/1000);
        fprintf(myfile1,"%5.3f; %.3f\n", i/1000, konvolusi/1000);
    }

    fclose(myfile1);
    return 0;

}
