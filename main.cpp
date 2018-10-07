#include<iostream>
#include<fstream>
#include<string>

using namespace std;


void peakfinder(int** mat, int row, int col, int **pos, int*count){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]>=mat[i-1][j]&&
               mat[i][j]>=mat[i][j-1]&&
               mat[i][j]>=mat[i][j+1]&&
               mat[i][j]>=mat[i+1][j]){
                pos[*count][0]=i;
                pos[*count][1]=j;
                count+=4;
            }
        }
    }
    return;
}

int main(int argc, char* argv[]){
    char cmd[20] = "cd ";
    strcat(cmd, argv[1]);
    system(cmd);

    ifstream inFile("matrix.data" , ios::in);
    if(!inFile) cout<< '.';

    int row, col;
    
    inFile >> row;
    inFile >> col;

    //cout << row << ' ' << col << endl;

    int **mat = new int*[row];
    for(int i = 0; i<row; i++)  mat[i] = new int[col];

    for(int j = 0; j<row; j++){
        for(int k = 0; k<col; k++){
            inFile >> mat[j][k];
            //cout << mat[j][k] <<' ';
        }
        //cout << endl;
    }
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
