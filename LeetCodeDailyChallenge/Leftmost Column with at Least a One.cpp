// Binary search on each row

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
    int getMostLeftOneInRow(BinaryMatrix *binaryMatrix, int row, int colNum){
        
        int left = 0, right = colNum - 1;
        
        int ret = colNum;
        
        while (left <= right){
            int mid = (right + left) / 2;
            
            if (binaryMatrix->get(row, mid) == 1){
                ret = mid;
                right = mid - 1;
            }
            else 
                left = mid + 1;
        }
        
        return ret;
    }
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        
        vector<int> dim = binaryMatrix.dimensions();
        
        int closest = dim[1];
        
        for (int i = 0; i < dim[0]; i++){
            
            int rowClosest = getMostLeftOneInRow(&binaryMatrix, i, dim[1]);
            
            if (rowClosest < closest)
                closest = rowClosest;
        }
        
        return closest == dim[1] ? -1 : closest;
    }
};
