#include <stdio.h>
#include "menu.h"

int main(){
    int x, sayi1, sayi2, sonuc;
    MENU;

    scanf("%d\n", &x);

    switch(x){
        case 1:
            printf("Toplamak istediginiz 1. sayiyi giriniz\n");
            scanf("%d", &sayi1);
            printf("Toplamak istediginiz 2. sayiyi giriniz\n");
            scanf("%d\n", &sayi2);
            sonuc = topla(sayi1, sayi2);
            printf("Sonuc: %d\n", sonuc);
            break;
        case 2:
            printf("Cikarmak istediginiz 1. sayiyi giriniz\n");
            scanf("%d", &sayi1);
            printf("Cikarmak istediginiz 2. sayiyi giriniz\n");
            scanf("%d\n", &sayi2);
            sonuc = cikar(sayi1, sayi2);
            printf("Sonuc: %d\n", sonuc);
            break;
        case 3:
            printf("Carpmak istediginiz 1. sayiyi giriniz\n");
            scanf("%d", &sayi1);
            printf("Carpmak istediginiz 2. sayiyi giriniz\n");
            scanf("%d\n", &sayi2);
            sonuc = carp(sayi1, sayi2);
            printf("Sonuc: %d\n", sonuc);
            break;
        case 4:
            printf("Bolmek istediginiz 1. sayiyi giriniz\n");
            scanf("%d", &sayi1);
            printf("Bolmek istediginiz 2. sayiyi giriniz\n");
            scanf("%d\n", &sayi2);
            sonuc = bol(sayi1, sayi2);
            printf("Sonuc: %d\n", sonuc);
            break;
        case 5:
            printf("Faktoriyel istediginiz sayiyi giriniz\n");
            scanf("%d", &sayi1);
            sonuc = faktoriyel(sayi1);
            printf("Sonuc: %d\n", sonuc);
            break;
        case 6:
            printf("Cikis yapiliyor\n");
            break;
        default:
            printf("Yanlis tusa basildi\n");
            break;
    }

    return 0;
}