//A star 
//Graph Algorithm

#include<iostream>
#include<vector>
#include<list>
using namespace std;


class Astar{
    int v;
    public:
    //first element of pair will be associated node and second element of pair will be cost associated
    vector<list<pair<int,int>>> adjList;
    //for storing estimated costs
    vector<int> estimated;


    //constructor for initialization
    Astar(int v){
       this->v=v;
       adjList.resize(v);
    }

   //adding edges
    void addedge(int x,int y,int cost){
        adjList[x].push_back(make_pair(y,cost));
        adjList[y].push_back(make_pair(x,cost)); 
    }

    //adding estimated costs
    void addcost(int cost){
        estimated.push_back(cost);
    }

    pair<int,int> findMinHure(int src,vector<int>& ans_path,vector<bool>& included){
         
         //this will be important from second node onwards to calculate the back distances till now
        int backCost=0;
        if(ans_path.size()!=0){
             //we will calculate cost from source to the till the current node
             for(int i=0;i<ans_path.size()-1;i++){
                 int node=ans_path[i];
                 for(auto j=adjList[node].begin();j!=adjList[node].end();j++){
                    int nextN=(*j).first;
                    if(nextN==ans_path[i+1]){
                        backCost+=(*j).second;
                    }
                 }
             }
        }

         
         //finding all adjacent nodes and there heuristic costs
        vector<pair<int,int>>temp;
        for(auto k=adjList[src].begin();k!=adjList[src].end();k++){   
               int i1=(*k).first;
               int i2=(*k).second;
               //heursitic = acutual + estimated 
               int h=i2+estimated[i1];
               temp.push_back(make_pair(i1,h));
        }

        
        //finding minimum heuristic cost
        int minHeur=INT_MAX;
        int minNode;
        for(int i=0;i<temp.size();i++){
            if(temp[i].second<minHeur){
                minHeur=temp[i].second;
                minNode=temp[i].first;
            }
        }
        //returning minimum heursitic cost along with its node
        return make_pair(minNode,minHeur+backCost);
    }



    void Algorithm(int src,int goal){
        
        //vector to track whether the vertex is included in answer or not
        vector<bool>included(v,false);
        //vector to store path from source to destination
        vector<int>ans_path;

        //include source vertex in the answer
        included[src]=true;
        int heur=estimated[src];
        ans_path.push_back(src);
        
        //till we don't get goal node in te answer we will keep on iterating
        int nextNode=src;
        while(included[goal]!=true){
            
            //for the nextNode,we will choose one node from all adjacent node which has least heuristic value
            pair<int,int>result=findMinHure(nextNode,ans_path,included);
            //include that node with least heuristic value in the answer path
            included[result.first]=true;
            ans_path.push_back(result.first);
            //make that node as the nextNode
            nextNode=result.first;;
            //store the heuristic cost
            heur=result.second;
        }
        

        //print the answer
        for(int h=0;h<ans_path.size();h++){
            cout<<ans_path[h]<<" ";
        }
        cout<<"\n";

        //Heuristic cost print
        cout<<"Heuristic cost is : ";
        cout<<heur;
    }
};

int main(){
    
    int n,e;
    cout<<"Enter number of vertices : ";
    cin>>n;
    cout<<"Enter number of edges : ";
    cin>>e;

    Astar obj(n);

    
    for(int i=0;i<e;i++){
        int x,y,cost;
        cout<<"For edge "<<i+1<<" :";
        cout<<"Enter first vertex :";
        cin>>x;
        cout<<"Enter second vertex :";
        cin>>y;
        cout<<"Enter cost :";
        cin>>cost;
        obj.addedge(x,y,cost);
    }

    cout<<"\n\n";
    cout<<"Now enter heuristic costs for all the vertices(Enter : \n";
    cout<<"Note: enter heuristic cost as 0 for goal node\n";
    for(int j=0;j<n;j++){
        int a;
        cout<<"For vertex "<<j<<" :";
        cin>>a;
        obj.addcost(a);
    }

    obj.Algorithm(0,3);
    return 0;
}