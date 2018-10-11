#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

bool isPeak(long* a1, long* a2, long* a3, int j, int col){ //a1 top, a2 mid, a3 bot
    if(j==1){
        if(a2[j]>=a1[j]&&a2[j]>=a3[j]&&a2[j]>=a2[j+1])  return true;
        else return false;
    }
    else if(j==col){
        if(a2[j]>=a1[j]&&a2[j]>=a3[j]&&a2[j]>=a2[j-1])  return true;
        else return false;
    }
    else{
        if(a2[j]>=a1[j]&&a2[j]>=a3[j]&&a2[j]>=a2[j+1]&&a2[j]>=a2[j-1])  return true;
        else return false;
    }
}
bool isPeakS(long* a1, long* a2, int j, int col){//a1 top, a2 bot for the start
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
bool isPeakE(long* a1, long* a2, int j, int col){//a1 top, a2 bot for the end
    if(j==1){
        if(a2[j]>=a1[j]&&a2[j]>=a2[j+1])    return true;
        else return false;
    }
    else if(j==col){
        if(a2[j]>=a1[j]&&a2[j]>=a2[j-1])    return true;
        else return false;
    }
    else{
        if(a2[j]>=a1[j]&&a2[j]>=a2[j+1]&&a2[j]>=a2[j-1])    return true;
        else return false;
    }
}

int main(int argc, char* argv[]){
    //open file
    char inftmp[15] = "/matrix.data";
    char inf[30];
    strcpy(inf,argv[1]);
    strcat(inf,inftmp);
    ifstream inFile;
    inFile.open(inf);

    //open output file for storing pos
    char oftmp[15] = "/final.peak";
    char of[30];
    strcpy(of,argv[1]);
    strcat(of,oftmp);
    ofstream outFile;
    outFile.open(of);

    //get row&col;
    int row,col;
    inFile>>row>>col;

    //
    outFile<<"       "<<endl;
    //setup buffers for peakfinding
    long b1[col+1], b2[col+1], b3[col+1];

    //start peak finding
    int count = 0;
    int i = 1;
    while(i<=row){
        if(i%3==1){
            if(i==1){
                for(int a=1; a<=col; a++)   inFile>>b1[a];
                i++;
                continue;
            }
            for(int a=1; a<=col; a++){
                inFile>>b1[a];
                if(isPeak(b2,b3,b1,a,col)){
                    outFile << i-1 << ' ' << a << endl;
                    count++;
                }
            }
        }
        else if(i%3==2){
            if(i==2){
                for(int a=1; a<=col; a++){
                    inFile>>b2[a];
                    if(isPeakS(b1,b2,a,col)){
                        outFile << i-1 << ' ' << a << endl;
                        count++;
                    }
                }
                i++;
                continue;
            }
            for(int a=1; a<=col; a++){
                inFile>>b2[a];
                if(isPeak(b3,b1,b2,a,col)){
                    outFile << i-1 << ' ' << a << endl;
                    count++;
                }
            }
        }
        else if(i%3==0){
            for(int a=1; a<=col; a++){
                inFile>>b3[a];
                if(isPeak(b1,b2,b3,a,col)){
                    outFile << i-1 << ' ' << a << endl;
                    count++;
                }
            }
        }
        if(i==row){
            if(i%3==1){
                for(int a=1; a<=col; a++)
                    if(isPeakE(b3,b1,a,col)){
                        outFile << i << ' ' << a << endl;
                        count++;
                    }
            }
            else if(i%3==2){
                for(int a=1; a<=col; a++)
                    if(isPeakE(b1,b2,a,col)){
                        outFile << i << ' ' << a << endl;
                        count++;
                    }
            }
            else if(i%3==0){
                for(int a=1; a<=col; a++)
                    if(isPeakE(b2,b3,a,col)){
                        outFile << i << ' ' << a << endl;
                        count++;
                    }
            }
        }
        i++;
    }

    inFile.close();
    
    char hof[7];
    sprintf(hof,"%d",count);
    outFile.seekp(0);
    outFile<<hof;
    int len = strlen(hof);
    len = 7-len;
    for(int i=0;i<len;i++)  outFile<<'\b';

    outFile.close();


    
    /*//open final output file
    char ooftmp[15] = "/final.peak";
    char oof[30];
    strcpy(oof,argv[1]);
    strcat(oof,ooftmp);
    ofstream out;
    out.open(oof);

    //open temp file
    char iinftmp[15] = "/tmp.peak";
    char iinf[30];
    strcpy(iinf,argv[1]);
    strcat(iinf,iinftmp);
    ifstream in;
    in.open(iinf);

    out<<count<<endl;
    string line;
    while(!in.eof()){
        getline(in,line);
        out<<line<<endl;
    }
    in.close();
    out.close();
    */
}