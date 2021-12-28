#include <iostream>
#include <vector>
#include <SortTestHelper.h>
using namespace std;

/**
 * 稠密图——邻接矩阵
 */
class DenseGraph{
 private:
  int n, m; // n为节点，m为边
  bool directed;// 有向图还是无向图
  vector<vector<bool>> g;
 public:
  DenseGraph(int n, bool directed) {
    this->n = n;
    this->m = 0;
    this->directed = directed;
    for (int i = 0; i < n; ++i) {
      g.push_back(vector<bool>(n, false));
    }
  }
  int V(){
    return n;
  }
  int E() {
    return m;
  }
  void addEdge(int v, int w) {
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);
    if(hasEdge(v, w)){
      return;
    }
    g[v][w] = true;
    if(!directed) {
      g[w][v] = true;
    }
    m++;
  }
  bool hasEdge(int v, int w) {
    assert(v >= 0 && v < n);
    assert(w >= 0 && w < n);
    return g[v][w];
  }
  ~DenseGraph(){

  }
  class adjIterator {
   private:
    DenseGraph &G;
    int v;
    int index;
   public:
    adjIterator(DenseGraph &graph, int v): G(graph){
      this->v = v;
      this->index = -1;
    }
    int begin() {
      index = -1;
      return next();
    }
    int next() {
      for (index += 1; index < G.V(); ++index) {
        if(G.g[v][index]){
          return index;
        }
      }
      return -1;
    }
    bool end() {
      return index >= G.V();
    }
  };
};

/**
 * 稀疏图——邻接表
 */
 class SparseGraph{
  private:
   int n, m; // n为节点，m为边
   bool directed;// 有向图还是无向图
   vector<vector<int> > g;
  public:
   SparseGraph(int n, bool directed) {
     this->n = n;
     this->m = 0;
     this->directed = directed;
     for (int i = 0; i < n; ++i) {
       g.push_back(vector<int>());
     }
   }
   int V(){
     return n;
   }
   int E() {
     return m;
   }
   void addEdge(int v, int w) {
     assert(v >= 0 && v < n);
     assert(w >= 0 && w < n);
     g[v].push_back(w);
     if(v!=w&&!directed) {
       g[w].push_back(v);
     }
     m++;
   }
   bool hasEdge(int v, int w) {
     assert(v >= 0 && v < n);
     assert(w >= 0 && w < n);
     for (int i = 0; i < g[v].size(); ++i) {
       if(g[v][i] == w) {
         return true;
       }
       return false;
     }
   }
   ~SparseGraph(){

   }
   class adjIterator {
    private:
     SparseGraph &G;
     int v;
     int index;
    public:
     adjIterator(SparseGraph &graph, int v): G(graph){
       this->v = v;
       this->index = 0;
     }
     int begin() {
       index = 0;
       if(G.g[v].size()) {
         return G.g[v][index];
       }
       return -1;
     }
     int next() {
      index++;
      if(index < G.g[v].size()){
        return G.g[v][index];
      }
      return -1;
     }
     bool end() {
      return index >= G.g[v].size();
     }
   };
 };


/**
 * 图论Graph Theory
 * 节点：Vertex
 * 边：Edge
 * 无向图：Undirected Graph
 * 有向图：Directed Graph
 * 无权图：Unweighted Graph
 * 有权图：Weighted Graph
 * 图的连通性、简单图(自环边、平行边)
 * 图的表示：邻接矩阵Adjacency Matrix（适合稠密图）、邻接表Adjacency Lists（适合稀疏图）
 * @return
 */
int main() {
  int N = 20;
  int M = 100;
  srand(time(NULL));
  SparseGraph g1(N, false);
  for (int i = 0; i < M; ++i) {
    int a = rand()%N;
    int b = rand()%N;
    g1.addEdge(a, b);
  }
  for (int v = 0; v < N; ++v) {
    cout << v << " : ";
    SparseGraph::adjIterator adj(g1, v);
    for (int w = adj.begin(); !adj.end(); w = adj.next()) {
      cout << w << " ";
    }
    cout << endl;
  }
  cout << endl;
  DenseGraph g2(N, false);
  for (int i = 0; i < M; ++i) {
    int a = rand()%N;
    int b = rand()%N;
    g2.addEdge(a, b);
  }
  for (int v = 0; v < N; ++v) {
    cout << v << " : ";
    DenseGraph::adjIterator adj2(g2, v);
    for (int w = adj2.begin(); !adj2.end(); w = adj2.next()) {
      cout << w << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
