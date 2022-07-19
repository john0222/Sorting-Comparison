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
int *data_array;       //declear a pointer for datasets
vector <int> algo_select = {}; //declear a vector for algorithms selection buffer 

int findmax(int arr[], int n){
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

            }
        }
    cout<<"option code:";
    for (int i = 0; i < algo_select.size(); i++) {
        std::cout << algo_select.at(i) << ' ';
    }
    cout<<"\n";


    cout<<"endpoint reached"<<endl;
    system("pause");
	return 0;
}
    /*int ch;
    while (1){
        if (_kbhit()){//如果有按键按下，则_kbhit()函数返回真
            ch = _getch();//使用_getch()函数获取按下的键值
            cout << ch;
            if (ch == 27){ break; }//当按下ESC时循环，ESC键的键值时27.
        }
    }
    */