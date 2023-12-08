#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
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
      for (int i =0; i < currline.length();i++){

      if (std::isdigit(currline.at(i))){
        sumvec.push_back(currline[i] - '0');
      }
    }
    num = sumvec[0] * 10 + sumvec[sumvec.size()-1];
    std::cerr <<num<< std::endl;
    sum += num;
    count +=1;
    }
  std::cerr << sum << std::endl;
  in.close();
  return 0;
}
