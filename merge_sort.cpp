#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v,int low, int mid, int high){
    int n1 = mid-low+1;
    int n2 = high-mid;

    vector<int> left(n1);
    vector<int> right(n2);

    for(int i=0;i<n1;i++){
        left[i]=v[low+i];
    }
    for(int i=0;i<n2;i++){
        right[i]=v[mid+1+i];
    }
    int i=0,j=0,k=low;
    while(i < n1 && j < n2){
        if(left[i]<=right[j]){
            v[k] = left[i];
            i++;
        }
        else{
            v[k] = right[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        v[k]=left[i];
        i++;
        k++;
    }

    while(j < n2){
        v[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> &v, int low, int high){
   
   if(low >= high){
        return;
   }
        int mid = low + (high-low)/2;
        merge_sort(v,low,mid);
        merge_sort(v,mid+1,high);
        merge(v,low,mid,high);  
}


int main(){
    vector<int> vec = {9,7,5,3,8,6,4,2};
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
        
    }
    merge_sort(vec,0,vec.size()-1);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
    return 0;
}
