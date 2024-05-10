#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Dijkstra{
 int vertices;
public:
    vector<list<pair<int,int>>> v;

    Dijkstra(int n)
    {
        this->vertices = n;
        v.resize(n);
    }

   void addedge(int x, int y,int cost)
    { 
        v[x].push_back(make_pair(y,cost));
        v[y].push_back(make_pair(x,cost));
    }
   
   void find(int start){
      //node indcluded or not in answer
      vector<bool>included(vertices,false);
      //vector for storing the path 
      vector<int>path;
      //vector for storing all the distances (updated distances ,intially infinite)
      vector<int>distances(vertices,INT_MAX);

      //make distance of starting node zero  
      distances[start]=0;

      for(int i=0;i<vertices;i++){
        //find node with minimum distance
        int min=INT_MAX, min_index;
        for(int j=0;j<vertices;j++){
            if(included[j]==false && distances[j]<=min){
                min=distances[j];
                min_index=j;
            }
        }

       // make it included in answer and also add to path
        included[min_index]=true;
        path.push_back(min_index);

        //find adjacent and update their distances
        //new for loop which can run in ubuntu
        for(auto k=v[min_index].begin();k!=v[min_index ].end();k++ ){
            int i1=(*k).first;
            int i2=(*k).second;
         if(!included[i1] && distances[min_index]+i2< distances[i1]){
            distances[i1]=distances[min_index]+i2;
         }
      }
      }

      //print the path i.e. answer
      for(int k=0;k<path.size();k++){
        cout<<path[k]<<" -> ";
      }

   }
  
   
};


int main(){
   
   int v,e;
   cout<<"Enter number of veritces : ";
   cin>>v;
   
   cout<<"Enter number of edges : ";
   cin>>e;
  
   Dijkstra obj(v);
    
   for (int i = 0; i < e; i++)

    {

        int x, y,cost;
        cout << "\nFor edge " << i + 1 << ": ";
        cout << "Enter first vertex of edge :";
        cin >> x;
        cout << "\t Enter last vertex of edge :";
        cin >> y;
        cout << "\t Enter xost of edge :";
        cin >> cost;

        obj.addedge(x, y,cost);
    }
    
   obj.find(0);
}