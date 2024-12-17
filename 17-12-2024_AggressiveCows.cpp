/*
You are given an array with unique elements of stalls[], which denote the position of a stall. 
You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls 
to k cows such that the minimum distance between any two of them is the maximum possible.
*/

// using binary search concept
int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(),stalls.end());
    int end = stalls.back()-stalls.front();
    int ans=0,start=1;
    while(start<=end){            
        int mid = start+(end-start)/2;
        int cowcnt = 1;
        int prevpos = stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-prevpos>=mid){
                cowcnt++;
                prevpos=stalls[i];
            }
        }
        if(cowcnt>=k){
            ans=mid;
            start=mid+1;
        }
        else{
            end=mid-1;
        }
    }
    return ans;
}

//brute force approach (gives TLE)

int aggressiveCows(vector<int> &stalls, int k) {
    sort(stalls.begin(),stalls.end());
    int maxDist = stalls.back()-stalls.front();
    int ans=0;
    for(int dist=1;dist<=maxDist;dist++){
        int cowcnt = 1;
        int prevpos = stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-prevpos>=dist){
                cowcnt++;
                prevpos=stalls[i];
            }
        }
        if(cowcnt>=k) ans=dist;
    }
    return ans;
}