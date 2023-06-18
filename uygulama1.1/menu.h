#ifndef menu
#define menu

#define MENU printf("Toplama icin 1e basiniz\n"); \
             printf("Cikarma icin 2ye basiniz\n"); \
             printf("Carpma icin 3e basiniz\n"); \
             printf("Bolme icin 4e basiniz\n"); \
             printf("Faktoriyel icin 5e basiniz\n"); \
             printf("Cikis icin 6ya basiniz\n");

int topla(int a, int b);
int cikar(int a, int b);
int carp(int a, int b);
float bol(int a, int b);
int faktoriyel(int a);

#endif