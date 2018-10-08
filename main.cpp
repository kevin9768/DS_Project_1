#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;


void peakfinder(long** mat, int row, int col, int **pos, int*count){
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
    char inftmp[15];
    strcpy(inftmp,"/matrix.data");
    char inf[30];
    strcpy(inf,argv[1]);
    strcat(inf,inftmp);

    ifstream inFile;
    inFile.open(inf);
    if(!inFile) cout<< '.';

    int row, col;
    
    inFile >> row;
    inFile >> col;

    //cout << row << ' ' << col << endl;

    long **mat = new long*[row+2];
    for(int i = 0; i<row+2; i++)  mat[i] = new long[col+2];

    for(int j = 1; j<=row; j++)
        for(int k = 1; k<=col; k++)  inFile >> mat[j][k];
    inFile.close();
    
    int count=0;
    int *c=&count;

    int **pos = new int*[1000000];
    for(int i=0;i<1000000;i++)   pos[i] = new int[2];
    
    peakfinder(mat, row, col, pos, c);
    
    char of[30];
    strcpy(of,argv[1]);
    char oftmp[15];
    strcpy(oftmp,"/final.peak");
    strcat(of,oftmp);
    ofstream outFile;
    outFile.open(of);
    
    outFile<<count<<endl;
    for(int i=0;i<count;i++){
        outFile<< pos[i][0] << ' ' <<pos[i][1]<<endl;
    }
    outFile.close();

    //free
    for(int i=0; i<row+2; i++)  delete[] mat[i];   
    delete[] mat;

    for(int i=0; i<1000000; i++)    delete[] pos[i];
    delete[] pos;
}