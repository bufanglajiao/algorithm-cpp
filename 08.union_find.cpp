#include <iostream>
#include <SortTestHelper.h>
using namespace std;

class UnionFind{
 private:
  int* id;
  int count;
 public:
  UnionFind(int n){
    count = n;
    id = new int[n];
    for (int i = 0; i < n; ++i) {
      id[i] = i;
    }
  }
  int find(int p) {
    assert(p>=0&&p<count);
    return id[p];
  }
  void unionElements(int p, int q) {
    int pID = find(p);
    int qID = find(q);
    if(pID == qID) {
      return;
    }
    for (int i = 0; i < count; ++i) {
      if(id[i] == pID){
        id[i] = qID;
      }
    }
  }
  bool isConnected(int p, int q){// 看是否具有相同的id组名
    return find(p) == find(q);
  }
  ~UnionFind(){
    delete[] id;
  }
};

/// 常规实现思路：将每个元素看做是一个节点(带指向父节点的指针)
class UnionFind2{
 private:
  int* parent;
  int count;
//  int* sz;// 表示以i为根的集合中元素个数
  int* rank;// rank[i]表示根节点为i的树的高度
 public:
  UnionFind2(int count){
    parent = new int[count];
//    sz = new int[count];
    rank = new int[count];
    this->count = count;
    for (int i = 0; i < count; ++i) {
      parent[i] = i;
//      sz[i] = 1;
      rank[i] = 1;
    }
  }
  int find(int p) {
    assert(p>=0&&p<count);
    while (p!=parent[p]){// 根节点是指向其自己的
      parent[p] = parent[parent[p]];// 路径压缩PathCompression减少层数
      p = parent[p];
    }
    return p;
  }
  void unionElements(int p, int q) {
    int pRoot = find(p);
    int qRoot = find(q);
    if(pRoot == qRoot) {
      return;
    }
    if(rank[pRoot] < rank[qRoot]) {// 为了防止树的层次过高
      parent[pRoot] = qRoot; // pRoot指向qRoot
    } else if(rank[qRoot] < rank[pRoot]){
      parent[qRoot] = pRoot;
    } else {
      parent[qRoot] = pRoot;
      rank[qRoot] += 1;
    }
//    if(sz[pRoot] < sz[qRoot]) {// 为了防止树的层次过高
//      parent[pRoot] = qRoot; // pRoot指向qRoot
//      sz[qRoot] += sz[pRoot];
//    } else {
//      parent[qRoot] = pRoot;
//      sz[pRoot] += sz[qRoot];
//    }
  }
  bool isConnected(int p, int q){// 看是否具有相同的id组名
    return find(p) == find(q);
  }
  ~UnionFind2(){
    delete[] parent;
//    delete[] sz;
    delete[] rank;
  }
};

/**
 * 并查集Union Find
 * 回答的是连接问题，关心的是能不能连接，而不是具体的连接路径
 * 对于一组数据，主要支持：
 * union(p,q)、find(p)
 * 回答：isConnected(p,q)
 * @return
 */
int main() {
  int n = 20;
  srand(time(NULL));
  UnionFind uf = UnionFind(n);
  for (int i = 0; i < n; ++i) {
    int a = rand() % n;
    int b = rand() % n;
    uf.unionElements(a, b);
  }
  for (int i = 0; i < n; ++i) {
    int a = rand() % n;
    int b = rand() % n;
    cout << a << " "<< b << " "<< uf.isConnected(a, b)<< endl;
  }
  return 0;
}
