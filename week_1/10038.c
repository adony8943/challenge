#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}   

/*this sort is easy to make*/
void bubble_sort(int arr[], int length) {
    int i;
    int check = 1;

    while(check == 1 && length > 0) {
        check = 0;
        for (i = 0; i < length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr, i, i + 1);
                check = 1;
            }
        }
        length--;
    }
}
        

int main() {
    int arr[3000], dif_arr[3000], arr_size, i, check;
    while(scanf("%d", &arr_size) == 1) {
        check = 1;
        for (i = 0; i < arr_size; i++) {
            scanf("%d", &arr[i]);
        }
        for(i = 0; i < arr_size - 1;i++) {
            dif_arr[i] = abs(arr[i + 1] - arr[i]);
        }

        bubble_sort(dif_arr, arr_size - 1);

        for(i = 1; i < arr_size; i++) {
            if(dif_arr[i] == dif_arr[i - 1]) {
                check = 0;
                break;
            }
        }
        if(check)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    } 
    return 0;
}
