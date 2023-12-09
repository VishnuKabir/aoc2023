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

    bool mynum = true;
    for(int i = 0 ; i < lenGame;i++){
    try{

    int number = stoi(line[i]);   
 if (i < lenGame -1){
        if(line[i+1].compare("red")==0 ||line[i+1].compare("red,")==0 ||line[i+1].compare("red;")==0  ){
          if (number > 12){
            games.push_back(number);
              mynum = false;
              cout<<it->first<<endl;
          }
        }
        if(line[i+1].compare("blue")==0 || line[i+1].compare("blue;") ==0 ||line[i+1].compare("blue,")==0){
          if (number > 14){
            games.push_back(number); 
              mynum = false;
          
          }
        }

        if(line[i+1].compare("green")==0 ||line[i+1].compare("green,")==0 ||line[i+1].compare("green;")==0){
          if (number > 13){
            games.push_back(number);
              mynum = false;
          
          }
      }
    }
  }
    catch(exception& e){
        
  }
 
  }
    if(mynum == true){
      sum += stoi(line[1]);
    } 
   ++it; 
}

    cout<<sum<<endl;
  return 0;
}
