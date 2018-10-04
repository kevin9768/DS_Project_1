#include<iostream>
#include<fstream>

using namespace std;


void peakfinder(int** mat, int row, int col, int **pos, int*max, int*count){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(mat[i][j]>*max){
                *count = 0;
                *max = mat[i][j];
                pos[*count][0]=i;
                pos[*count][1]=j;
            }
            else if(mat[i][j]==*max){
                count++;
                pos[*count][0]=i;
                pos[*count][1]=j;
            }
        }
    }
}

int main(){
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
    
    int max=0;
    int count=0;
    int *m=&max;
    int *c=&count;

    
    int **pos = new int*[10];
    for(int i=0;i<10;i++)   pos[i] = new int[2];
    peakfinder(mat, row, col, pos, m, c);
    
    
    cout<<count<<endl;
    for(int i=0;i<count;i++){
        cout<< pos[i][0] << ' ' <<pos[i][1]<<endl;
    }
}
