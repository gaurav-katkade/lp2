#include <iostream>
#include <vector>
#include <list>
using namespace std;

class GraphColouring
{
    int vertices;
  public:
    vector<list<int>> v;

    GraphColouring(int n)
    {
        this->vertices = n;
        v.resize(n);
    }

    void addedge(int x, int y)
    {
        v[x].push_back(y);
        v[y].push_back(x);
    }

    bool isSafe(int vertex,int c,int color_ans[]){
        //new for loop which can run  in ubuntu
        for(auto k=v[vertex].begin();k!=v[vertex].end();k++){
            int i=*k;
            if(color_ans[i]==c){
                return false;
            }
        }
        return true;
    }

    bool GraphColour(int vertex, int color_ans[])
    {
        if (vertex == vertices)
        {
            return true;
        }
        // consider this vertex and try different colours
        for (int c = 1; c < vertices + 1; c++)
        {
            // check assignment of this color is safe or not
            if (isSafe(vertex, c,color_ans))
            {
                color_ans[vertex] = c;

                if (GraphColour(vertex + 1, color_ans) == true)
                {
                    return true;
                }
                // if color c does not lead to solution , go for next iteration of color
                color_ans[vertex] = 0;
            }
        }
        // if no assignemtn of coloru possibel
        return false;
    }

    void colouring()
    {
        // creating array which will indicate color to the node
        // initialize it with 0
        int color_ans[vertices];
        for (int i = 0; i < vertices; i++)
        {
            color_ans[i] = 0;
        }

        // for each vetex we will assign colour
        GraphColour(0, color_ans);

        //print answer colours
        for(int k=0;k<vertices;k++){
            // cout<<color_ans[k]<<" ";
            //1==red, 2==green,3==yellow,and son on 
            cout<<"Node "<<k<<": ";
            if(color_ans[k]==1){
                cout<<"red";
            }else if(color_ans[k]==2){
                cout<<"green";
            }else if(color_ans[k]==3){
                cout<<"yellow";
            }else if(color_ans[k]==4){
                cout<<"blue";
            }else if(color_ans[k]==5){
                cout<<"orange";
            }else if(color_ans[k]==6){
                cout<<"white";
            }else{
                cout<<"black";
            }
            cout<<"\n";
        }
    }
};

int main()

{

    int v, e;
    cout << endl;
    cout << "\tEnter number of nodes/vertices of the graph : ";
    cin >> v;
    GraphColouring obj(v);
    cout << "Enter the number of edges of the graph : ";
    cin >> e;
    cout << endl;

    for (int i = 0; i < e; i++)

    {

        int x, y;
        cout << "\nFor edge " << i + 1 << ": ";
        cout << "Enter first vertex of edge :";
        cin >> x;
        cout << "\t Enter last vertex of edge :";
        cin >> y;
        obj.addedge(x, y);
    }

     obj.colouring();
    return 0;
}