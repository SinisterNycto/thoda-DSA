#include <bits/stdc++.h>
using namespace std;

// induction code
// insert element in sorted array
void insertVal(vector<int> &arr, int val){
    if(arr.size() == 0 || arr[arr.size() - 1] <= val){
        arr.push_back(val);
        return;
    }

    int temp = arr[arr.size() - 1]; // remove last element temporarily, to find correct pos of val
    arr.pop_back();

    insertVal(arr, val); // find correct position in smaller input
    arr.push_back(temp);

}

void recursiveSort(vector<int> &arr){
    // base cond(if one element then already sorted)
    if(arr.size() == 1){
        return;
    }

    // hypothesis(remove last element and sort the remaining array)

    int lastVal = arr[arr.size() - 1];
    arr.pop_back();

    recursiveSort(arr);

    // induction(insert removed element correctly)
    insertVal(arr, lastVal);
}

int main() {
    vector<int> arr = {5, 3, 2, 6, 1};
    
    recursiveSort(arr);

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    return 0;
}
