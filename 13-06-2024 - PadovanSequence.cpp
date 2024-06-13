int padovanSequence(int n) {
        int a=1;
        int b=1;
        int c=1;
        if(n<3) return 1;
        for(int i=3;i<=n;i++){
            int x=(a+b)%(1000000007);
            a=b;
            b=c;
            c=x;
        }
        return c;
    }