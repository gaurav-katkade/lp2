#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Prims
{
    int vertices;

public:
    vector<list<pair<int, int>>> v;
    Prims(int n)
    {
        this->vertices = n;
        v.resize(n);
    }

    void addedge(int x, int y, int cost)
    {
        v[x].push_back(make_pair(y, cost));
        v[y].push_back(make_pair(x, cost));
    }

    // we will return only the minimum total cost
    void find(int start)
    {

        // node indcluded or not in answer
        vector<bool> included(vertices, false);
        // vector for storing all the distances
        vector<int> distances(vertices, INT_MAX);

        included[start] = true;
        int total_cost = 0;

        // update distances related to start node
        //new for loop which can run in ubuntu 
        for (auto k = v[start].begin(); k != v[start].end(); k++)
        {
            int i1=(*k).first;
            int i2=(*k).second;
            distances[i1] = i2;
        }

        for (int i = 1; i < vertices; i++)
        {

            // finding minimum
            int min = INT_MAX, min_index;
            for (int j = 0; j < vertices; j++)
            {
                if (included[j] == false && distances[j] <= min)
                {
                    min = distances[j];
                    min_index = j;
                }
            }

            included[min_index] = true;
            total_cost = total_cost + min;

            // update distances related to min_selected node
            //new for loop which can run in ubuntu 
            for (auto k = v[min_index].begin(); k != v[min_index].end(); k++)
            {
                int i1 = (*k).first;
                int i2 = (*k).second;
                if (distances[i1] > i2)
                {
                    distances[i1] = i2;
                }
            }
        }

        cout << "Total cost : " << total_cost;
    }
};

int main()
{

    int v, e;
    cout << "Enter number of veritces : ";
    cin >> v;

    cout << "Enter number of edges : ";
    cin >> e;

    Prims obj(v);
    for (int i = 0; i < e; i++)
    {

        int x, y, cost;
        cout << "\nFor edge " << i + 1 << ": ";
        cout << "Enter first vertex of edge :";
        cin >> x;
        cout << "\t Enter last vertex of edge :";
        cin >> y;
        cout << "\t Enter xost of edge :";
        cin >> cost;
        obj.addedge(x, y, cost);
    }

    obj.find(0);
}