#include <stdio.h>
#define INF 9999999

typedef struct {
    int x;
    int y;
} place;

int route_dp[12][1000], bool_visited[12][1000], visit_num;
place start, size, visit_place[100];

int dp(place pos, int ) {
    int i;
    if (pos.x >= size.x || pos.y >= size.y || pos.x < 0 || pos.y < 0)
        return INF;
    
    if (route_dp[pos.x][pos.y][] != -1)
        return route_dp[][];

    if (pos.x == start.x && pos.y == start.y) {
        for (i = 0;i < visit_num; i++) {
            if(bool_visited[i] == 0)
                break;
        }
    } else {
        for (i = 0; i < visit_num; i++) {
            if(visit_place[i].x == pos.x && visit_place[i].y == pos.y) {
                


        return 
        
    route_dp[x_pos]
    
int main() {
    int i, j, k, scenarios;
    scanf("%d", &scenarios);
    for(i = 0; i < scenarios; i++) {
        scanf("%d %d", &size.x, &size.y);
        scanf("%d %d", &start.x, start.y);
        
        scanf("%d", &visit_num);

        for(j = 0; j < visit_num; j++) {
            scanf("%d %d", &visit_place[j].x, visit_place[j].y);
        }
        memset(dp, -1, sizeof(dp));
        dp
    }


