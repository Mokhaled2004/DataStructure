#include <iostream>
using namespace std;

void maxheapify (int arr[], int  i,int n) {         // maxheapify function

    int left = 2*i + 1;
    int right = 2*i + 2;
    int max = i;
    if (left < n && arr[left] > arr[i]) {
        max = left;
    }
    else {
        max = i;
    }

    if (right < n && arr[right] > arr[max]) {
        max = right;
    }

    if (max != i) {
        swap(arr[i],arr[max]);
        maxheapify(arr,max,n);
    }
}


void buildmaxheap(int arr[], int n) {            // buildmaxheap function

    for (int i = 0; i < (n/2)-1;i++) {
        maxheapify(arr,i,n);
    }
}

void heapmaxsort(int arr[], int n) {             // heapsort function

    buildmaxheap(arr,n);
    for (int i = n -1; i>=0;i--) {

        swap(arr[0],arr[i]);
        maxheapify(arr,0,i);

    }
}


int heapextractmax(int arr[], int n) {           // extractmax function

    if (n < 1) {
        cout << "Heap underflow" << endl;
        return -1;
    }

    int max = arr[0];
    arr[0] = arr[n-1];
    maxheapify(arr,0,n-1);
    return max;
}

void heapincreasekey(int arr[], int i, int key) {        // heapincreasekey function

    if (key < arr[i]) {
        cout << "New key is smaller than the current key" << endl;
        return;
    }

    arr[i] = key;
    while (i > 0 && arr[(i-1)/2] < arr[i]) {
        swap(arr[i],arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

void maxheapinsert(int arr[], int key, int n) {          // maxheapinsert function

    n = n + 1;
    arr[n-1] = INT_MIN;
    heapincreasekey(arr,n-1,key);
}

void minheapify(int arr[], int i, int n) {          // minheapify function

    int left = 2*i + 1;
    int right = 2*i + 2;
    int min = i;
    if (left < n && arr[left] < arr[i]) {
        min = left;
    }
    else {
        min = i;
    }

    if (right < n && arr[right] < arr[min]) {
        min = right;
    }

    if (min != i) {
        swap(arr[i],arr[min]);
        minheapify(arr,min,n);
    }
}



void buildminheap(int arr[], int n) {            // buildminheap function

    for (int i = n / 2 -1; i >=0 ;i--) {
        minheapify(arr,i,n);
    }
}


void heapminsort(int arr[], int n) {             // heapminsort function

    buildminheap(arr,n);
    for (int i = n - 1 ; i>=0 ;i--) {

        swap(arr[0],arr[i]);
        minheapify(arr,0,i);

    }
}


void print(int* arr, int n) {                     // print function
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}







int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};  
    int arr2[] = {12, 11, 13, 5, 6, 7};
    int n1 = sizeof(arr)/sizeof(arr[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    //cout << "Extracting max element from the array: ";
    //cout << heapextractmax(arr,n1) << endl;

    cout << "Original array: ";
    print(arr, n1); 
    heapmaxsort(arr,n1);
    cout << "Sorted array: ";
    print(arr,n1);

    cout << "Original array: ";
    print(arr2, n2); 
    heapminsort(arr2,n2);
    cout << "Sorted array: ";
    print(arr2,n2);

    maxheapinsert(arr, 10, n1);
    cout << "After inserting 10 into the array: ";
    print(arr,n1+1);
    heapmaxsort(arr,n1+1);
    cout << "Sorted array: ";
    print(arr,n1+1);

    


    

    return 0;
}
