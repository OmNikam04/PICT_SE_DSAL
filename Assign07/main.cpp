#include <bits/stdc++.h>
using namespace std;
#define v 5

class Graph
{
public:
    int a[v][v] = {{0, 1, 5, 0, 4}, {1, 0, 6, 0, 0}, {5, 6, 0, 2, 0}, {0, 0, 2, 0, 3}, {4, 0, 0, 3, 0}};
    Graph()
    {
        // initialize a[5][5] to 0
        // a[5][5] =
    }

    void acceptData()
    {
        int v1, v2, w, e;
        cout << "Enter number of Edges: ";
        cin >> e;

        for (int i = 0; i < e; i++)
        {
            cout << "\nEnter row number: ";
            cin >> v1;
            cout << "\nEnter column number: ";
            cin >> v2;
            cout << "\nEnter weight: ";
            cin >> w;
            cout << endl;
            a[v1][v2] = w;
            a[v2][v1] = w;
        }
    }

    void display()
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }

    void prims()
    {
        bool visited[5] = {false};
        int edge = 0;
        visited[0] = true;

        while (edge < v - 1)
        {
            int minweight = 999;

            int x = 0, y = 0;

            for (int i = 0; i < v; i++)
            {
                if (visited[i])
                {
                    for (int j = 0; j < v; j++)
                    {
                        if (!visited[j] && a[i][j] != 0)
                        {
                            if (a[i][j] < minweight)
                            {
                                minweight = a[i][j];
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }
            visited[y] = true;
            cout << "Edge no: " << edge << " between " << x << "-" << y << " "
                 << " cost= " << minweight << endl;
            edge++;
        }
    }
    int parent[v];
    int findparent(int a){
        while(parent[a] != a){
            a = parent[a];
        }
        return a;
    }
    void setUnion(int x, int y){
        x = findparent(x);
        y = findparent(y);
        parent[x] = y;//now x is parent of y
    }

    void kruskals()
    {
        // initialize set of disjoints set
        for(int i=0; i<v;i++){
            parent[i]= i;
        }
        int edge = 0;
        while (edge < v - 1)
        {
            
            int minweight = 999;
            int x = 0, y = 0;
            for (int i = 0; i < v; i++)
            {
                for (int j = 0; j < v; j++)
                {
                    if (a[i][j] != 0 && (findparent(i) != findparent(j)))
                    {
                        if (a[i][j] < minweight)
                        {
                            minweight = a[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
            setUnion(x, y);
            cout << "Edge no: " << edge << " between " << x << "-" << y << " "
                << " cost= " << minweight << endl;
            edge++;
        }
    }
};

int main()
{
    Graph g;

    int choice;
    do
    {
        cout << "------Minimum Spanning Tree------";
        cout << "\n1.Create Graph";
        cout << "\n2.Display Graph";
        cout << "\n3.Prim's Algorithm";
        cout << "\n4.Krushkal's Algorithm";
        cout << "\n5.Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            g.acceptData();
            break;
        case 2:
            g.display();
            break;
        case 3:
            g.prims();
            break;
        case 4:
            g.kruskals();
            break;
        default:
            cout << "Enter valid choice:" << endl;
            break;
        }
    } while (choice != 5);
    return 0;
}