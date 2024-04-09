//Bobokulov Asilbek 230092 FCS1
//CS 111 Data Structures and Algorithms
#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> &vec, int low, int high){
    int pivot = vec[high];
    int i = low - 1;
    for(int j = low; j <= high; j++){
        if(vec[j] < pivot){
            i ++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i+1], vec[high]);
    return i + 1;
}
void quickSort(vector<int> &vec, int low, int high){
    if(low < high){
        int p = partition(vec, low, high);
        quickSort(vec, low, p - 1);
        quickSort(vec, p + 1, high);
    }
}
int main()
{
    int n; cin >> n;
    vector<int> even, odd, vec;
    for(int i = 0; i < n; i++){
        int x; cin >> x; //vec.push_back(x);
        if(i % 2) odd.push_back(x);
        else even.push_back(x);
    }
    //quickSort(vec, 0, n - 1);
    //for(auto x:vec) cout << x << ' ';
    quickSort(odd, 0, odd.size() - 1);
    quickSort(even, 0, even.size() - 1);
    reverse(even.begin(), even.end());
    //for(auto x:even) cout << x << ' ';
    for(int i = 0; i < n; i++){
        cout << (i % 2 ? odd[(i-1)/2] : even[i/2]) << ' ';
    }
}