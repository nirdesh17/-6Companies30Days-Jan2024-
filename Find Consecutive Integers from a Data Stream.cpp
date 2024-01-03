class DataStream {
public:
    int val=0,kmax=0;
    int cnt=0;
    DataStream(int value, int k) {
        val=value;
        kmax=k;
    }
    
    bool consec(int num) {
        if(num==val)
            cnt++;
        else
            cnt=0;
        
        return cnt>=kmax;
    }
};