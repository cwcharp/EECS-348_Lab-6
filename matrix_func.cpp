#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <limits>

using namespace std;

// Function to read matrices from file, takes filename, 2D vectors mat1 and mat2, and size as parameters
void get_mat(const string& filename, vector<vector<int>>& mat1, vector<vector<int>>& mat2, int& size) {
    // Create file object by opening file
    ifstream file(filename);
    // If file was not opened successfully then exit program
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        exit(1);
    }
    // Reads first line of file and stores int value in size
    file >> size;
    // Uses resize() to change the size of mat1 and mat2 using value read for size
    mat1.resize(size, vector<int>(size));
    mat2.resize(size, vector<int>(size));
    // Iterates through mat1 row and col and reads corresponding value from file into curent position
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> mat1[i][j];
        }
    }
    // Iterates through mat2 row and col and reads corresponding value from file into curent position
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> mat2[i][j];
        }
    }
    // Close the file
    file.close();
}



// Function to print matrix, takes 2D vector as parameter
void print_mat(const vector<vector<int>>& mat) {
    // Create int size variable equal to size of mat using size()
    int size = mat.size();
    // Iterates through all mat row and col
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            //Print current iteration of row and col with 5 spaces for padding using setw(5)
            cout << setw(5) << mat[i][j];
        }
        // After printing all elements in a row go to next line using endl
        cout << endl;
    }
}




// Function to add two matrices, takes two 2D vectors as parameters
vector<vector<int>> add_mat(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    // Create int size variable equal to size of mat using size()
    int size = mat1.size();
    // Create 2D vector variable equal to size of mats to store answer
    vector<vector<int>> result(size, vector<int>(size));
    // Iterate through all row and col of mat1 and mat2 and add the current iterations together and set result[i][j] equal to sum
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    // Return resulting 2D vector
    return result;
}




// Function to multiply two matrices, takes two 2D vectors as parameters
vector<vector<int>> mult_mat(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    // Create int size variable equal to size of mat using size()
    int size = mat1.size();
    // Create 2D vector variable equal to size of mats to store answer
    vector<vector<int>> result(size, vector<int>(size));
    // Iterate through all row and col of mat1 and mat2 and multiply the current iterations together and set result[i][j] equal to product
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    // Return resulting 2D vector
    return result;
}




// Function to subtract one matrix from another, takes two 2D vectors as parameters
vector<vector<int>> sub_mat(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    // Create int size variable equal to size of mat using size()
    int size = mat1.size();
    // Create 2D vector variable equal to size of mats to store answer
    vector<vector<int>> result(size, vector<int>(size));
    // Iterate through all row and col of mat1 and mat2 and subtract the current iterations and set result[i][j] equal to difference
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    // Return resulting 2D vector
    return result;
}




// Function to update value of matrix, takes matrix, col, row, and new value as parameters
vector<vector<int>> update_mat(vector<vector<int>>& mat, int row, int col, int newValue) {
    // Create int size variables equal to size of mat using size()
    int numRows,numCols = mat.size();
    // Check if row and column indices are valid
    if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
        // If indices are valid say matrix successfully and print new matrix
        mat[row][col] = newValue;
        cout << "\nMatrix updated successfully." << endl;
        cout << "\nMatrix with updated value:\n" << endl;
        print_mat(mat);
    } else {
        // If indices are invalid say so
        cout << "\nInvalid row or column index." << endl;
    }
    //Return updated matrix
    return mat;
}




// Function to get maximum value in matrix, takes 2D vector as parameters
int get_max(const vector<vector<int>>& mat) {
    // Create maxVal variable using numeric_limits to make sure any value will be greater than maxVal at first
    int maxVal = std::numeric_limits<int>::min();
    // Iterate through the matrix row and col to find the maximum value
    for (const auto& row : mat) {
        for (int value : row) {
            if (value > maxVal) {
                maxVal = value;
            }
        }
    }
    // Return the maximum value in matrix
    return maxVal;
}




// Function to compute the transpose of a matrix, takes 2D vector as parameter
vector<vector<int>> transpose_mat(const vector<vector<int>>& mat) {
    // Create variables for the number of rows and cols
    int numRows = mat.size();
    int numCols = mat[0].size();
    // Create a new matrix to store the transpose
    vector<vector<int>> transpose(numCols, vector<int>(numRows));
    // Iterate through all rows and cols of matrix to find transpose
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            transpose[j][i] = mat[i][j];
        }
    }
    // Return the transposed matrix
    return transpose;
}




// Main function
int main() {
    vector<vector<int>> mat1, mat2, result;
    int size;

    // Read matrices from file using get_mat function
    get_mat("matrix_input.txt", mat1, mat2, size);
    cout << "Matrix 1:\n" << endl;
    print_mat(mat1);
    cout << "\nMatrix 2:\n" << endl;
    print_mat(mat2);

    // Add matrices
    result = add_mat(mat1, mat2);
    // Print result of addition
    cout << "\nResult from adding the matrices:\n" << endl;
    print_mat(result);

    // Multiply matrices
    result = mult_mat(mat1, mat2);
    // Print result of multiplication
    cout << "\nResult from multiplying the matrices:\n" << endl;
    print_mat(result);

    // Subtract second matrix from the first
    result = sub_mat(mat1, mat2);
    // Print result of subtraction
    cout << "\nResult from subtracting the second matrix from the first:\n" << endl;
    print_mat(result);

    // Update value of matrix and print if valid
    update_mat(mat1, 1, 1, 100);

    // Find max value of matrix
    int max_val = get_max(mat1);
    // Print maximum value in matrix
    cout << "\nMatrix maximum value:\n\n" << max_val << endl;

    // Compute the transpose of the matrix
    result = transpose_mat(mat1);
    cout << "\nResult from transposing the matrix:\n" << endl;
    print_mat(result);

    return 0;
}
