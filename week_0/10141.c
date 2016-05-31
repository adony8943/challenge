#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int req_num = 1;
    int pro_num = 1;
    int i, j, k;
    char *tmp;
    int rfp_count = 0;

    char *require[req_num];
    char *proposal[pro_num];
    float price[pro_num];
    int compliance[pro_num];
    int satisfaction[pro_num]; /* the number of (requires correspond with proposal's compliance) */
    char *rfp;
    float min_price;
 
    if ((tmp = malloc(80)) == NULL) {
        printf("malloc\n");
        exit(1);
    }
    if ((rfp = malloc(80))== NULL) {
        printf("malloc\n");
        exit(1);
    }

    while (1) {
        int max_satisfaction = 0;
        if(fgets(tmp, 80, stdin) == NULL) break;
        if(sscanf(tmp, "%d %d", &req_num, &pro_num) != 2) break; 
        
        for (i = 0; i < req_num; i++) {
            if((require[i] = malloc(100)) == NULL) {
                printf("malloc\n");
                exit(1);
            }
        }
        for(i = 0; i < pro_num; i++) { 
            satisfaction[i] = 0;
            if ((proposal[i] = malloc(100)) == NULL) {
                printf("malloc");
                exit(1);
            }
        }

        if (req_num == 0 && pro_num == 0) break;
        
        for (i = 0; i < req_num; i++) {
            fgets(require[i], 100, stdin);
        }
        
        for (i = 0; i < pro_num; i++) {
            fgets(proposal[i], 80, stdin);
            fgets(tmp, 80, stdin);
            sscanf(tmp, "%f %d", &price[i], &compliance[i]);

            /*check compliances are included requires*/
            for (j = 0; j < compliance[i]; j++) {
                fgets(tmp, 80, stdin);
                for(k = 0; k < req_num; k++) {
                    if (strcmp(tmp, require[k]) == 0) {
                        satisfaction[i]++;
                        break;
                    }
                }
            }
        }

        for(i = 0; i < pro_num; i++) {
            if (satisfaction[i] > max_satisfaction) {
                max_satisfaction = satisfaction[i];
                strcpy(rfp, proposal[i]);
                min_price = price[i];
            }
            else if (satisfaction[i] == max_satisfaction) {
                if (price[i] < min_price) {
                    strcpy(rfp, proposal[i]);
                    min_price = price[i];
                }
            }
        }
        rfp_count++;
        printf("\nRFP #%d\n%s", rfp_count, rfp);
    }

    for (i = 0; i < req_num; i++)
        free(require[i]);
    for (i = 0; i < pro_num; i++)
        free(proposal[i]);
    free(rfp);
    free(tmp);

    return 0;
}

