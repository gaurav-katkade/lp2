#include <iostream>
#include <bits/stdc++.h>
#include <tuple>
#include <vector>
using namespace std;

bool sorting(const tuple<int, int, int> &a, const tuple<int, int, int> &b)
{
  return (get<2>(a) <= get<2>(b));
}

class Krushkal
{
public:
  int v;
  int e;
  vector<tuple<int, int, int>> G;

  Krushkal(int v)
  {
    this->v = v;
  }

  void add(int x, int y, int cost)
  {
    G.push_back(make_tuple(x, y, cost));
  }

  void K()
  {
    sort(G.begin(), G.end(), sorting);
    vector<bool> visited(v, false);
    int total = 0;

    for (int i = 0; i < G.size(); i++)
    {
      if (visited[get<0>(G[i])] == false || visited[get<1>(G[i])] == false)
      {
        visited[get<0>(G[i])] = true;
        visited[get<1>(G[i])] = true;

        total = total + get<2>(G[i]);
      }
    }

    cout << "\n Total cost of MST : ";
    cout << total << "\n";
  }
};

int main()
{

  int v, e;
  cout << "Enter number of veritces : ";
  cin >> v;

  cout << "Enter number of edges : ";
  cin >> e;

  Krushkal obj(v);

  for (int k = 0; k < e; k++)
  {
    int x, y, c;
    cout << "\nFor edge " << (k + 1) << " : ";
    cout << "Enter first vertex : ";
    cin >> x;
    cout << "Enter second vertex : ";
    cin >> y;
    cout << "Enter the cost for edge: ";
    cin >> c;
    obj.add(x, y, c);
  }

  obj.K();
}
