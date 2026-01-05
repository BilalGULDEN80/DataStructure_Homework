#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


#define N 5
void dfs(int v);
int graf[N][N] = {
    {0,1,0,0,0},
    {1,0,0,0,0},
    {0,0,0,1,0},
    {0,0,1,0,0},
    {0,0,0,0,0}
};

int ziyaretedilen[N] = {0};

int main(int argc, char *argv[]) 
{
	int cluster = 0,i=0;

    for (i = 0; i < N; i++) 
	{
        if (!ziyaretedilen[i]) {
            cluster++;
            printf("Cluster %d: ", cluster);
            dfs(i);
            printf("\n");
        }
    }
	return 0;
}
void dfs(int v)
 {
 	int i = 0;
    ziyaretedilen[v] = 1;
    printf("%d ", v);
    for (i = 0; i < N; i++) {
        if (graf[v][i] == 1 && !ziyaretedilen[i]) {
            dfs(i);
        }
    }
}

