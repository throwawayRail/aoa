#include<stdio.h>
#include<stdlib.h>
int cost[9][9], parent[9], u, v, a, b, ne = 1, n, min, total_cost = 0;
int find_parent(int);
int check_cycle(int, int);
void create_matrix();
void display_matrix();
void display_parent();

int main(){
    create_matrix();
    display_matrix();
    while(ne < n){
        for(int i = 1, min = 999; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                if (cost[i][j] < min){
                    min = cost[i][j];
                    u = a = i;
                    v = b = j;
                }
            }
        }
        u = find_parent(u);
        v = find_parent(v);
        if(check_cycle(u, v)){
            printf("Edge number %d will be formed between %d and %d\n", ne++, a, b);
            total_cost += cost[a][b];
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("The cost of the minimum spanning tree is %d\n", total_cost);
}

void create_matrix(){
    printf("Enter the no. of vertices in the graph: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: ");
    for(int i = 1; i <= n; i++)
        cost[i][i] = 999;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            printf("Enter value for cost[%d][%d]: ", i, j);
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
            cost[j][i] = cost[i][j];
        }
    }
}

void display_matrix(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(cost[i][j] == 999){
                printf("0 ");
                continue;
            }
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
}

void display_parent(){
    printf("Parent array is: \n");
    for(int i = 1; i <= n; i++)
        printf("%d ", parent[i]);
}

int find_parent(int i){
//     printf("For %d", i);
    while(parent[i])
        i = parent[i];
//     printf("Parent is: %d\n", i);
    return i;
}

int check_cycle(int i, int j){
    if(i != j){
        parent[j] = i;
        return 1; //cycle is not present
    }
    return 0; //cycle is present
}
