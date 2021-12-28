#include <iostream>
#include <vector>
#include <SortTestHelper.h>
using namespace std;

/**
 * ����ͼ�����ڽӾ���
 */
class DenseGraph{
 private:
  int n, m; // nΪ�ڵ㣬mΪ��
  bool directed;// ����ͼ��������ͼ
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
 * ϡ��ͼ�����ڽӱ�
 */
 class SparseGraph{
  private:
   int n, m; // nΪ�ڵ㣬mΪ��
   bool directed;// ����ͼ��������ͼ
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
 * ͼ��Graph Theory
 * �ڵ㣺Vertex
 * �ߣ�Edge
 * ����ͼ��Undirected Graph
 * ����ͼ��Directed Graph
 * ��Ȩͼ��Unweighted Graph
 * ��Ȩͼ��Weighted Graph
 * ͼ����ͨ�ԡ���ͼ(�Ի��ߡ�ƽ�б�)
 * ͼ�ı�ʾ���ڽӾ���Adjacency Matrix���ʺϳ���ͼ�����ڽӱ�Adjacency Lists���ʺ�ϡ��ͼ��
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
