#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tarih{
    char islemTarihi[30];
};

struct Ogrenci{
    char ogrID[8];
    char ad[30];
    char soyad[30];
    int puan;
    struct Ogrenci *next;
    struct Ogrenci *prev;
};

struct Yazar{
    int yazarID;
    char yazarAd[30];
    char yazarsoyAd[30];
    struct Yazar *next;
};

struct KitapOrnek{
    char EtiketNo[20];
    char Durum[8];
    struct KitapOrnek *next;
};

struct Kitap{
    char kitapAdi[30];
    char ISBN[13];
    struct Kitap *next;
    struct KitapOrnek *head;
};

struct KitapYazar{
    char ISBN[13];
    int YazarID;
};

struct KitapOdunc{
    char EtiketNo[20];
    char ogrID[8];
    int islemTipi;//değiştirilebilir
    struct Tarih islemTarihi;
};


void printFile(FILE *fptr){
    //fptr = fopen("Ogrenciler.csv", "r");
    char c = fgetc(fptr);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(fptr);
    }
    printf("\n");
    fclose(fptr);
}

void yazarEkle(struct Yazar **yazar){
    int yazarID;
    char yazarAd[30];
    char yazarsoyAd[30];

    printf("Eklemek istediğiniz yazarin bilgilerini giriniz\n");
    scanf("%d %s %s", &yazarID, yazarAd, yazarsoyAd);
    struct Yazar *temp = (struct Yazar *)malloc(sizeof(struct Yazar));
    
    int success = temp != NULL;

    if(success){
        temp->yazarID = yazarID;
        strcpy(temp->yazarAd, yazarAd);
        strcpy(temp->yazarsoyAd, yazarsoyAd);
        temp->next = NULL;

        while(*yazar) yazar = &(*yazar)->next;

        *yazar = temp;
    }
    printf("Yazar basariyla eklendi\n");
}

