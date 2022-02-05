#include <iostream>
using namespace std;
#define MAX 1000 
class heap{
    int *arr;
    int parent;
    int leftch;
    int rightch;
    int size;
    public:

    heap(){
        arr = new int[MAX];
        size=0;
    }

    void swap(int *a, int *b)
    {
    int temp = *b;
    *b = *a;
    *a = temp;
    }

    void insertNode(int newNum){
    if (size == 0)
    {
        arr[size++]=newNum;}
    else
    {
    arr[size++]=newNum;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
    heapify(size,i);}}}
    

    void deleteNode(int num){
    int i;
    for (i = 0; i < size; i++)
    {
        if (num == arr[i])
        break;}
    swap(&arr[i], &arr[--size]);
    for (i = size / 2 - 1; i >= 0; i--)
    {
        heapify(size,i);}
    }

    void heapify(int size,int i)
    {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && arr[l] > arr[largest])
        largest = l;
    if (r < size && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(size,largest);
    }}

    void heapSort() {
    for (int i = size - 1; i >= 0; i--) {
      swap(&arr[0],&arr[i]);
      heapify(i, 0);
    }
  }

    void printArray()
    {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "\n";
    }

};


int main()
{
    heap h1;
    h1.insertNode(4);
    h1.insertNode(17);
    h1.insertNode(3);
    h1.insertNode(12);
    h1.insertNode(9);
    h1.insertNode(6);
    h1.heapSort();
    h1.printArray();
	return 0;
}
