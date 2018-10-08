#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;


int peakfinder(long** mat, int row, int col, int **pos){
    int count = 0;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(mat[i][j]>=mat[i-1][j]&&
               mat[i][j]>=mat[i][j-1]&&
               mat[i][j]>=mat[i][j+1]&&
               mat[i][j]>=mat[i+1][j]){
                pos[count][0]=i;
                pos[count][1]=j;
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char* argv[]){

    //open file
    char inftmp[15] = "/matrix.data";
    char inf[30];
    strcpy(inf,argv[1]);
    strcat(inf,inftmp);

    ifstream inFile;
    inFile.open(inf);
    //setup matrix
    int row, col;    
    inFile >> row;
    inFile >> col;

    long **mat = new long*[row+2];
    for(int i = 0; i<row+2; i++)  mat[i] = new long[col+2];

    for(int j = 1; j<=row; j++)
        for(int k = 1; k<=col; k++)  inFile >> mat[j][k];
    inFile.close();

    //run func
    int **pos = new int*[1000000];
    for(int i=0;i<1000000;i++)   pos[i] = new int[2];
    int count = peakfinder(mat, row, col, pos);

    //for output to final.peak
    char oftmp[15] = "/final.peak";
    char of[30];
    strcpy(of,argv[1]);
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
