// 1st method 
void matchPairs(int n, char nuts[], char bolts[]) {
        sort(nuts,nuts+n);
        sort(bolts,bolts+n);
    }
// 2nd method  
void matchPairs(int n, char nuts[], char bolts[]) {
        char temp[9]={'!','#','$','%','&','*','?','@','^'};
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[nuts[i]]++;
        }
        int j=0;
        for (int i=0;i<9;i++){
            if(mp[temp[i]]){
                nuts[j]=temp[i];
                bolts[j]=temp[i];
                j++;
            }
        }
    }