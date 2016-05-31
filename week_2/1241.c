#include <stdio.h>

typedef struct {
    int state;
    NODE left;
    NODE right;
} NODE;

int main() {
    int repeat, large, num, i, j, k, N, no_exist;
    char *tmp;

    if ((tmp = malloc(100)) == NULL) {
        printf("malloc_error\n");
        exit(1);
    }
        
    scanf("%d", &repeat);
    while (repeat--) {
        large = 1;
        fgets(tmp, 100, stdin);
        sscanf(tmp, "%d %d", &N, &num);
        
        for (i = 0; i < N; i++) {
            large *= 2;
        }
        int tournament[large];


        for (i = 0; i < num; i++) {
            scanf("%d", no_exist);
        
    return 0;
}
