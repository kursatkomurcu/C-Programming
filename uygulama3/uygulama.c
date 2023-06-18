#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Arac{
    char model[20];
    int yil;
    int satis;
    int fiyat;
    int adet;
};


int main(){
    int i, j, size=3, deger, sira;
    //struct Arac arac[size], temp;
    struct Arac temp, *arac = (struct Arac *)malloc(size*sizeof(struct Arac));
    


    //arac0
    strcpy(arac[0].model, "FiatModel1");
    arac[0].yil = 2019;
    arac[0].satis = 20000;
    arac[0].fiyat = 500000;
    arac[0].adet = 10;

    //arac1
    strcpy(arac[1].model, "Mercedes1");
    arac[1].yil = 2020;
    arac[1].satis = 10000;
    arac[1].fiyat = 1000000;
    arac[1].adet = 15;
    
    //arac2
    strcpy(arac[2].model, "RenaultModel1");
    arac[2].yil = 2021;
    arac[2].satis = 30000;
    arac[2].fiyat = 600000;
    arac[2].adet = 20;

    printf("Deneme...\n");
    for(i=0;i<size;i++){
        printf("%s %d %d %d %d", arac[i].model, arac[i].yil, arac[i].satis, arac[i].fiyat, arac[i].adet);  
        printf("\n");
    }
    

    printf("Arac eklemek için 1, var olan listeyle devam etmek için 2 giriniz\n");
    scanf("%d", &deger);

    //2 için
    if(deger==2){
        printf("Artan sira icin 1, azalan icin 2 giriniz");
        scanf("%d", &sira);

        if(sira==1){
            for (i = 1; i < size; i++)
              for (j = 0; j < size - i; j++) {
                 if (strcmp(arac[j].model, arac[j + 1].model) > 0) {
            		temp = arac[j];
                    arac[j] = arac[j + 1];
                    arac[j + 1] = temp;
                 }
              }
        }

        if(sira==2){
            for (i = 1; i < size; i++)
              for (j = 0; j < size - i; j++) {
                 if (strcmp(arac[j].model, arac[j + 1].model) < 0) {
            		temp = arac[j + 1];
                    arac[j + 1] = arac[j];
                    arac[j] = temp;
                 }
              }
        }

        printf("\n");
        for(i=0;i<size;i++){
            printf("%s %d %d %d %d", arac[i].model, arac[i].yil, arac[i].satis, arac[i].fiyat, arac[i].adet);  
            printf("\n");
        }
    }

    if(deger==1){
        //size += 1;
        arac = (struct Arac *)realloc(arac, (1, sizeof(struct Arac)));
        printf("Eklemek istediginiz degerleri giriniz\n");
        scanf("%s %d %d %d %d", arac[size-1].model, &arac[size-1].yil, &arac[size-1].satis, &arac[size-1].fiyat, &arac[size-1].adet);
        for(i=0;i<size;i++){
            printf("%s %d %d %d %d", arac[i].model, arac[i].yil, arac[i].satis, arac[i].fiyat, arac[i].adet);  
            printf("\n");
        }
    }


    return 0;
}