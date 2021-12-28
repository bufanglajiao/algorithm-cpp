#include <iostream>
#include <math.h>
#include "SortTestHelper.h"

using namespace std;

/**
 * 最大堆/二叉堆
 * 比较完美的方式是索引堆：
 * 0     1  2 3 4 5 6 7 8 9 10
 * index 10 9 7 8 5 6 3 1 4 2
 * data 15 17 19 13 22 16 28 30 41 62
 * @tparam Item
 */
template<typename Item>
class MaxHeap {
 private:
  Item* data;
  int count;
  int capacity;
  void shiftUp(int k) {
    while(k > 1 && data[k/2] < data[k]) {// 父节点比当前节点小
      swap(data[k/2], data[k]);
      k /= 2;
    }
  }
  void shiftDown(int k) {
    while(2*k <= count) {// 有左孩子就代表有孩子节点
      int j = 2*k; // 在此轮循环中，data[k]下沉到子孩子
      if(j+1 <= count && data[j+1] > data[j]) {
        j+=1; // 右孩子比左孩子大，下沉的位置改为右孩子
      }
      if(data[k] >= data[j]){// 因为是最大堆，所以父节点大于子节点
        break;
      }
      swap(data[k], data[j]);
      k = j;
    }
  }
  void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft){
    int sub_tree_width = (cur_tree_width - 1) / 2;
    int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
    assert(offset + 1 < line.size());
    if( num >= 10 ) {
      line[offset + 0] = '0' + num / 10;
      line[offset + 1] = '0' + num % 10;
    }
    else{
      if( isLeft)
        line[offset + 0] = '0' + num;
      else
        line[offset + 1] = '0' + num;
    }
  }

  void putBranchInLine( string &line, int index_cur_level, int cur_tree_width){
    int sub_tree_width = (cur_tree_width - 1) / 2;
    int sub_sub_tree_width = (sub_tree_width - 1) / 2;
    int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
    assert( offset_left + 1 < line.size() );
    int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
    assert( offset_right < line.size() );
    line[offset_left + 1] = '/';
    line[offset_right + 0] = '\\';
  }
 public:
  MaxHeap(int capacity) {
    data = new Item[capacity+1];
    count = 0;
    this->capacity = capacity;
  }

  int size(){
    return count;
  }

  bool isEmpty() {
    return count == 0;
  }

  void insert(Item item) {
    assert(count +1 <= capacity);
    data[count+1] = item;
    count++;
    shiftUp(count);
  }

  Item extractMax() {
    assert(count > 0);
    Item ret = data[1];
    swap(data[1], data[count]);
    count--;
    shiftDown(1);
    return ret;
  }

  void testPrint(){
    // 我们的testPrint只能打印100个元素以内的堆的树状信息
    if( size() >= 100 ){
      cout<<"This print function can only work for less than 100 int";
      return;
    }
    // 我们的testPrint只能处理整数信息
    if( typeid(Item) != typeid(int) ){
      cout <<"This print function can only work for int item";
      return;
    }

    cout<<"The max heap size is: "<<size()<<endl;
    cout<<"Data in the max heap: ";
    for( int i = 1 ; i <= size() ; i ++ ){
      // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
      assert( data[i] >= 0 && data[i] < 100 );
      cout<<data[i]<<" ";
    }
    cout<<endl;
    cout<<endl;

    int n = size();
    int max_level = 0;
    int number_per_level = 1;
    while( n > 0 ) {
      max_level += 1;
      n -= number_per_level;
      number_per_level *= 2;
    }

    int max_level_number = int(pow(2, max_level-1));
    int cur_tree_max_level_number = max_level_number;
    int index = 1;
    for( int level = 0 ; level < max_level ; level ++ ){
      string line1 = string(max_level_number*3-1, ' ');

      int cur_level_number = min(count-int(pow(2,level))+1,int(pow(2,level)));
      bool isLeft = true;
      for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ ){
        putNumberInLine( data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
        isLeft = !isLeft;
      }
      cout<<line1<<endl;

      if( level == max_level - 1 )
        break;

      string line2 = string(max_level_number*3-1, ' ');
      for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
        putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
      cout<<line2<<endl;

      cur_tree_max_level_number /= 2;
    }
  }

  ~MaxHeap(){
    delete[] data;
  }
};

/**
 * 堆排序
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void heapSort(T arr[], int n) {
  MaxHeap<T> max_heap = MaxHeap<T>(n);
  for (int i = 0; i < n; ++i) {
    max_heap.insert(arr[i]); // 一个插比较麻烦，可以考虑Heapify方式
  }
  for (int i = n-1; i >= 0; --i) {
    arr[i] = max_heap.extractMax();
  }
}

/**
 *  二叉堆/最大堆——nlogn
 *  以数组的方式存储，完全二叉树,
 *  为了便于满足父子节点的索引公式，这里数组从索引1开始存储。
 *  堆排序多用于动态数据的维护
 * @return
 */
int main() {
  int n = 100;
  int *arr = SortTestHelper::generateRandomArray(n, 0, n);
  SortTestHelper::testSort("Heap Sort", heapSort, arr, n);
  SortTestHelper::printArray(arr, n);
  delete[] arr;

  /** 最大堆
  MaxHeap<int> max_heap = MaxHeap<int>(100);
//  cout << max_heap.size() << endl;
  srand(time(NULL));
  for (int i = 0; i < 23; ++i) {
    max_heap.insert(rand() % 100);
  }
  max_heap.testPrint();
  while(!max_heap.isEmpty()) {
    cout << max_heap.extractMax() << " ";
  }
  cout << endl;
   */
  return 0;
}

