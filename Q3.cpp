#include <iostream>
using namespace std;

int recursiveArraySum(int** matrix, int* colSizes,int dim,int sum,int rows){
    if (dim==rows)
    {
        return sum;
    }
    for (int i = 0; i < colSizes[dim]; i++)
    {
        sum = sum+matrix[dim][i];
    }
    return recursiveArraySum(matrix,colSizes,dim+1,sum,rows);
    
}


int main() {

    int sum = 0;

   int rows;
   int columns;
   cout << "Enter the number of rows" << endl;
   cin >> rows;

   int** matrix = new int*[rows];

   int* colSizes = new int[rows]; //This will store the number of columns at each rows

   for (int i = 0; i < rows; i++)
   {
    cout << "Enter the number of columns for row " << i+1 << endl;
    cin >> columns ;
    colSizes[i] = columns;
    matrix[i] = new int[columns];
   }


   //Initialising the array with random values
   for (int i = 0; i < rows; i++)
   {
    for (int j = 0; j < colSizes[i]; j++)
    {
        matrix[i][j] = j;
    }
   }


   int result = recursiveArraySum(matrix,colSizes,0,0,rows);
   cout << "The output of sum of all elements in the array is " << result << endl;

   for (int i = 0; i < rows; i++)
   {
    
    delete[] matrix[i];
   }

   delete[] matrix;
   delete[] colSizes;

   return 0;
}