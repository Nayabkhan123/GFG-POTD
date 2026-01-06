/*
    Given an array of integers arr[]  and a number k. Return the maximum xor of a subarray of size k.

    Note: A subarray is a contiguous part of any given array.

    Examples:

    Input: arr[] = [2, 5, 8, 1, 1, 3], k = 3
    Output: 15
    Explanation: arr[0] ^ arr[1] ^ arr[2] = 15, which is maximum.
*/

// Sliding Window
int maxSubarrayXOR(vector<int>& arr, int k) {
    int n=arr.size();
    int maxsum=0;
    int currxor=0;
    for(int i=0;i<k-1;i++){
        currxor^=arr[i];
    }
    for(int i=k-1;i<n;i++){
        currxor ^= arr[i];
        maxsum=max(maxsum,currxor);
        currxor ^= arr[i-k+1];
    }
    return maxsum;
} 

// Brute Force Approach
int maxSubarrayXOR(vector<int>& arr, int k) {
    int n=arr.size();
    int maxsum=0;
    for(int i=0;i<=n-k;i++){
        int temp=0;
        for(int j=i;j<i+k;j++){
            temp ^= arr[j];
        }
        maxsum=max(maxsum,temp);
    }
    return maxsum;
}