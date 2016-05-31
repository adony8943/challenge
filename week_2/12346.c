#include <stdio.h>

int main() {
    int dam_num, case_num, i, j, k;

    scanf("%d", &dam_num);
    int flow_rate[dam_num], cost[dam_num];

    for (i = 0; i < dam_num; i++) {
        scanf("%d %d", &flow_rate[i], &cost[i]);
    }
    scanf("%d", &case_num);
    int goal_volume[case_num], goal_hour[case_num];

    for (i = 0; i < case_num; i++) {
        scanf("%d %d", &goal_volume[i], goal_hour[i]);
    }

    for (i = 0; i < case_num; i++) {
        int fph = goal_volume[i] / goal_hour[i];
        if (goal_volume[i] % goal_hour[i] > 0) 
            fph += 1;

    }
 
    return 0;
}
