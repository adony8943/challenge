#include <stdio.h>
#include <stdlib.h>

int main() {
    /*char *tmp;*/
    int i, j, k, l, m, n, N, p, q, tmp_num, ans_exist, total_ans_exist, ans;
    int check[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

   while(1) {
        scanf("%d", &N);
        if (N == 0) break;
        total_ans_exist = 0;
        for(i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                if (j == i)continue;
                for (k = 0; k < 10; k++) {
                    if (k == i || k == j) continue;
                    for (l = 0;l < 10; l++) {
                        if (l == i || l == j || l == k) continue;
                        for (m = 0; m < 10; m++) {
                            if (m == i || m == j || m == k || m == l) continue;
                            p = i * 10000 + j * 1000 + k * 100 + l * 10 + m;

                            check[i] = 1; check[j] = 1; check[k] = 1;
                            check[l] = 1; check[m] = 1;

                            q = p * N;
                            if (q >= 100000) continue;
                            tmp_num = q;
                            ans_exist = 1;
                            for(n = 0; n < 5; n++) {
                                if (check[tmp_num % 10] == 1) {
                                    ans_exist = 0;
                                    break;
                                }
                                check[tmp_num % 10] = 1;
                                tmp_num /= 10;
                            }
                            if (ans_exist) {
                                printf("%05d / %05d = %d\n", q, p, N);
                                total_ans_exist = 1;
                            }
                            for (n = 0; n < 10; n++)
                                check[n] = 0;
                        }
                    }
                }
            }
        }
        if (!total_ans_exist)
            printf("There are no solutions for %d.\n", N);
        printf("\n");
    }
    printf("\n");
    return 0;
}


