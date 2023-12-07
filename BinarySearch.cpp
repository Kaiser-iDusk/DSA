#include<bits/stdc++.h>
using namespace std;
class BinarySearch{
public:
    int firstOccur(vector<int> &v, int target){
        int n = v.size(), start = 0, end = n-1, ans = -1, mid;
        while(start<=end){
            mid = start + (end - start)/2;
            if(v[mid] == target){
                ans = mid;
                end = mid-1;
            }
            else if(v[mid]< target){
                start = mid+1;
            }
            else if(v[mid]> target){
                end = mid-1;
            }
        } 
        return ans;
    }
    int lastOccur(vector<int> &v, int target){
        int n = v.size(), start = 0, end = n-1, ans = -1, mid;
        while(start<=end){
            mid = start + (end - start)/2;
            if(v[mid] == target){
                ans = mid;
                start = mid+1;
            }
            else if(v[mid]< target){
                start = mid+1;
            }
            else if(v[mid]> target){
                end = mid-1;
            }
        } 
        return ans;
    }
    int rotSortArr(vector<int> &v, int target){
        int n = v.size(), start = 0, end = n-1, ans = -1, left = v[0], right = v[n-1];
        while(start<=end){
            int mid = start + (end - start)/2;
            if(v[mid] == target){
                ans = mid;
                return mid;
            }
            else if(v[mid] < target && target >=left){
                end = mid-1;
            }
            else if(v[mid] < target && target <=right){
                start = mid+1;
            }
            else if(v[mid] > target && target >=left){
                end = mid-1;
            }
            else if(v[mid] > target && target <=right){
                start = mid+1;
            }
        } 
        return ans;
    }
};