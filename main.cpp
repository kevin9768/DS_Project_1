#include<iostream>
#include<fstream>

using namespace std;


void peakfinder(int** mat, int row, int col, int **pos, int*count){
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(mat[i][j]>=mat[i-1][j]&&
               mat[i][j]>=mat[i][j-1]&&
               mat[i][j]>=mat[i][j+1]&&
               mat[i][j]>=mat[i+1][j]){
                pos[*count][0]=i;
                pos[*count][1]=j;
                (*count) += 1;
            }
        }
    }
    return;
}

int main(int argc, char* argv[]){
    char tmp[20] = "/matrix.data";
    strcat(argv[1],tmp);

    ifstream inFile;
    inFile.open(argv[1]);
    if(!inFile) cout<< '.';

    int row, col;
    
    inFile >> row;
    inFile >> col;

    //cout << row << ' ' << col << endl;

    int **mat = new int*[row+2];
    for(int i = 0; i<row+2; i++)  mat[i] = new int[col+2];

    for(int j = 1; j<=row; j++)
        for(int k = 1; k<=col; k++)  inFile >> mat[j][k];
    inFile.close();
    
    int count=0;
    int *c=&count;

    int **pos = new int*[10];
    for(int i=0;i<10;i++)   pos[i] = new int[2];
    
    peakfinder(mat, row, col, pos, c);
    
    
    cout<<count<<endl;
    for(int i=0;i<count;i++){
        cout<< pos[i][0] << ' ' <<pos[i][1]<<endl;
    }
}
