#include <stdio.h>

#define I 32767

int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1};

void Myunion(int u, int v)
{
    if (set[u] < set[v])
    {
        set[u] += set[v];
        set[v] = u;
    }
    else
    {
        set[v] += set[u];
        set[u] = v;
    }
}

int find(int u)
{
    int x = u;
    while (set[x] > 0)
    {
        x = set[x];
    }
    return x;
}

int edges[3][9] = {
    {1, 1, 2, 2, 3, 4, 4, 5, 6},
    {2, 6, 3, 7, 4, 5, 7, 7, 7},
    {25, 5, 12, 10, 8, 16, 14, 20, 18}
};

int included[9] = {0};
int t[2][6];

int main()
{
    int i = 0, j, k, u, v, min = I, n = 7, e = 9;
    
    while (i < n - 1)
    {
        min = I;
        k = -1;
        for (j = 0; j < e; j++)
        {
            if (included[j] == 0 && edges[2][j] < min)
            {
                min = edges[2][j];
                k = j;
            }
        }
        
        if (k == -1)
            break;
            
        u = edges[0][k];
        v = edges[1][k];
        
        if (find(u) != find(v))
        {
            t[0][i] = u;
            t[1][i] = v;
            Myunion(find(u), find(v));
            i++;
        }
        included[k] = 1;
    }
    
    printf("Spanning Tree Edges (u, v):\n");
    for (i = 0; i < n - 1; i++)
    {
        printf("(%d,%d)\n", t[0][i], t[1][i]);
    }
    
    return 0;
}
