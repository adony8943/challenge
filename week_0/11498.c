#include <stdio.h>
#include <stdlib.h>

int main() {
    char *tmp;
    if ((tmp = malloc(100)) == NULL) {
        printf("malloc\n");
        exit(1);
    }

    while(1) {
        int org_x, org_y, count;
        int i;

        fgets(tmp, 100, stdin);
        sscanf(tmp, "%d", &count);
        if (count == 0) break;

        fgets(tmp, 100, stdin);
        sscanf(tmp, "%d %d", &org_x, &org_y);

        for (i = 0; i < count; i++) {
            int x, y;
            fgets(tmp, 100, stdin);
            sscanf(tmp, "%d %d", &x, &y);
            
            if (x == org_x || y == org_y) 
                printf("divisa\n");
            
            else if (y < org_y) {
                if (x < org_x)
                    printf("SO\n");
                else
                    printf("SE\n");
            
            } else {
                if (x < org_x)
                    printf("NO\n");
                else
                    printf("NE\n");
            } 
        }
    }
    free(tmp);
    return 0;
}
