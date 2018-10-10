#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

bool isPeak(long* a1, long* a2, long* a3, int j, int col);
bool isPeakS(long* a1, long* a2, int j, int col){
    if(j==1){
        if(a1[j]>=a1[j+1]&&a1[j]>=a2[j])    return true;
        else return false;
    }
    else if(j==col){
        if(a1[j]>=a1[j-1]&&a1[j]>=a2[j])    return true;
        else return false;
    }
    else{
        if(a1[j]>=a1[j-1]&&a1[j]>=a1[j+1]&&a1[j]>=a2[j])    return true;
        else return false;
    }
}
bool isPeakE(long* a1, long* a2, int j, int col);

int main(int argc, char* argv[]){
    //open file
    char inftmp[15] = "/matrix.data";
    char inf[30];
    strcpy(inf,argv[1]);
    strcat(inf,inftmp);
    ifstream inFile;
    inFile.open(inf);

    //open output file for storing pos
    char oftmp[15] = "/tmp.peak";
    char of[30];
    strcpy(of,argv[1]);
    strcat(of,oftmp);
    ofstream outFile;
    outFile.open(of);

    //get row&col;
    int row,col;
    inFile>>row>>col;

    //setup buffers for peakfinding
    long b1[col+1], b2[col+1], b3[col+1];

    //start peak finding
    int count = 0;
    int i = 1;
    while(i<=row){
        if(i%3==1){
            for(int a=1; a<=col; a++){
                inFile>>b1[a];
            }
            if(i==1){
                i++;
                continue;
            }
        }
        else if(i%3==2){
            if(i==2){
                for(int a=1; a<=col; a++){
                    inFile>>b2[a];
                    isPeakS(b1,b2,a,col);
                }
                i++;
                continue;
            }
            for(int a=1; a<=col; a++){
                inFile>>b2[a];
            }
        }
        else if(i%3==0){
            for(int a=1; a<+col; a++){
                inFile>>b3[a];
            }
        }
        i++;
    }
    //deal with last row
}