#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <ctype.h>
#include <map>
#include <string.h>
#include <cstring>
using namespace std;
int main(){

int sum = 0;
  string filename = "data.txt";
  ifstream in ("data.txt");
  if(!in)
    {
        cerr << "Cannot open the File : "<<filename<<endl;
        return 0;
    }
  else {
    cerr <<"Opened File: " <<filename<<endl;
  }
  string str;
  map<int,vector<string> > mymap;
  int count = 0;
  while(getline(in,str)){
  vector<string> lines;
  stringstream ss(str);
    string word;
    while (getline(ss,word, ' ')){
      lines.push_back(word);
    }
    mymap[count] = lines;

    count++;
  }
  vector<int> games;
  map<int, vector<string> >::iterator it = mymap.begin();
  while(it!= mymap.end()){

    vector<string> line = it->second;

    int lenGame = line.size();
    int maxred = 0;
    int maxblue = 0;
    int maxgreen = 0;
    bool mynum = true;
    for(int i = 0 ; i < lenGame;i++){
    try{

    int number = stoi(line[i]);   
 if (i < lenGame -1){
        if(line[i+1].compare("red")==0 ||line[i+1].compare("red,")==0 ||line[i+1].compare("red;")==0  ){
          if (number > maxred){
              maxred = number;
          }
        }
        if(line[i+1].compare("blue")==0 || line[i+1].compare("blue;") ==0 ||line[i+1].compare("blue,")==0){
          if (number > maxblue){
              maxblue = number;
          
          }
        }

        if(line[i+1].compare("green")==0 ||line[i+1].compare("green,")==0 ||line[i+1].compare("green;")==0){
          if (number > maxgreen){
              maxgreen = number;
          
          }
      }
    }
  }
    catch(exception& e){
        
  }
 
  }
   sum += maxred * maxblue*maxgreen; 
   ++it; 
}

    cout<<sum<<endl;
  return 0;
}
