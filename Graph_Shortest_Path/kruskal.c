#include <stdio.h>
#include <stdlib.h>

typedef struct { int u,v,weight; } Edge;
int parent[100];

int find(int i){ return (parent[i]==i)?i:(parent[i]=find(parent[i])); }
void unite(int i,int j){ parent[find(i)] = find(j); }

int cmp(const void *a,const void *b){ return ((Edge*)a)->weight - ((Edge*)b)->weight; }

void kruskal(Edge edges[],int n,int V){
    for(int i=0;i<V;i++) parent[i]=i;
    qsort(edges,n,sizeof(edges[0]),cmp);
    printf("Edge \tWeight\n");
    for(int i=0;i<n;i++){
        int u=edges[i].u,v=edges[i].v;
        if(find(u)!=find(v)){
            printf("%d-%d \t%d\n",u,v,edges[i].weight);
            unite(u,v);
        }
    }
}

int main(){
    Edge edges[]={{0,1,2},{0,3,6},{1,2,3},{1,3,8},{1,4,5},{2,4,7},{3,4,9}};
    int n=sizeof(edges)/sizeof(edges[0]);
    kruskal(edges,n,5);
    return 0;
}
