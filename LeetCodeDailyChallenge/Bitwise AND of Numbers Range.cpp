class Solution {
public:
    
    int MSB(int n){
        int count = -1;
        while (n != 0){
            n = n >> 1;
            count++;
        }
        
        return count;
    }
    
    int rangeBitwiseAnd(int m, int n) {

        int msb1 = MSB(m);
        int msb2 = MSB(n);

        int ret = 0;
        while (msb1 == msb2 && msb1 >= 0) {

            ret = ret | (0x01 << msb1);
            int mask = ~((int)0x01 << msb1);

            m = m & mask;
            n = n & mask;

            msb1 = MSB(m);
            msb2 = MSB(n);

        }

        return ret;
    }
};
