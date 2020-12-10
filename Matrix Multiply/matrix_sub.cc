#include "matrix.h"

// to open data files
void open_files(ifstream &is1, ifstream &is2){
  // Trying to open FILE1 and FILE2
  is1.open(FILE1);
  is2.open(FILE2);

  // If FILE1 can't opened, display an error
  if(!is1){
    cerr << "Error! Can't open file: " << FILE1 << endl;
    exit(1); // abort the program with a non-zero exit value
  }
  // If FILE2 can't be opened, display an error
  if(!is2){
    cerr << "Error! Can't open file: " << FILE2 << endl;
    exit(1); // abort the program with a non-zero value
  }
}

// to read contents of data files
void read_data(ifstream &is, vector<vector<int>> &m){
  for(size_t i=0; i < m.size(); i++){ // loop for the number of rows
    for(size_t j=0; j < m[i].size(); j++){ // loop for the number of columns
      is >> m[i][j]; // reading data into the matrix
    }
  }
}

// to print contents of all matrices
void print_data(const vector<vector<int>> &m){
  cout << m.size() << " x " << m[0].size() << endl; // displaying a size of the matrix shown bellow
  cout << "--------------------------------------------------------------------------" << endl;

  for(size_t i=0; i < m.size(); i++){ // loop for the number of rows
    for(size_t j=0; j < m[i].size(); j++){ // loop for the numbers of columns
      cout << setw(ITEM_W) << m[i][j]; // Prints the contents of on stdout by allocating ITEM_W spaces for each integer value
    }
    cout << "\n";
  }
}

// to generate a matrix by multiplying two input matrices
void gen_data(const vector<vector<int>> &A, const vector<vector<int>> &B, vector<vector<int>> &C){
  for(size_t i=0; i < A.size(); i++){ // loop for the number of rows in the matrix A
    for(size_t j=0; j < B[i].size(); j++){ // loop for the number of columns in the matrix B
      C[i][j] = 0;
      for(size_t k=0; k < A[i].size(); k++){ // loop over the number of columns in the matrix A

	C[i][j] += A[i][k] * B[k][j]; // multiplying 1st and 2nd matrices and storing it in C
      }
    }
  }
}
  
