//Bobokulov Asilbek 230092 FCS1
//CS 111 Data Structures and Algorithms
#include<bits/stdc++.h>
using namespace std;
int part(vector<int> &vec, int low, int high){
    int pivot = vec[high];
    int i = low - 1;
    for(int j = low; j <= high; j++){
        if(vec[j] < pivot){
            i ++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[++i], vec[high]);
    return i;
}
void quickSort(vector<int> &vec, int low, int high){
    if(low < high){
        int p = part(vec, low, high);
        quickSort(vec, low, p - 1);
        quickSort(vec, p + 1, high);
    }
}
int main()
{
    int n, mn = INT_MAX; cin >> n;
    vector<int> vec(n);
    for(auto &x:vec) cin >> x;
    quickSort(vec, 0, n - 1);
    for(int i = 0; i < n - 1; i++){
        mn = min(mn, vec[i+1] - vec[i]);
    }
    for(int i = 0; i < n - 1; i++){
        if(vec[i+1] - vec[i] == mn) cout << vec[i] << ' ' << vec[i+1] << '\n';
    }
}