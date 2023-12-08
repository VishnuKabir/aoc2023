#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
#include <ctype.h>
int main(){
  std::string filename = "data.txt";
  std::ifstream in ("data.txt");
  if(!in)
    {
        std::cerr << "Cannot open the File : "<<filename<<std::endl;
        return 0;
    }
  else {
    std::cerr <<"Opened File: " <<filename<<std::endl;
  }
  std::map<std::string, int> dict;
  dict.insert(std::pair<std::string,int>("one",1));
  dict["two"] =2;
  dict["three"] =3;
  dict["four"] =4;;
  dict["five"] =5;
  dict["six"] =6;
  dict["seven"] =7;
  dict["eight"] =8;
  dict["nine"]= 9;

  std::string str;
  std::vector<std::string> lines;
  int count = 0;
  int sum = 0;
  int num = 0;
  while (std::getline(in, str))
    {
        // Line contains string of length > 0 then save it in vector
        if(str.size() > 0){
            lines.push_back(str);}
       std::cout << lines.back()<< std::endl;
    std::string currline = lines.back();
    std::vector<int> sumvec;
    std::vector<int> idxnum;
    std::map<std::string, int>::iterator it = dict.begin();
    int min = 20000;
    int max = -1;
    std::string minstring;
    std::string maxstring;
    while(it != dict.end()){
      // find substring in string 
      int found = currline.find(it->first);

      if (found != std::string::npos){

          if (min > found){
          min = found;
          minstring = it->first;

        }
        int j;
        int tracker = found;
        for(int j = 1; j < currline.length() && tracker != std::string::npos;j++){
          tracker = currline.find(it->first, tracker+1);
          if (tracker >found) found = tracker;
        }

        if (max < found){
          max = found;
          maxstring = it->first; 
        }
      }
      // get index of substring
      // get min index and substring 
      // get max index and substring 
      ++it;
    }

      for (int i =0; i < currline.length();i++){

      if (std::isdigit(currline.at(i))){
        idxnum.push_back(i);
        sumvec.push_back(currline[i] - '0');
      }
    }
    int first = 0;
    int last =0;
    if (min > idxnum[0]){
        first = sumvec[0];
    }
    else{
      first = dict[minstring];
    }
    if(max < idxnum[idxnum.size()-1]){
      last = sumvec[idxnum.size()-1];
    }
    else{
      last = dict[maxstring];
    }
  //  std::cout << min<< std::endl;   
    num = first * 10 + last;
    std::cerr <<num<< std::endl;
    sum += num;
    count +=1;
    }
  std::cerr << sum << std::endl;
  in.close();
  return 0;
}

