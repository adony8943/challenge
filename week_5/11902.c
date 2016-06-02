#include <stdio.h>
#include <string.h>

int bool_visit[105];
int nodes[105][105];
int size;

/* 深さ優先探索*/
void dfs(int now_node, int no_exist_node) {
    int i;
    if (now_node == no_exist_node)
        return;
    bool_visit[now_node] = 1;

    for (i = 0; i <size; i++) {
        if(nodes[now_node][i] && !bool_visit[i]) {
            dfs(i, no_exist_node);
        }
    }
}
    
int main() {
    int trial, i, j;
    int case_num = 1;
    char ans[105][105];
    int org_bool_visit[105];
    scanf("%d", &trial);
    while(trial--) {
        scanf("%d", &size);

        for(i = 0; i < size; i++) {
            for(j = 0; j < size; j++) {
                scanf("%d", &nodes[i][j]);
            }
        }
        memset(bool_visit, 0, sizeof(bool_visit));
        /*どのノードも除外せずに探索する*/
        dfs(0, -1);
        for (i = 0; i < size; i++) {
            org_bool_visit[i] = bool_visit[i];
        }
 
        for (i = 0; i< size; i++) {
            memset(bool_visit, 0, sizeof(bool_visit));
            dfs(0, i);
            for (j = 0; j < size; j++) {
               if(org_bool_visit[j] && !bool_visit[j])
                    ans[i][j] = 'Y';
                else 
                    ans[i][j] = 'N';
            }
        }

        printf("Case %d:\n", case_num++);
        
        /*フレームを書く*/
        for (i = 0; i < size; i++) {
            printf("+");
            for (j = 0; j < size-1; j++) {
                printf("--");
            }
            printf("-+\n");

            for (j = 0; j < size; j++) {
                printf("|%c", ans[i][j]);
            }
            printf("|\n");
        }
        printf("+");
        for (i = 0; i < size-1; i++) {
            printf("--");
        }
        printf("-+\n");
            
    }
    return 0;
}
