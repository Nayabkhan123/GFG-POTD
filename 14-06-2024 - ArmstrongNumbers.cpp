 string armstrongNumber(int n) {
      
        int sum=0;
        int m=n;
        while(m){
            int digit = m % 10;
            m=m/10;
            sum+=pow(digit,3);
            
        }
        
        if(sum==n) return "true";
        else{
            return "false";
        }
    }