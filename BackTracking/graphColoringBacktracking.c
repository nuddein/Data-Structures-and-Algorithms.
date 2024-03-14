#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTEX 10

// Sehir boyama fonksiyonu
bool is_safe(int v, int graph[MAX_VERTEX][MAX_VERTEX], int color[], int c, int V) {
	int i;
    for (i = 0; i < V; i++) {
        if (graph[v][i] && c == color[i]) {
            return false;
        }
    }
    return true;
}

// Sehir boyama algoritmasi
bool graph_coloring_util(int graph[MAX_VERTEX][MAX_VERTEX], int m, int color[], int v, int V) {
    if (v == V) {
        return true;
    }
	int c;
    for (c = 1; c <= m; c++) {
        if (is_safe(v, graph, color, c, V)) {
            color[v] = c;
            if (graph_coloring_util(graph, m, color, v + 1, V)) {
                return true;
            }
            color[v] = 0; // Backtrack
        }
    }

    return false;
}

// Sehir boyama islevi
void graph_coloring(int graph[MAX_VERTEX][MAX_VERTEX], int m, int V) {
    int color[MAX_VERTEX];
    int i;
    for (i = 0; i < V; i++) {
        color[i] = 0;
    }

    if (!graph_coloring_util(graph, m, color, 0, V)) {
        printf("Çözüm bulunamadi.\n");
    } else {
        printf("Sehir boyama çözümü:\n");
        for (i = 0; i < V; i++) {
            printf("Sehir %d: Renk %d\n", i + 1, color[i]);
        }
    }
}

int main() {
    int V, m; // V: Sehir sayisi, m: Renk sayisi
    printf("Sehir sayisini girin: ");
    scanf("%d", &V);

    printf("Renk sayisini girin: ");
    scanf("%d", &m);

    int graph[MAX_VERTEX][MAX_VERTEX];

    printf("Baglanti matrisini girin (0 veya 1):\n");
    int i,j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d ve %d arasinda Baglanti matrisini girin (0 veya 1):\n",i,j);
            scanf("%d", &graph[i][j]);
        }
    }

    graph_coloring(graph, m, V);

    return 0;
}

