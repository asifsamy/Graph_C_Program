#include<stdio.h>
#include<stdlib.h>

struct Edge
{
    char edgeName;
    struct Edge *edgePtr;
} *edge, *tmpEdge;

struct Vertex
{
    char vertexName;
    struct Vertex *fromPtr;
    struct Edge *toPtr;
} *vertex, *tmpVert;

struct Head
{
    int counter;
    struct Vertex *point;
} *head;

void InsertEdge_1st()
{
    int j, no_of_edges;

    head->point = vertex;
    tmpVert = head->point;

    printf("\nEnter number of edges you want to connect:");
    scanf("%d", &no_of_edges);
    printf("\nEnter the vertices which are connected to that vertex : ");
    for(j=1; j<=no_of_edges; j++)
    {
        edge=(struct Edge*)malloc(sizeof(struct Edge));
        scanf(" %c", &edge->edgeName);
        edge->edgePtr = NULL;

        if(tmpVert->toPtr == NULL)
        {
            tmpVert->toPtr = edge;
            tmpEdge = tmpVert->toPtr;
        }

        else
        {
            tmpEdge->edgePtr = edge;
            tmpEdge = tmpEdge->edgePtr;
        }
    }

}

void InsertEdge()
{
    int j, no_of_edges;

    tmpVert->fromPtr = vertex;
    tmpVert = tmpVert->fromPtr;

    printf("\nEnter number of edges you want to connect:");
    scanf("%d", &no_of_edges);
    printf("\nEnter the vertices which are connected to that vertex: ");
    for(j=1; j<=no_of_edges; j++)
    {
        edge = (struct Edge*)malloc(sizeof(struct Edge));
        scanf(" %c", &edge->edgeName);
        edge->edgePtr = NULL;

        if(tmpVert->toPtr == NULL)
        {
            tmpVert->toPtr = edge;
            tmpEdge = tmpVert->toPtr;
        }

        else
        {
            tmpEdge->edgePtr = edge;
            tmpEdge = tmpEdge->edgePtr;
        }
    }

}

void InsertVertex(int n)
{
    int i;
    for(i=1; i<=n; i++)
    {
        vertex = (struct Vertex*)malloc(sizeof(struct Vertex));
        printf("\nEnter the name of vertex%d : ", i);
        scanf(" %c", &vertex->vertexName);
        vertex->fromPtr = NULL;
        vertex->toPtr = NULL;

        if (head->point == NULL)
            InsertEdge_1st();
        else
            InsertEdge();

        system("cls");
    }
    head->counter++;
}

void printGraph(int n)
{
    int i,j;

    tmpVert = head->point;

    FILE *fp;
    fp = fopen("aph.txt","w");

    printf("\nPrinted as adjacency List\n");
    for(i=1; i<=n; i++)
    {
        printf("%c", tmpVert->vertexName);
        fprintf(fp, "%c", tmpVert->vertexName);
        tmpEdge = tmpVert->toPtr;
        while(tmpEdge != NULL)
        {
            printf("->%c", tmpEdge->edgeName);
            fprintf(fp, "->%c", tmpEdge->edgeName);
            tmpEdge = tmpEdge->edgePtr;
        }
        tmpVert = tmpVert->fromPtr;
        printf("\n");
        fprintf(fp,"\n");
    }
}

int main()
{
    int i, no_of_vert;

    head = (struct Head*)malloc(sizeof(struct Head));
    head->counter = 0;
    head->point = NULL;

    printf("\n\n\nEnter the total number of Vertices: ");
    scanf("%d", &no_of_vert);
    system("cls");

    InsertVertex(no_of_vert);

    printGraph(no_of_vert);

    return 0;
}
