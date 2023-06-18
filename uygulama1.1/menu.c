#include "menu.h"

int topla(int a, int b){
    return (a + b);
}

int cikar(int a, int b){
    return (a - b);
}

int carp(int a, int b){
    return (a * b);
}

float bol(int a, int b){
    return (a / b);
}

int faktoriyel(int a){
    int sonuc = 1;
    while(a != 1){
        sonuc *= a--;
    }
    return sonuc;
}

