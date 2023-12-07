#include<bits/stdc++.h>
using namespace std;
class Sorting{
public:
    void printArray(int arr[], int s, int e){
        for(int i =0; i<= e; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void printArray(vector<int> arr, int s, int e){
        for(int i =0; i<= e; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // mergesort algorithm: 
    void mergeSort(int arr[], int s, int e){
        if(s>=e)
            return;
        int mid = s + (e-s)/2;
        int x[mid+1-s], y[e-mid];
        for(int i = 0; i<=mid-s; i++){
            x[i] = arr[s + i];
        }
        for(int i = 0; i<=e-mid-1; i++){
            y[i] = arr[mid + i + 1];
        }
        mergeSort(x, 0, mid-s);
        mergeSort(y, 0, e-mid-1);
        
        mergeArrays(x, y, arr, s, e);
    }
    void mergeArrays(int x[], int y[], int arr[], int s, int e){
        int mid = s + (e-s)/2, m = mid+1-s, n = e-mid, i = 0, j = 0, it = 0;
        while(it<m+n){
            if(i<m && j<n){
                if(x[i]<=y[j]){
                    arr[it] = x[i];
                    it++;
                    i++;
                }
                else{
                    arr[it] = y[j];
                    it++;
                    j++;
                }
            }
            else if(j==n){
                arr[it] = x[i];
                it++;
                i++;
            }
            else if(i==m){
                arr[it] = y[j];
                it++;
                j++;
            }
        }
    }

    /// quicksort algorithm: 5 3 1 6 7 | 4 : 4 | 3 1 6 7 5 : 3 1 | 4 | 6 7 5 
    void quickSort(int arr[], int s, int e){
        if(s>=e)
            return;
        int p = partition(arr, s, e);
        quickSort(arr, s, p-1);
        quickSort(arr, p+1, e);
    }
    int partition(int arr[], int s, int e){
        int pivot = arr[e], pivotInd = e;
        for(int j = 0; j<= e-1; j++){
            if(arr[j]>pivot && j < pivotInd){
                swap(arr[pivotInd], arr[j]);
                // arr[j] = arr[j]+pivot;
                // arr[pivotInd] = arr[j]-pivot;
                // arr[j] = arr[j]-pivot;
                pivotInd = j;
            }
            else if(arr[j]<pivot && j > pivotInd){
                swap(arr[pivotInd], arr[j]);
                // arr[j] = arr[j]+pivot;
                // arr[pivotInd] = arr[j]-pivot;
                // arr[j] = arr[j]-pivot;
                pivotInd = j;
            }
        } 
        return pivotInd;
    }
    void HeapifyUp(vector<int>& arr, int ind){
        if(ind == 0){
            return;
        }
        int pi = (ind%2==0)?((ind/2)-1):(ind/2);
        //cout << pi << " " << ind << endl;
        while(pi>=0){
            if(arr[pi]>arr[ind]){
                //cout << "Swapping " << arr[ind] << " and " << arr[pi] << endl;
                swap(arr[pi], arr[ind]);
                //printArray(arr, 0, arr.size()-1);
                ind = pi;
            }
            else{
                break;
            }
            int pi = (ind&1==0)?((ind-1)/2):(ind/2);
        }
    }
    void HeapifyDown(vector<int>& arr, int e){
        if(e==0){
            return;
        }
        int ind = 0, cL = 1, cR = 2;
        while(ind<=e){
            if(cR<=e && (arr[ind]>arr[cL] || arr[ind]>arr[cR])){
                if(arr[cL]>arr[cR]){
                    swap(arr[ind], arr[cR]);
                    ind = cR;
                }
                else{
                    swap(arr[ind], arr[cL]);
                    ind = cL;
                }
            }
            if(cR>e && cL<=e && (arr[ind]>arr[cL])){
                swap(arr[cL], arr[ind]);
                ind = cL;
            }
            if(cR>e && cL<=e && (arr[ind]<arr[cL])){
                return;
            }
            if(cR<=e && (arr[ind]<arr[cL] && arr[ind]<arr[cR])){
                return;
            }
            if(cL>e){
                return;
            }
            //printArray(arr, 0, e);
            cL = 2*ind + 1;
            cR = 2*ind + 2;
        }
        return;
    }
    void HeapSort(vector<int>& arr){
        int n = arr.size();
        if(n==0 || n==1){
            return;
        }
        int s = 0, e = n-1;
        //cout << "Heapify Up" << endl;
        for(int i = 1; i<=n-1; i++){
            HeapifyUp(arr, i);
            //printArray(arr, 0, n-1);
        }
        //cout << "Heapify Down" << endl;
        for(int i = 0; i< n; i++){
            swap(arr[0], arr[e]);
            HeapifyDown(arr, e-1);
            e--;
            //printArray(arr, 0, n-1);
        }
    }
 };
 /*
 5 3 1 6 7 : 4 | 5
 4 : 3 1 6 7 5 | 5<->0
 3 : 4 : 1 6 7 5 | 0<->1
 3 1 : 4 : 6 7 5 | 1<->2
*/
int main(){
    Sorting srt;
    vector<int> v;
    int n;
    cin>>n;
    for(int i = 0; i< n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    srt.HeapSort(v);
    srt.printArray(v, 0, n-1);
    return 0;
}