void yazarSil(struct Yazar **yazar, int position)
{
    int i;
    struct Yazar *temp = (struct Yazar *)malloc(sizeof(struct Yazar));
    struct Yazar *prev = (struct Yazar *)malloc(sizeof(struct Yazar));

    temp = *yazar;
    prev = *yazar;

    for (i = 0; i < position; i++) {
        if (i == 0 && position == 1) {
            *yazar = (*yazar)->next;
            free(temp);
        }
        else {
            if (i == position - 1 && temp) {
                prev->next = temp->next;
                free(temp);
            }
            else {
                prev = temp;
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
}

void yazarGuncelle(struct Yazar **yazar, int position){
    int i;
    int yazarID;
    char yazarAd[30];
    char yazarsoyAd[30];

    struct Yazar *temp = (struct Yazar *)malloc(sizeof(struct Yazar));
    struct Yazar *ptr = (struct Yazar *)malloc(sizeof(struct Yazar));
    
    printf("Yeni id, ad ve soyad giriniz\n");
    scanf("%d %s %s", &yazarID, yazarAd, yazarsoyAd);

    temp->yazarID = yazarID;
    strcpy(temp->yazarAd, yazarAd);
    strcpy(temp->yazarsoyAd, yazarsoyAd);
    temp->next = NULL;

    if(position == 0){
        temp->next = *yazar;
        *yazar = temp;
    }

    else{
        for(i=0,ptr=*yazar;i<position-1;i++){
            ptr = ptr->next;
            if(ptr == NULL){
                printf("Position not found\n");
                return;
            }
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
    

}

void printYazar(struct Yazar **yazar){
    int yazarID;
    char yazarAd[30];
    char yazarsoyAd[30];

    struct Yazar *temp = (struct Yazar *)malloc(sizeof(struct Yazar));
    temp = *yazar;

    while(temp != NULL){
        printf("%d %s %s\n", temp->yazarID, temp->yazarAd, temp->yazarsoyAd);
        temp = temp->next;
    }
}

void kitapEkle(struct Kitap **kitap){
    char kitapAdi[30];
    char ISBN[13];
    
    printf("Eklemek istediginiz kitabin bilgilerini giriniz\n");
    scanf("%s %s", kitapAdi, ISBN);
    struct Kitap *temp = (struct Kitap *)malloc(sizeof(struct Kitap));

    int success = temp != NULL;

    if(success){
        strcpy(temp->kitapAdi, kitapAdi);
        strcpy(temp->ISBN, ISBN);
        temp->next = NULL;

        while(*kitap) kitap = &(*kitap)->next;

        *kitap = temp;
    }
    printf("Kitap basariyla kaydedildi\n");
}

void kitapSil(struct Kitap **kitap, int position){
    int i;
    struct Kitap *temp = (struct Kitap *)malloc(sizeof(struct Yazar));
    struct Kitap *prev = (struct Kitap *)malloc(sizeof(struct Kitap));

    temp = *kitap;
    prev = *kitap;

    for(i = 0; i < position; i++){
        if(i == 0 && position == 1){
            *kitap = (*kitap)->next;
            free(temp);
        }
        else{
            if (i == position - 1 && temp) {
                prev->next = temp->next;
                free(temp);
            }
            else {
                prev = temp;
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
}

void kitapGuncelle(struct Kitap **kitap, int position){
    int i;
    char kitapAdi[30];
    char ISBN[13];

    struct Kitap *temp = (struct Kitap *)malloc(sizeof(struct Kitap));
    struct Kitap *ptr = (struct Kitap *)malloc(sizeof(struct Kitap));

    printf("Yeni kitap adi ve isbn numarasi giriniz\n");
    scanf("%s %s", kitapAdi, ISBN);

    strcpy(temp->kitapAdi, kitapAdi);
    strcpy(temp->ISBN, ISBN);
    temp->next = NULL;

    if(position == 0){
        temp->next = *kitap;
        *kitap = temp;
    }

    else{
        for(i=0, ptr=*kitap;i<position-1;i++){
            ptr = ptr->next;
            if(ptr == NULL){
                printf("Position not found\n");
                return;
            }
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void printKitap(struct Kitap **kitap){
    char kitapAdi[30];
    char ISBN[13];

    struct Kitap *temp = (struct Kitap *)malloc(sizeof(struct Kitap));
    temp = *kitap;

    while(temp != NULL){
        printf("%s %s\n", temp->kitapAdi, temp->ISBN);
        temp = temp->next;
    }
}

void ogrenciEkle(struct Ogrenci **ogrenci){
    char ogrID[8];
    char ad[30];
    char soyad[30];
    int puan;

    printf("Eklemek istediginiz ogrencinin bilgilerini giriniz\n");
    scanf("%s %s %s %d", ogrID, ad, soyad, &puan);
    struct Ogrenci *temp = (struct Ogrenci *)malloc(sizeof(struct Ogrenci));

    int success = temp != NULL;

    if(success){
        strcpy(temp->ogrID, ogrID);
        strcpy(temp->ad, ad);
        strcpy(temp->soyad, soyad);
        temp->puan = puan;

        while(*ogrenci) ogrenci = &(*ogrenci)->next;

        *ogrenci = temp;
    }
    printf("Ogrenci basariyla kaydedildi\n");
}

void ogrenciSil(struct Ogrenci **ogrenci, int position){
    int i;
    struct Ogrenci *temp = (struct Ogrenci *)malloc(sizeof(struct Ogrenci));
    struct Ogrenci *prev = (struct Ogrenci *)malloc(sizeof(struct Ogrenci));

    temp = *ogrenci;
    prev = *ogrenci;

    for(i = 0; i < position; i++){
        if(i == 0 && position == 1){
            *ogrenci = (*ogrenci)->next;
            free(temp);
        }
        else{
            if (i == position - 1 && temp) {
                prev->next = temp->next;
                free(temp);
            }
            else {
                prev = temp;
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
}

void ogrenciGuncelle(struct Ogrenci **ogrenci, int position){
    char ogrID[8];
    char ad[30];
    char soyad[30];
    int puan;

    struct Ogrenci *temp = (struct Ogrenci *)malloc(sizeof(struct Ogrenci));
    struct Ogrenci *ptr = (struct Ogrenci *)malloc(sizeof(struct Ogrenci));

    printf("Yeni ogrenci ID, ad, soyad, puan giriniz\n");
    scanf("%s %s %s %d", ogrID, ad, soyad, &puan);

    strcpy(temp->ogrID, ogrID);
    strcpy(temp->ad, ad);
    strcpy(temp->soyad, soyad);
    temp->puan = puan;
    temp->next = NULL;

    if(position == 0){
        temp->next = *ogrenci;
        *ogrenci = temp;
    }
    
    else{
        for(i=0, ptr=*ogrenci;i<position;i++){
            ptr = ptr->next;
            if(ptr == NULL){
                printf("Position not found\n");
                return;
            }
        }
        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void printOgrenci(struct Ogrenci **ogrenci){
    char ogrID[8];
    char ad[30];
    char soyad[30];
    int puan;

    struct Ogrenci *temp = (struct Ogrenci *)malloc(sizeof(struct Ogrenci));
    temp = *ogrenci;

    while(temp != NULL){
        printf("%s %s %s %d\n", temp->ogrID, temp->ad, temp->soyad, temp->puan);
        temp = temp->next;
    }
}

int main(){
    int islem, islem2, islem3, index;
    FILE *fptr;

    struct Yazar *yazar = (struct Yazar *)malloc(sizeof(struct Yazar));
    struct KitapOrnek *kitapOrnek = (struct KitapOrnek *)malloc(sizeof(struct KitapOrnek));
    struct Kitap *kitap = (struct Kitap *)malloc(sizeof(struct Kitap));
    struct Ogrenci *ogrenci = (struct Ogrenci *)malloc(sizeof(struct Ogrenci));

    yazar->next = NULL;  
    kitapOrnek->next = NULL;
    kitap->next = NULL;
    ogrenci->next = NULL;  
    ogrenci->prev = NULL;

    while(1){
        printf("Sececeginiz islemin numarasini giriniz\n");
        printf("1-Ogrenci Islemleri\n");
        printf("2-Kitap Islemleri\n");
        printf("3-Yazar Islemleri\n");
        printf("4-Cikmak icin 4'e basiniz\n");
        scanf("%d", &islem);

        if(islem == 1){
            printf("Sececeginiz islemin numarasini giriniz\n");
            printf("1-Ogrenci ekle/sil/guncelle\n");
            printf("2-Ogrenci bilgisi goruntule\n");//
            printf("3-Kitap teslim etmemis ogrencileri listele\n");
            printf("4-Cezali ogrencileri listele\n");
            printf("5-Tum ogrencileri listele\n");
            printf("6-Kitap odunc al/teslim et\n");
            scanf("%d", &islem2);

            if(islem2 == 1){
                printf("Sececeginiz islemin numarasini giriniz\n");
                printf("1-Ekle\n");
                printf("2-Sil\n");
                printf("3-Guncelle\n");
                scanf("%d", &islem3);

                if(islem3 == 1){
                    ogrenciEkle(&ogrenci);
                }

                if(islem3 == 2){
                    printf("Silinmesini istediginiz kitap indexini giriniz\n");
                    scanf("%d", &index);
                    ogrenciSil(&ogrenci, index);
                    printOgrenci(&ogrenci);
                }

                if(islem3 == 3){
                    printf("Guncellenmesini istediginiz kitap indexini giriniz\n");
                    scanf("%d", &index);
                    ogrenciGuncelle(&ogrenci, index);
                    printOgrenci(&ogrenci);
                }
            }

            if(islem2 == 2){
                fptr = fopen("Ogrenciler.csv", "r");
                printFile(fptr);
            }
        }

        if(islem == 2){
            printf("Sececeginiz islemin numarasini giriniz\n");
            printf("1-Kitap ekle/sil/guncelle\n");
            printf("2-Kitap bilgisi goruntule\n");
            printf("3-Raftaki kitaplari listele\n");
            printf("4-Zamaninda teslim edilmeyen kitaplari listele\n");
            printf("5-Kitap-Yazar eslestir\n");
            printf("6-Kitabin yazarini guncelle\n");
            scanf("%d", &islem2);

            if(islem2 == 1){
                printf("Sececeginiz islemin numarasini giriniz\n");
                printf("1-Ekle\n");
                printf("2-Sil\n");
                printf("3-Guncelle\n");
                scanf("%d", &islem3);

                if(islem3 == 1){
                    kitapEkle(&kitap);
                }
                
                if(islem3 == 2){
                    printf("Silinmesini istediginiz kitap indexini giriniz\n");
                    scanf("%d", &index);
                    kitapSil(&kitap, index);
                    printKitap(&kitap);
                }

                if(islem3 == 3){
                    printf("Guncellenmesini istediginiz kitap indexini giriniz\n");
                    scanf("%d", &index);
                    kitapGuncelle(&kitap, index);
                    printKitap(&kitap);
                }
            }
            
            if(islem2 == 2){

            }

            if(islem3== 3){
                fptr = fopen("Kitaplar.csv", "r");
                printFile(fptr);
            }

            if(islem2 == 4){

            }

            if(islemt2 == 5){
                
            }

            if(islem2 == 6){

            }
        }

        if(islem == 3){
            printf("Sececeginiz islemin numarasini giriniz\n");
            printf("1-Yazar ekle/sil/guncelle\n");
            printf("2-Yazar bilgisini goruntule\n");//
            scanf("%d", &islem2);

            if(islem2 == 1){
                printf("Sececeginiz islemin numarasini giriniz\n");
                printf("1-Ekle\n");
                printf("2-Sil\n");
                printf("3-Guncelle\n");
                scanf("%d", &islem3);

                if(islem3 == 1){                   
                    yazarEkle(&yazar);
                    printYazar(&yazar);//if'ten çıkmıyor düzeltilecek            
                }
                if(islem3 == 2){
                    printf("Silinmesini istediginiz yazar indexini giriniz\n");
                    scanf("%d", &index);
                    yazarSil(&yazar, index);
                    printYazar(&yazar);
                }
                if(islem3 == 3){
                    printf("Guncellenmesini istediginiz yazar indexini giriniz\n");
                    scanf("%d", &index);
                    yazarGuncelle(&yazar, index);//hata olabilir
                    printYazar(&yazar);
                }
            }

            if(islem2 == 2){
                fptr = fopen("Yazarlar.csv", "r");
                printFile(fptr);
            }
            scanf("%d", &islem);
        }

        if(islem == 4){
            break;
        }
        printf("****************************************************\n");
    }
    
    return 0;
}