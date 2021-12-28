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
  bool isConnected(int p, int q){// ���Ƿ������ͬ��id����
    return find(p) == find(q);
  }
  ~UnionFind(){
    delete[] id;
  }
};

/// ����ʵ��˼·����ÿ��Ԫ�ؿ�����һ���ڵ�(��ָ�򸸽ڵ��ָ��)
class UnionFind2{
 private:
  int* parent;
  int count;
//  int* sz;// ��ʾ��iΪ���ļ�����Ԫ�ظ���
  int* rank;// rank[i]��ʾ���ڵ�Ϊi�����ĸ߶�
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
    while (p!=parent[p]){// ���ڵ���ָ�����Լ���
      parent[p] = parent[parent[p]];// ·��ѹ��PathCompression���ٲ���
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
    if(rank[pRoot] < rank[qRoot]) {// Ϊ�˷�ֹ���Ĳ�ι���
      parent[pRoot] = qRoot; // pRootָ��qRoot
    } else if(rank[qRoot] < rank[pRoot]){
      parent[qRoot] = pRoot;
    } else {
      parent[qRoot] = pRoot;
      rank[qRoot] += 1;
    }
//    if(sz[pRoot] < sz[qRoot]) {// Ϊ�˷�ֹ���Ĳ�ι���
//      parent[pRoot] = qRoot; // pRootָ��qRoot
//      sz[qRoot] += sz[pRoot];
//    } else {
//      parent[qRoot] = pRoot;
//      sz[pRoot] += sz[qRoot];
//    }
  }
  bool isConnected(int p, int q){// ���Ƿ������ͬ��id����
    return find(p) == find(q);
  }
  ~UnionFind2(){
    delete[] parent;
//    delete[] sz;
    delete[] rank;
  }
};

/**
 * ���鼯Union Find
 * �ش�����������⣬���ĵ����ܲ������ӣ������Ǿ��������·��
 * ����һ�����ݣ���Ҫ֧�֣�
 * union(p,q)��find(p)
 * �ش�isConnected(p,q)
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
