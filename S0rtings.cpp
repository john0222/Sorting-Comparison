#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int n,ch,seed,m;
int *data_array;                    //declear a pointer for datasets
vector <int> algo_select = {};      //declear a vector for algorithms selection buffer 

void SetColor(int color){
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,color);
}

void print(int *arr, int size){
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isSorted(int a[], int n){
    while (--n > 0)
        if (a[n] < a[n - 1])
            return false;
    return true;
}

void shuffle(int a[], int n){
    for (int i = 0; i < n; i++)
        swap(a[i], a[rand() % n]);
}
void bogosort(int a[], int n){
    srand(time(NULL));
    int max = 255;
    int mai = 1;
    while (!isSorted(a, n)){
        SetColor((max - mai) * rand() / (RAND_MAX + 1.0) + mai);
        shuffle(a, n);
        print(a,n);
    }
    cout<<"OMFG!! THIS CANNOT HAPPEN!!! You did the sort with BOGO! It's incredible..."<<endl;
    system("pause");
}

void swap(int * p, int * q){
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

int findmax(int arr[], int n){
    int i;
    int max = arr[0];
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
 
    return max;
}

void bucket_sort(int a[], int n, int max){
    int i, j;
    int *buckets;

    if (a==NULL || n<1 || max<1)
        return ;

    if ((buckets=(int *)malloc(max*sizeof(int)))==NULL)
        return ;
    memset(buckets, 0, max*sizeof(int));

    for(i = 0; i < n; i++) 
        buckets[a[i]]++; 

    for (i = 0, j = 0; i < max; i++) 
        while( (buckets[i]--) >0 )
        a[j++] = i;
}

void InsertionSort(int *arr, int size){

    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (key < arr[j] && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

template<typename T>
void comb_sort(T arr[], int len) {
	double shrink_factor = 0.8;
	int gap = len, swapped = 1, i;
	while (gap > 1 || swapped) {
		if (gap > 1)
			gap = (int) ((double) gap * shrink_factor);
		swapped = 0;
		for (i = 0; gap + i < len; i++)
			if (arr[i] > arr[i + gap]) {
				swap(arr[i], arr[i + gap]);
				swapped = 1;
			}
	}
}

int seg(int *arr, int front, int end){
    int pivot = arr[end];
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}
void quick_sort(int *arr, int front, int end){
    if (front < end) {
        int pivot = seg(arr, front, end);
        quick_sort(arr, front, pivot - 1);
        quick_sort(arr, pivot + 1, end);
    }
}

void merge(int *,int, int , int );

    int find_max(int arr[], int n){
        int i,max=arr[0],cnt=0;
        for(i=1;i<n;i++){
            if(arr[i]>max)
                max=arr[i];
        }
        while(max>0){
            cnt++;
            max=max/10;
        }
    
        return cnt;
}

void merge_sort(int *arr, int low, int high){
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        //merge or conquer sorted arrays
        merge(arr,low,high,mid);
    }
}

// Merge sort 
void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}

void MaxHeapify(std::vector<int> &array, int root, int length){

    int left = 2*root,      // get left child
    right = 2*root + 1,     // get right child
    largest;                // largest include root und child

    if (left <= length && array[left] > array[root])
        largest = left;
    else
        largest = root;

    if (right <= length && array[right] > array[largest])
        largest = right;

    if (largest != root) {                         // if not maximum
        swap(array[largest], array[root]);         //swap key and max node
        MaxHeapify(array, largest, length);        
    }
}

void BuildMaxHeap(std::vector<int> &array){

    for (int i = (int)array.size()/2; i >= 1 ; i--) {
        MaxHeapify(array, i, (int)array.size() - 1);     // length -1
    }
}

void HeapSort(std::vector<int> &array){

    array.insert(array.begin(), 0);                     // 將index(0)閒置

    BuildMaxHeap(array);                                // 將array調整成Max Heap

    int size = (int)array.size() -1;                    // size用來記錄「目前要處理的矩陣」之長度
    for (int i = (int)array.size() -1; i >= 2; i--) {
        swap(array[1], array[i]);                       // 將最大值放到array的最後一個位置
        size--;
        MaxHeapify(array, 1, size);                     // 調整「忽略最後一個位置」的矩陣
    }

    array.erase(array.begin());                         // 將index(0)刪除
}

void countingsort(int array[], int size, int place) {
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int array[], int size) {
  // Get maximum element
  int max = findmax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingsort(array, size, place);
}

void shellSort(int arr[], int n){
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i += 1){
            int temp = arr[i];
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    cout<<"Sorted array: ";
    print(arr,n);
}

void gnomeSort(int arr[], int n){
    int index = 0;
    
    while (index < n) {
            if (index == 0)
                index++;
            if (arr[index] >= arr[index - 1])
                index++;
            else {
                swap(arr[index], arr[index - 1]);
                index--;
                }
        }
    return;
}
  
int shell_sort(int arr[], int n){
    for (int gap = n/2; gap > 0; gap /= 2){
        for (int i = gap; i < n; i += 1){
            int temp = arr[i];
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}

void cock_sort(int arr[], int n){
   bool flag = true;
   int start = 0, end = n-1;
   while(flag){
      flag = false;
      for(int i = start; i<end; i++){ //scan from left to right as bubble sort
         if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
            flag = true;
         }
      }
      if(!flag){ //if nothing has changed simply break the loop
         break;
      }
      flag = false;
      end--; //decrease the end pointer
      for(int i = end - 1; i >= start; i--){ //scan from right to left
         if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
            flag = true;
         }
      }
      start++;
   }
}

void selection_sort(int array[], int n) {
    for (int i=0; i<n-1; i++) {
        int min_idx = i;
        for (int j=i+1; j<n; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        // swap
        int temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }
}

void bubble_sort(int array[], int size) {
  for (int s=0;s<size;s++) {
    for (int i=0;i<size-s;i++) {
      if (array[i] > array[i + 1]) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

void insertion_sort(int arr[], int size){

    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (key < arr[j] && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(int argc, char *argv[]){
    cout<<".____     _____________________/\\        _________________ _____________________"<<endl;
    cout<<"|    |    \\_   _____/\\__    ___)/_____  /   _____/\\_____  \\______   \\__    ___/"<<endl;
    cout<<"|    |     |    __)_   |    |  /  ___/  \\_____  \\  /   |   \\|       _/ |    |   "<<endl;
    cout<<"|    |___  |        \\  |    |  \\___ \\   /        \\/    |    \\    |   \\ |    |   "<<endl;
    cout<<"|_______ \\/_______  /  |____| /____  > /_______  /\\_______  /____|_  / |____|   "<<endl;
    cout<<"        \\/        \\/               \\/          \\/         \\/       \\/           "<<endl;
	cout<<"This is a program to compare the sorting alogrithms in time compelxity"<<endl;
    cout<<"Finish some setup by following indication.\n";
    cout<<"ENJOY!"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"created by John J.Y.  22/19/07"<<endl;
    cout<<"With GPL-3.0 license, ALL RIGHT RESERVED"<<endl;
    Sleep(4000);
    system("cls");
        re:
        cout<<"Press number key(0-9) to select the data mode:"<<endl;
        cout<<"1. 30 elements"<<endl;
        cout<<"2. 70 elements"<<endl;
        cout<<"3. 100 elements"<<endl;
        cout<<"4. 1000 elements"<<endl;
        cout<<"5. 10000 elements"<<endl;
        cout<<"6. 1000000 elements"<<endl;
        cout<<"7. Costimze data"<<endl;

        seed = (unsigned)time(NULL); // get time
        srand(seed); // time seed 

        while(1){
            if (_kbhit()){         //_kbhit() return true while key pressed
            ch = _getch();         // get key value
            switch(ch){            //data selection key press selection
                case 49:
                    n = 30;
                    data_array = new int[n]; //create array
                    for(int i=0;i<30;i++){
                        data_array[i] = rand(); //random data in array
                    }
                    cout<<"30 of random data set"<<endl;
                    /*for(int j=0;j<30;j++){
                        cout<<data_array[j]<<endl;
                    }                                                             //the whole segment are the same
                    */
                    break;
                case 50:
                    n = 70;
                    data_array = new int[n];
                    for(int i=0;i<n;i++){
                        data_array[i] = rand();
                    }
                    cout<<"70 of random data set"<<endl;
                    /*for(int j=0;j<n;j++){
                        cout<<data_array[j]<<endl;
                    }
                    */
                    break;
                case 51:
                    n = 100;
                    data_array = new int[n];
                    for(int i=0;i<n;i++){
                        data_array[i] = rand();
                    }
                    cout<<"100 of random data set"<<endl;
                    /*for(int j=0;j<n;j++){
                        cout<<data_array[j]<<endl;
                    }
                    */
                    break;
                case 52:
                    n = 1000;
                    data_array = new int[n];
                    for(int i=0;i<n;i++){
                        data_array[i] = rand();
                    }
                    cout<<"1000 of random data set"<<endl;
                    /*for(int j=0;j<n;j++){
                        cout<<data_array[j]<<endl;
                    }
                    */
                    break;
                case 53:
                    n = 10000;
                    data_array = new int[n];
                    for(int i=0;i<n;i++){
                        data_array[i] = rand();
                    }
                    cout<<"10000 of random data set"<<endl;
                    /*for(int j=0;j<n;j++){
                        cout<<data_array[j]<<endl;
                    }
                    */
                    break;
                case 54:
                    n = 1000000;
                    data_array = new int[n];
                    for(int i=0;i<n;i++){
                        data_array[i] = rand();
                    }
                    cout<<"1000000 of random data set"<<endl;
                    /*for(int j=0;j<n;j++){
                        cout<<data_array[j]<<endl;
                    }
                    */
                    break;
                case 55:
                    int in;
                    system("cls");
                    cout<<"Input the quantity of data you want:";
                    cin>>in;
                    n = in;
                    data_array = new int[n];
                    for(int i=0;i<n;i++){
                        data_array[i] = rand();
                    }
                    cout<<in<<" of random data set"<<endl;
                    /*for(int j=0;j<n;j++){
                        cout<<data_array[j]<<endl;
                    }
                    */
                    break;
                    
                default:
                    cout<<"Invalid Input, please try again..."<<endl;
                    system("cls");
                    goto re;
                }
                break;
            }
        }   
        //data setup finished
        //select alogrithms below

        Sleep(3500);
        system("cls");
        
        cout<<"Use Keyboard to select the alogrithms you want to compare."<<endl;
        cout<<"HOLD SHIFT+\"KEY\" TO ADD YOUR OPTION"<<endl;
        cout<<"A.Bucket Sort"<<endl;
        cout<<"B.Comb Sort"<<endl;
        cout<<"C.Quick Sort (dual pointer)"<<endl;
        cout<<"D.Merge Sort"<<endl;
        cout<<"E.Heap Sort"<<endl;
        cout<<"F.Radix Sort (LSD)"<<endl;
        cout<<"G.Shell Sort"<<endl;
        cout<<"H.Gnome Sort"<<endl;
        cout<<"I.Cocktail Shaker Sort"<<endl;
        cout<<"J.Selection Sort"<<endl;
        cout<<"K.Bubble Sort"<<endl;
        cout<<"L.Insertion Sort"<<endl;
        cout<<"M.STL-Stable Sort"<<endl;
        cout<<"N.STL-Sort"<<endl;
        cout<<"-------------------------------------------------\n";
        cout<<"press ESC to finish your choice"<<endl;
        while(1){
            if (_kbhit()){                 //key check?
                ch = _getch();             //get key value
                if(ch == 27){
                    if (!algo_select.empty()){
                        system("cls");
                        cout<<"DONE!"<<endl;
                        break;
                    }
                    cout<<"Selection cannot be empty!!!!!"<<endl;
                }
                else if(ch == 65){
                    if (find(algo_select.begin(), algo_select.end(), 1) != algo_select.end()){
                        cout<<"Already in list!"<<endl;
                    }
                    else{
                        algo_select.push_back(1);
                        cout<<"A.Bucket Sort added!"<<endl;
                    }
                }
                if(ch == 66){
                    if (find(algo_select.begin(), algo_select.end(), 2) != algo_select.end()){
                        cout<<"Already in list!"<<endl;
                    }
                    else{
                        algo_select.push_back(2);
                        cout<<"B.Comb Sort added!"<<endl;
                    }
                }
                if(ch == 67){
                    if (find(algo_select.begin(), algo_select.end(), 3) != algo_select.end()){
                        cout<<"Already in list!"<<endl;
                    }
                    else{
                        algo_select.push_back(3);
                        cout<<"C.Quick Sort (dual pointer) added!"<<endl;
                    }
                }
                if(ch == 68){
                    if (find(algo_select.begin(), algo_select.end(), 4) != algo_select.end()){
                        cout<<"Already in list!"<<endl;
                    }
                    else{
                        algo_select.push_back(4);
                        cout<<"D.Merge Sort added!"<<endl;
                    }
                }
                if(ch == 69){
                    if (find(algo_select.begin(), algo_select.end(), 5) != algo_select.end()){
                        cout<<"Already in list!"<<endl;
                    }
                    else{
                        algo_select.push_back(5);
                        cout<<"E.Heap Sort added!"<<endl;
                    }
                }
                if(ch == 70){
                    if (find(algo_select.begin(), algo_select.end(), 6) != algo_select.end()){
                        cout<<"Already in list!"<<endl;
                    }
                    else{
                        algo_select.push_back(6);
                        cout<<"F.Radix Sort (LSD) added!"<<endl;
                    }
                }
                if(ch == 71){
                    if (find(algo_select.begin(), algo_select.end(), 7) != algo_select.end()){
                        cout<<"Already in list!"<<endl;
                    }
                    else{
                        algo_select.push_back(7);
                        cout<<"G.Shell Sort added!"<<endl;
                    }
                }
                if(ch == 72){
                    if (find(algo_select.begin(), algo_select.end(), 8) != algo_select.end()){
                        cout<<"Already in list!"<<endl;
                    }
                    else{
                        algo_select.push_back(8);
                        cout<<"H.Gnome Sort added!"<<endl;
                    }
                }
                if(ch == 73){
                    if (find(algo_select.begin(), algo_select.end(), 9) != algo_select.end()){
                        cout<<"Already in list!"<<endl;
                    }
                    else{
                        algo_select.push_back(9);
                        cout<<"I.Cocktail Shaker Sort added!"<<endl;
                    }
                }
                if(ch == 74){
                    if (find(algo_select.begin(), algo_select.end(), 10) != algo_select.end()){
                        cout<<"Already in list!"<<endl;
                    }
                    else{
                        algo_select.push_back(10);
                        cout<<"J.Selection Sort added!"<<endl;
                    }
                }
                if(ch == 75){
                    if (find(algo_select.begin(), algo_select.end(), 11) != algo_select.end()){
                        cout<<"Already in list!"<<endl;
                    }
                    else{
                        algo_select.push_back(11);
                        cout<<"K.Bubble Sort added!"<<endl;
                    }
                }
                if(ch == 76){
                    if (find(algo_select.begin(), algo_select.end(), 12) != algo_select.end()){
                        cout<<"Already in list!"<<endl;
                    }
                    else{
                        algo_select.push_back(12);
                        cout<<"L.Insertion Sort added!"<<endl;
                    }
                }
                if(ch == 77){
                    if (find(algo_select.begin(), algo_select.end(), 13) != algo_select.end()){
                        cout<<"Already in list!"<<endl;
                    }
                    else{
                        algo_select.push_back(13);
                        cout<<"M.STL-Stable Sort added!"<<endl;
                    }
                }
                if(ch == 78){
                    if (find(algo_select.begin(), algo_select.end(), 14) != algo_select.end()){
                        cout<<"Already in list!"<<endl;
                    }
                    else{
                        algo_select.push_back(14);
                        cout<<"N.STL-Sort added!"<<endl;
                    }
                }
                if (ch == 79){
                    system("cls");
                    cout<<"OH!You're finally here!"<<endl;
                    Sleep(1500);
                    cout<<"Let's have some fun!";
                    Sleep(1500);
                    cout<<"BOGO!!!!!!"<<endl;
                    Sleep(1500);
                    bogosort(data_array, n);
                    system("cls");
                    goto re;
                }

            }
        }
    cout<<"option code:";
    for (int i = 0; i < algo_select.size(); i++) {
        std::cout << algo_select.at(i) << ' ';
    }
    cout<<"\n";

    vector<int> data_vector(data_array, data_array + sizeof(data_array));

    for(int i=0;i<14;i++){
        if (algo_select.at(i) == 1){
                LARGE_INTEGER t1,t2,tc;
                QueryPerformanceFrequency(&tc);
                QueryPerformanceCounter(&t1);
                cout<<"Bucket sort:"<<endl;
                cout<<"Sorting..."<<endl;

                bucket_sort(data_array,n,findmax(data_array,n));

                QueryPerformanceCounter(&t2);
                double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
                cout<<"time = "<<time<<" s"<<endl;  //time output
                cout<<"Press any key to start next sorting"<<endl;
                cout<<"-----------------------------------------------------------------------------------"<<endl;
                system("pause");
                continue;
                    }
        else if (algo_select.at(i) == 2){
                LARGE_INTEGER t1,t2,tc;
                QueryPerformanceFrequency(&tc);
                QueryPerformanceCounter(&t1);
                cout<<"Comb sort:"<<endl;
                cout<<"Sorting..."<<endl;

                comb_sort(data_array, n);

                QueryPerformanceCounter(&t2);
                double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
                cout<<"time = "<<time<<" s"<<endl;  //time output
                cout<<"Press any key to start next sorting"<<endl;
                cout<<"-----------------------------------------------------------------------------------"<<endl;
                system("pause");
                continue;
                    }
        else if (algo_select.at(i) == 3){
                LARGE_INTEGER t1,t2,tc;
                QueryPerformanceFrequency(&tc);
                QueryPerformanceCounter(&t1);
                cout<<"Quick sort:"<<endl;
                cout<<"Sorting..."<<endl;

                quick_sort(data_array,0, n-1);

                QueryPerformanceCounter(&t2);
                double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
                cout<<"time = "<<time<<" s"<<endl;  //time output
                cout<<"Press any key to start next sorting"<<endl;
                cout<<"-----------------------------------------------------------------------------------"<<endl;
                system("pause");
                continue;
                    }
        else if (algo_select.at(i) == 4){
                LARGE_INTEGER t1,t2,tc;
                QueryPerformanceFrequency(&tc);
                QueryPerformanceCounter(&t1);
                cout<<"Merge sort:"<<endl;
                cout<<"Sorting..."<<endl;

                merge_sort(data_array, 0, n-1);

                QueryPerformanceCounter(&t2);
                double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
                cout<<"time = "<<time<<" s"<<endl;  //time output
                cout<<"Press any key to start next sorting"<<endl;
                cout<<"-----------------------------------------------------------------------------------"<<endl;
                system("pause");
                continue;
                    }
        else if (algo_select.at(i) == 5){
                LARGE_INTEGER t1,t2,tc;
                QueryPerformanceFrequency(&tc);
                QueryPerformanceCounter(&t1);
                cout<<"Heap sort:"<<endl;
                cout<<"Sorting..."<<endl;

                HeapSort(data_vector);

                QueryPerformanceCounter(&t2);
                double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
                cout<<"time = "<<time<<" s"<<endl;  //time output
                cout<<"Press any key to start next sorting"<<endl;
                cout<<"-----------------------------------------------------------------------------------"<<endl;
                system("pause");
                continue;
                    }
        else if (algo_select.at(i) == 6){
                LARGE_INTEGER t1,t2,tc;
                QueryPerformanceFrequency(&tc);
                QueryPerformanceCounter(&t1);
                cout<<"Radix sort:"<<endl;
                cout<<"Sorting..."<<endl;

                radixsort(data_array, n);

                QueryPerformanceCounter(&t2);
                double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
                cout<<"time = "<<time<<" s"<<endl;  //time output
                cout<<"Press any key to start next sorting"<<endl;
                cout<<"-----------------------------------------------------------------------------------"<<endl;
                system("pause");
                continue;
                    }
        else if (algo_select.at(i) == 7){
                LARGE_INTEGER t1,t2,tc;
                QueryPerformanceFrequency(&tc);
                QueryPerformanceCounter(&t1);
                cout<<"Shell sort:"<<endl;
                cout<<"Sorting..."<<endl;

                shell_sort(data_array, n);

                QueryPerformanceCounter(&t2);
                double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
                cout<<"time = "<<time<<" s"<<endl;  //time output
                cout<<"Press any key to start next sorting"<<endl;
                cout<<"-----------------------------------------------------------------------------------"<<endl;
                system("pause");
                continue;
                    }
        else if (algo_select.at(i) == 8){
                LARGE_INTEGER t1,t2,tc;
                QueryPerformanceFrequency(&tc);
                QueryPerformanceCounter(&t1);
                cout<<"Gnome sort:"<<endl;
                cout<<"Sorting..."<<endl;

                gnomeSort(data_array, n);

                QueryPerformanceCounter(&t2);
                double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
                cout<<"time = "<<time<<" s"<<endl;  //time output
                cout<<"Press any key to start next sorting"<<endl;
                cout<<"-----------------------------------------------------------------------------------"<<endl;
                system("pause");
                continue;
                    }
        else if (algo_select.at(i) == 9){
                LARGE_INTEGER t1,t2,tc;
                QueryPerformanceFrequency(&tc);
                QueryPerformanceCounter(&t1);
                cout<<"Cocktail Shaker sort:"<<endl;
                cout<<"Sorting..."<<endl;

                cock_sort(data_array, n);

                QueryPerformanceCounter(&t2);
                double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
                cout<<"time = "<<time<<" s"<<endl;  //time output
                cout<<"Press any key to start next sorting"<<endl;
                cout<<"-----------------------------------------------------------------------------------"<<endl;
                system("pause");
                continue;
                    }
        else if (algo_select.at(i) == 10){
                LARGE_INTEGER t1,t2,tc;
                QueryPerformanceFrequency(&tc);
                QueryPerformanceCounter(&t1);
                cout<<"Selection sort:"<<endl;
                cout<<"Sorting..."<<endl;

                selection_sort(data_array, n);

                QueryPerformanceCounter(&t2);
                double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
                cout<<"time = "<<time<<" s"<<endl;  //time output
                cout<<"Press any key to start next sorting"<<endl;
                cout<<"-----------------------------------------------------------------------------------"<<endl;
                system("pause");
                continue;
                    }

        else if (algo_select.at(i) == 11){
                LARGE_INTEGER t1,t2,tc;
                QueryPerformanceFrequency(&tc);
                QueryPerformanceCounter(&t1);
                cout<<"Bubble sort:"<<endl;
                cout<<"Sorting..."<<endl;

                bubble_sort(data_array, n);

                QueryPerformanceCounter(&t2);
                double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
                cout<<"time = "<<time<<" s"<<endl;  //time output
                cout<<"Press any key to start next sorting"<<endl;
                cout<<"-----------------------------------------------------------------------------------"<<endl;
                system("pause");
                continue;
                    }
        else if (algo_select.at(i) == 12){
                LARGE_INTEGER t1,t2,tc;
                QueryPerformanceFrequency(&tc);
                QueryPerformanceCounter(&t1);
                cout<<"Insertion sort:"<<endl;
                cout<<"Sorting..."<<endl;

                insertion_sort(data_array, n);

                QueryPerformanceCounter(&t2);
                double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
                cout<<"time = "<<time<<" s"<<endl;  //time output
                cout<<"Press any key to start next sorting"<<endl;
                cout<<"-----------------------------------------------------------------------------------"<<endl;
                system("pause");
                continue;
                    }
        else if (algo_select.at(i) == 13){
                LARGE_INTEGER t1,t2,tc;
                QueryPerformanceFrequency(&tc);
                QueryPerformanceCounter(&t1);
                cout<<"STL::sort:"<<endl;
                cout<<"Sorting..."<<endl;

                int *data_cpy1;
                data_cpy1 = new int[n];
                data_cpy1 = data_array;

                sort(data_cpy1,data_cpy1+n);

                QueryPerformanceCounter(&t2);
                double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
                cout<<"time = "<<time<<" s"<<endl;  //time output
                cout<<"Press any key to start next sorting"<<endl;
                cout<<"-----------------------------------------------------------------------------------"<<endl;
                system("pause");
                continue;
                    }  
        else if (algo_select.at(i) == 14){
                LARGE_INTEGER t1,t2,tc;
                QueryPerformanceFrequency(&tc);
                QueryPerformanceCounter(&t1);
                cout<<"STL::Stable_sort:"<<endl;
                cout<<"Sorting..."<<endl;

                int *data_cpy2;
                data_cpy2 = new int[n];
                data_cpy2 = data_array;

                stable_sort(data_cpy2,data_cpy2+n);

                QueryPerformanceCounter(&t2);
                double time=(double)(t2.QuadPart-t1.QuadPart)/(double)tc.QuadPart; 
                cout<<"time = "<<time<<" s"<<endl;  //time output
                cout<<"Press any key to start next sorting"<<endl;
                cout<<"-----------------------------------------------------------------------------------"<<endl;
                system("pause");
                continue;
                    }          


                }
        delete data_array;
                
        cout<<"endpoint reached"<<endl;
        system("pause");
        return 0;
}
    /*
    int ch;
    while (1){
        if (_kbhit()){
            ch = _getch();/
            cout << ch;
            if (ch == 27){ break; }
        }
    }
    */