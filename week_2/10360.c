#include <stdio.h>

int main() {
    int i, j, k, l, d, scenario, rat_num, x, y, n;
    int max_num, max_x, max_y;
    int bomb_attack[1030][1030];

    scanf("%d", &scenario);
    for (i = scenario; i > 0; i--) {
        /*reset*/
        max_num = 0; max_x = 0; max_y = 0;
        for (j = 0; j < 1025; j++) {
            for (k = 0; k < 1025; k++) {
                bomb_attack[j][k] = 0;
            }
        }

        scanf("%d", &d);
        scanf("%d", &n);
        for (j = 0; j < n; j++) {
            scanf("%d %d %d", &x, &y, &rat_num);
            for (k = x - d; k <= x + d; k++) {
                if (k < 0 || k > 1024)
                    continue;
                for (l = y - d; l <= y + d; l++) {
                    if (l < 0 || l > 1024)
                        continue;
                    bomb_attack[k][l] += rat_num; /*how many rat can be killed in this area (k, l)*/
                }
            }
        }
        
        for (j = 0; j < 1025; j++) {
            for (k = 0; k < 1025; k++) {
                if (max_num < bomb_attack[j][k]) {
                    max_num = bomb_attack[j][k];
                    max_x = j;
                    max_y = k;
                }
            }
        }
        printf("%d %d %d\n", max_x, max_y, max_num);
    }
    return 0;
}
