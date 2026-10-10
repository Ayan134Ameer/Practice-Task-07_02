#include <iostream>
using namespace std;

bool FindPath(int arr[][5],int SolArr[][5],int row,int col){
    if (row==4 && col==4)
    {
        SolArr[row][col] = 2;
        return true;
    }
    
    if (row<0||row>=5||col<0||col>=5||arr[row][col]==0)
    {
        return false;
    }
    SolArr[row][col] = 2;
    
    if (FindPath(arr,SolArr,row,col+1)==true)
    {
        return true;
    }
    return FindPath(arr,SolArr,row+1,col);


}


int main() {
   int ROWS = 5;
   int COLS = 5;

   int arr[5][5];
   int SolArr[5][5];

   for (int i = 0; i < ROWS; i++)
   {
    for (int j = 0; j < COLS; j++)
    {
        arr[i][j] = 1;
        SolArr[i][j] = 0;
    }
   }

   arr[0][1] = 0;
   arr[0][3] = 0;
   arr[2][0] = 0;
   arr[2][2] = 0;
   arr[3][1] = 0;
   arr[3][2] = 0;
   arr[4][3] = 0;

   FindPath(arr,SolArr,0,0);
   //Display array

   for (int i = 0; i < ROWS; i++)
   {
    for (int j = 0; j < COLS; j++)
    {
        cout << SolArr[i][j] << "|";
    }
    cout << endl;
   }
   
   

   return 0;
}