#include <iostream>
#include <vector>

using namespace std;
void quicksort(vector<int> &v, int begin, int end);
int helper(vector <int> &v, int begin, int end);

int main(){
    vector<int> v = {4 , 5 , 1 , 7 , 6};
    quicksort(v,0,v.size()-1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}

void quicksort(vector<int> &v,int begin, int end){
    if(end <= begin) return;
    int pivot = helper(v,begin,end);
    quicksort(v,0,pivot-1);
    quicksort(v,pivot + 1,end);
}

int helper(vector<int> &v, int begin, int end){
    int pivot = v[end];
    int i = begin - 1;
    int j = begin;
    while(j <= end-1){
        if(v[j] < pivot){
            i++;
            int temp = v[j];
            v[j] = v[i];
            v[i] = temp;
        }
        j++;
    }
    i++;
    int temp = v[j];
        v[j] = v[i];
        v[i] = temp;

    return i;
}

