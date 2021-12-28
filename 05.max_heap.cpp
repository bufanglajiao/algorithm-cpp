#include <iostream>
#include <math.h>
#include "SortTestHelper.h"

using namespace std;

/**
 * ����/�����
 * �Ƚ������ķ�ʽ�������ѣ�
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
    while(k > 1 && data[k/2] < data[k]) {// ���ڵ�ȵ�ǰ�ڵ�С
      swap(data[k/2], data[k]);
      k /= 2;
    }
  }
  void shiftDown(int k) {
    while(2*k <= count) {// �����Ӿʹ����к��ӽڵ�
      int j = 2*k; // �ڴ���ѭ���У�data[k]�³����Ӻ���
      if(j+1 <= count && data[j+1] > data[j]) {
        j+=1; // �Һ��ӱ����Ӵ��³���λ�ø�Ϊ�Һ���
      }
      if(data[k] >= data[j]){// ��Ϊ�����ѣ����Ը��ڵ�����ӽڵ�
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
    // ���ǵ�testPrintֻ�ܴ�ӡ100��Ԫ�����ڵĶѵ���״��Ϣ
    if( size() >= 100 ){
      cout<<"This print function can only work for less than 100 int";
      return;
    }
    // ���ǵ�testPrintֻ�ܴ���������Ϣ
    if( typeid(Item) != typeid(int) ){
      cout <<"This print function can only work for int item";
      return;
    }

    cout<<"The max heap size is: "<<size()<<endl;
    cout<<"Data in the max heap: ";
    for( int i = 1 ; i <= size() ; i ++ ){
      // ���ǵ�testPrintҪ����е�����������[0, 100)�ķ�Χ��
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
 * ������
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void heapSort(T arr[], int n) {
  MaxHeap<T> max_heap = MaxHeap<T>(n);
  for (int i = 0; i < n; ++i) {
    max_heap.insert(arr[i]); // һ����Ƚ��鷳�����Կ���Heapify��ʽ
  }
  for (int i = n-1; i >= 0; --i) {
    arr[i] = max_heap.extractMax();
  }
}

/**
 *  �����/���ѡ���nlogn
 *  ������ķ�ʽ�洢����ȫ������,
 *  Ϊ�˱������㸸�ӽڵ��������ʽ���������������1��ʼ�洢��
 *  ����������ڶ�̬���ݵ�ά��
 * @return
 */
int main() {
  int n = 100;
  int *arr = SortTestHelper::generateRandomArray(n, 0, n);
  SortTestHelper::testSort("Heap Sort", heapSort, arr, n);
  SortTestHelper::printArray(arr, n);
  delete[] arr;

  /** ����
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

