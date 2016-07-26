// include...
//#include <boost>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {

  std::ifstream file;
  file.open("output_truncate.txt");

  std::vector<std::string> vec;
  std::string number;
  while (file >> number) {
    vec.push_back(number);
  }
  std::vector<std::string> new_vec;
  for (int i = 0; i < vec.size(); i++) {
    std::string temp = vec[i];
    std::cout << ">Seq" << i << "\n";
    for (char &c : temp) {
      int nuc = (int)(c - '0');
      // std::cout << c << ", " << nuc << "\n";
      switch (nuc) {
      case 0: {
        std::cout << "A";
        break;
      }
      case 1: {
        std::cout << "C";
        break;
      }
      case 2: {
        std::cout << "G";
        break;
      }
      case 3: {
        std::cout << "T";
        break;
      }
      }
    }
    std::cout << "\n";
  }

  return 0;
}
