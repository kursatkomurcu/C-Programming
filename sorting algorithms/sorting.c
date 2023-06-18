#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void bubblesort(int arr[], int size){
    int i,j;
    for(i=0;i<size;i++){
        for(j=1;j<size-i;j++){
            if(arr[j-1]>arr[j]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

void selectionsort(int arr[], int size){
    int i,j, minimumIndex;
    for(i=0;i<size;i++){
        minimumIndex = i;
        for(j=i;j<size;j++){
            if(arr[j]<arr[minimumIndex]){
                minimumIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minimumIndex];
        arr[minimumIndex] = temp;
    }
}

void insertionsort(int arr[], int size){
    int i,j, key;
    for(i=1;i<size;i++){
        key = arr[i];
        j = i - 1;
        while(key < arr[j] && j >= 0){
            arr[j+1]= arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

int main(){
    int a[MAX], size, i;

    printf("Kac elemanli?\n");
    scanf("%d", &size);

    for(i=0;i<size;i++){
        scanf("%d", &a[i]);
    }
    //bubblesort(a, size);
    //selectionsort(a, size);
    insertionsort(a, size);
    for(i=0;i<size;i++){
        printf("%d ", a[i]);
    }

    return 0;
}