#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int shortestDistance[20];
struct Graph{
    int v;
    int e;
    struct Edge *edge;
};

struct Edge{
    int source, destination, weight;
};

void bellmanFord(struct Graph *graph, int s);
struct Graph* createGraph(int v, int e);
void main(){
    int v,e,s;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &v);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &e);
    printf("Enter the source vertex: ");
    scanf("%d", &s);

    for(int i = 1; i <= v; i++){
        shortestDistance[i] = 999;
    }
    shortestDistance[1] = 0;

    struct Graph* graph = createGraph(v, e);
    for(int i = 0; i < e; i++){
        printf("Enter the source, destination and weight for edge %d: ", i + 1);
        scanf("%d%d%d", &graph->edge[i].source, &graph->edge[i].destination, &graph->edge[i].weight);
    }
    bellmanFord(graph, s);
    printf("The result is as follows:\n");
    for(int i = 1; i <= v; i++){
        printf("%d\t%d\n", i, shortestDistance[i]);
    }
}

struct Graph* createGraph(int v, int e){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph -> v = v;
    graph -> e = e;
    graph -> edge = (struct Edge*)malloc(sizeof(struct Graph));
    return graph;
}

void bellmanFord(struct Graph* graph, int s){
    int v = graph -> v;
    int e = graph -> e; 
    for(int i = 0; i < v - 1; i++){
        for(int j = 0; j < e; j++){
            int du = shortestDistance[graph -> edge[j].source];
            int dv = shortestDistance[graph -> edge[j].destination];
            int c = graph -> edge[j].weight;
            if(dv > du + c)
                shortestDistance[graph -> edge[j].destination] = du + c;
        }
    }
}
