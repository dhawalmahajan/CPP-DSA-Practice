#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    int *arr;
    int size;
    int total_size;

public:
    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void insert(int value)
    {
        if (size == total_size)
        {
            cout << "Heap is full" << endl;
            return;
        }
        arr[size] = value;
        int index = size;
        size++;
        while (index > 0 && arr[(index - 1) / 2] < arr[index])
        {
            cout << "swapping " << arr[index] << " with " << arr[(index - 1) / 2] << endl;
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
        cout << "Inserted: " << arr[index] << endl;
    }
    void deleteNode()
    {
        if (size == 0)
        {
            cout << "Heap is empty" << endl;
            return;
        }
        cout << arr[0] << " deleted" << endl;
        arr[0] = arr[size - 1];
        size--;
        if (size == 0)
        {
            return;
        }
        heapify(0);
    }
    void heapify(int index)
    {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        // Largest will store the index of the element which is greater between parent, left child and right child

        if (left < size && arr[left] > arr[largest])
            largest = left;
        if (right < size && arr[right] > arr[largest])
            largest = right;
        if (largest != index)
        {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    MaxHeap heap(10);
    heap.insert(5);
    heap.insert(10);
    heap.insert(3);
    heap.insert(8);
    heap.insert(12);

    heap.insert(1);
    heap.insert(7);
    heap.insert(6);
    heap.insert(4);
    heap.insert(2);
    heap.print();
    cout << endl;
    heap.deleteNode();
    heap.print();

    return 0;
}
