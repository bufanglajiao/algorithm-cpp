#include <iostream>
#include <queue>
#include "SortTestHelper.h"

using namespace std;

template<typename Key, typename Value>
class BST {
 private:
  struct Node {
    Key key;
    Value value;
    Node *left;
    Node *right;
    Node(Key key, Value value){
      this->key = key;
      this->value = value;
      this->left = this->right = NULL;
    }
    Node(Node *node){
      this->key = node->key;
      this->value = node->value;
      this->left = node->left;
      this->right = node->right;
    }
  };
  Node *root;
  int count;
 public:
  BST(){
    root = NULL;
    count = 0;
  }
  void insert(Key key, Value value){
    root = insert(root, key, value);
  }
  bool contain(Key key) {
    return contain(root, key);
  }
  Value* search(Key key) {
    return search(root, key);
  }
  void preOrder() {
    preOrder(root);
  }
  void inOrder() {
    inOrder(root);
  }
  void postOrder() {
    postOrder(root);
  }
  // ��nodeΪ���Ķ������������в������
  void levelOrder(){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
      Node *node = q.front();
      q.pop();
      cout << node->key<<endl;
      if(node->left){
        q.push(node->left);
      }
      if(node->right){
        q.push(node->right);
      }
    }
  }
  // Ѱ����С�ļ�ֵ
  Key minimum() {
    assert(count != 0);
    Node* minNode = minimum(root);
    return minNode->key;
  }
  // Ѱ�����ļ�ֵ
  Key maxmum() {
    assert(count != 0);
    Node* maxNode = maximum(root);
    return maxNode->key;
  }
  // ɾ����Сֵ���ڽڵ�
  void removeMin() {
    if(root){
      root = removeMin(root);
    }
  }
  void removeMax() {
    if(root){
      root = removeMax(root);
    }
  }
  /**
   * ɾ������ڵ�(ɾ��ֻ��һ�������Ǽ򵥵ģ����Ƕ������Ҷ��к��ӵĽڵ�����Կ���Hubbard Deletion)
   * 1.ɾ�����Ҷ��к��ӵĽڵ�d���ҵ�����ڵ�s=min(d->right)[���Һ��ӵ�����]
   * 2.s��d�ĺ�̣���s�ڵ�ɾ����s-right = delMin(d->right);
   * 3.s->left=d->left,ɾ��d��s���µ������ĸ�
   * @param key
   */
  void remove(Key key) {
    root = remove(root, key);
  }

  int size() {
    return count;
  }
  bool isEmpty() {
    return count == 0;
  }
  ~BST(){
    destroy(root);
  }
 private:
  // ����nodeΪ���Ķ����������У�����ڵ�(key, value)�����ز����½ڵ��Ķ����������ĸ�
  Node* insert(Node *node, Key key, Value value){
    if(node == NULL) {
      count++;
      return new Node(key, value);
    }
    if(key == node->key) {
      node->value = value;
    } else if(key < node->key) {
      node->left = insert(node->left, key, value);
    } else {
      node->right = insert(node->right, key, value);
    }
    return node;
  }
  bool contain(Node* node, Key key) {
    if(node == NULL){
      return false;
    }
    if(key == node->key) {
      return true;
    } else if(key < node->key) {
      return contain(node->left, key);
    } else{
      return contain(node->right, key);
    }
  }
  //��nodeΪ���Ķ����������в���key����Ӧ��value
  Value* search(Node* node, Key key) {
    if(node == NULL) {
      return NULL;
    }
    if(key == node->key) {
      return &(node->value);
    } else if(key < node->key) {
      return contain(node->left, key);
    } else {
      return contain(node->right, key);
    }
  }
  //��nodeΪ���Ķ�������������ǰ�����
  void preOrder(Node* node) {
    if(node != NULL) {
      cout << node->key << endl;
      preOrder(node->left);
      preOrder(node->right);
    }
  }
  //��nodeΪ���Ķ��������������������
  void inOrder(Node* node) {
    if(node != NULL) {
      inOrder(node->left);
      cout << node->key << endl;
      inOrder(node->right);
    }
  }
  //��nodeΪ���Ķ��������������������
  void postOrder(Node* node) {
    if(node != NULL) {
      postOrder(node->left);
      postOrder(node->right);
      cout << node->key << endl;
    }
  }
  void destroy(Node* node) {
    if(node != NULL) {
      destroy(node->left);
      destroy(node->right);
      delete node;
      count--;
    }
  }
  // ����nodeΪ���Ķ����������У�������С��ֵ�Ľڵ�
  Node* minimum(Node* node){
    if(node->left == NULL){
      return node;
    }
    return minimum(node->left);
  }
  // ����nodeΪ���Ķ����������У���������ֵ�Ľڵ�
  Node* maximum(Node* node){
    if(node->right == NULL){
      return node;
    }
    return maximum(node->right);
  }
   // ����nodeΪ���Ķ����������У�ɾ����С�ڵ㣬����ɾ���ڵ���µĶ����������ĸ�
  Node* removeMin(Node* node){
    if(node->left == NULL){
      Node* rightNode = node->right;// �Һ���Ҳ�Ƕ����������������ԭ�����ڵ��Ϊ��
      delete node;
      count--;
      return rightNode;
    }
     node->left = removeMin(node->left);
    return node;
  }
  // ����nodeΪ���Ķ����������У�ɾ�����ڵ㣬����ɾ���ڵ���µĶ����������ĸ�
  Node* removeMax(Node* node){
    if(node->right == NULL){
      Node* leftNode = node->left;// ����Ҳ�Ƕ����������������ԭ�����ڵ��Ϊ��
      delete node;
      count--;
      return leftNode;
    }
     node->right = removeMin(node->right);
    return node;
  }
  // ɾ����nodeΪ���Ķ����������м�ֵΪkey�Ľڵ�
  Node* remove(Node* node, Key key){
    if(node == NULL){
      return NULL;
    }
    if(key < node->key) {
      node->left = remove(node->left, key);
      return node;
    }else if(key > node->key){
      node->right = remove(node->right, key);
      return node;
    } else {
      if(node->left == NULL) {
        Node *rightNode = node->right;
        delete node;
        count--;
        return rightNode;
      }
      if(node->right == NULL) {
        Node *leftNode = node->left;
        delete node;
        count--;
        return leftNode;
      }
      // ���Һ��Ӷ���Ϊ��
      Node *delNode = node;
      Node *successor = new Node(minimum(node->right));
      count++;
      successor->right = removeMin(node->right);
      successor->left = node->left;
      delete delNode;
      count--;
      return successor;
    }
  }

};


/**
 * ����������/����������(logn):
 * 1��ÿ���ڵ�ļ�ֵ>���ӣ�<�Һ���
 * 2. �����Һ���Ϊ����������ȻΪ����������
 * 3. ��һ������ȫ������
 * ͨ������ʵ�ֲ��ұ����ֵ����ݽṹ
 * ƽ����������Կ��Ǻ����
 * @return
 */
int main() {
  return 0;
}

