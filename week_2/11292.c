#include <stdio.h>

void swap(int array[], int a, int b) {
    int tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}

void bubble_sort(int arr[], int length) {
    int i;
    int check = 1;
    void swap();

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
    int dragon_num, knight_num, cost, point, check, i, j, k;
    void swap();
    void bubble_sort();

    while (1) {
        scanf("%d %d", &dragon_num, &knight_num);
        if (dragon_num == 0 && knight_num == 0) break;
        int dragon_height[dragon_num], knight_height[knight_num];
        
        /*reset*/
        cost = 0; point = 0;
        
        for (i = 0; i < dragon_num; i++) {
            scanf("%d", &dragon_height[i]);
        }

        for (i = 0; i < knight_num; i++) {
            scanf("%d", &knight_height[i]);
        }

        bubble_sort(dragon_height, dragon_num);
        bubble_sort(knight_height, knight_num);

        for (i = 0; i < dragon_num; i++) {
            check = 0;
            for (j = point; j < knight_num; j++) {
                if (dragon_height[i] <= knight_height[j]) {
                    point = j + 1;
                    cost += knight_height[j];
                    check = 1;
                    break;
                }
            }
            if (!check) {
                printf("Loowater is doomed!\n");
                break;
            }
        }
        if (check) {
            printf("%d\n", cost);
        }
    }
    return 0;
}
