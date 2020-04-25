// Use pointer that goes down when meets zero and left when meets one. 

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:

    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        vector<int> dim = binaryMatrix.dimensions();
        int c = dim[1] - 1;
        int r = 0;
        int ret = -1;
        
        while (r < dim[0] && c >= 0){
            if (binaryMatrix.get(r, c) == 1){
                ret = c;
                c--;
            }
            else {
                r++;
            }
        }
        
        return ret;

    }
};
