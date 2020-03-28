/*Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square
/*matrix (mat[][]). The task to print a solved Sudoku. For simplicity you may
/*assume that there will be only one unique solution.*/

#include <iostream>
using namespace std;

int sudoku[9][9];

bool safeCell(int digit, int r, int c){
    
    int cell_r = r - (r % 3);
    int cell_c = c - (c % 3);
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (sudoku[cell_r + i][cell_c + j] == digit)
                return false;
        }
    }
    
    return true;
}

bool safeColumn(int digit, int c){
    
    for (int i = 0; i < 9; i++){
        if (sudoku[i][c] == digit) return false;
    }
    
    return true;
}

bool safeRow(int digit, int r){
    
    for (int j = 0; j < 9; j++){
        if (sudoku[r][j] == digit) return false;
    }
    
    return true;
}

bool safe(int digit, int r, int c){
    
    if (safeCell(digit, r, c) && safeRow(digit, r) && safeColumn(digit, c))
        return true;
        
    return false;
}

bool solved(){
    
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (sudoku[i][j] == 0){
                
                for (int digit = 1; digit <= 9; digit++){
                    if (safe(digit, i, j)){
                        sudoku[i][j] = digit;
                        if (solved())
                            return true;
                        else 
                        sudoku[i][j] = 0;
                    }
                }
                
                return false;
            }
        }
    }

    return true;
}

void readSudoku(){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++)
            cin >> sudoku[i][j];
    }
}

void printSudoku(){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++)
            cout << sudoku[i][j] << " ";
    }
    cout << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--){
	    readSudoku();
	    solved();
	    printSudoku();
	}
	return 0;
}