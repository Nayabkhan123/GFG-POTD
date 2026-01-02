/*
    Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.
    Note: You need to solve this problem without utilizing the built-in sort function.

    Examples:

    Input: arr[] = [0, 1, 2, 0, 1, 2]
    Output: [0, 0, 1, 1, 2, 2]
    Explanation: 0s, 1s and 2s are segregated into ascending order.
*/

// Dutch National Flag Algorithm 
void sort012(vector<int>& arr) {
    int n=arr.size();
    int i=0,j=n-1,k=0;
    while(k<=j){
        if(arr[k]==0){
            swap(arr[k++],arr[i]);
            i++;
        }
        else if(arr[k]==2){
            swap(arr[k],arr[j]);
            j--;
        }
        else k++;
    }
    
}
// sorting
void sort012(vector<int> &arr) {    
    sort(arr.begin(), arr.end()); 
}

// we can count 0's, 1's and 2's also