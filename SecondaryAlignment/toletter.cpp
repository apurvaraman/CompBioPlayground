// include...
//#include <boost>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

// char *ToCharArray(std::string str) {
//   char *c_array = new char[str.length() + 1];
//   std::strcpy(c_array, str.c_str());
//   return c_array;
// }
//
// void PathArray(char **c_array, std::string str) {
//   char *message = ToCharArray(str);
//   int i = 0;
//   c_array[i] = strtok(message, " ");
//   i = i + 1;
//   while ((c_array[i] = strtok(NULL, " ")) != NULL) {
//     i = i + 1;
//   }
// }

int main(int argc, char const *argv[]) {
  // std::string str =
  //     "20123201002002312230322 211010311113032113010033011333332 "
  //     "22203012231011332102100132230132023223 "
  //     "21032311222303011011012322301032221123201201 "
  //     "1220311303200201301223203301211012311231333 "
  //     "303012033333220232233033123332 311212003130120302302322330313120 "
  //     "0021030013220013313013 12221300032012321113 "
  //     "20330120123333201322330221111333 1123302220013122201132 "
  //     "221203312322030102130322033 32022220211120032210013123131333 "
  //     "3030210232233323332 11223303303001 12120130122320130033222 "
  //     "312320232220110333031333313322213031231301200302213 "
  //     "31122010011222223213 31000203211212332221222212331 "
  //     "21101031111303211301003301131333 3013323123223223221321301 "
  //     "120113301322222031002121211103320 202122320133122220301222110132 "
  //     "2003030210232213220211313013 2111103021222022323113300133 "
  //     "1121010223122220222330130 130120223222011303310113220013 "
  //     "221322130320323102322113331020 0122202111013310 "
  //     "0133230232230312013213033333122022132013 333201230120103120200330130 "
  //     "3133030110112302013 310133301301102333220123 "
  //     "23120101120130302102323113320133 32010202331132120333331301 "
  //     "130120223222011303310113220013 33212201203112202030222013 "
  //     "33223130210012113030021112002011 10310211111130303021221003 "
  //     "002002013002231220123313122111303310022000103 333221023221320131 "
  //     "11312031131023033 2020030322 21101031111303211301003301131333 "
  //     "2231330122323333201322300122222210322 3211320130122320121133333320 "
  //     "112332222202332201232003222 0232222201222122130322010133 "
  //     "0001111131112020100130320113033 22230031322223103222 "
  //     "11030332200010013032221131010133120313132222 220303113331333 "
  //     "130120223222011303310113220013 22010110213220121301 20022222013102032
  //     "
  //     "20123201002002312230322 1123023002232030232220213111333 "
  //     "12220223222011302211232232233312 03120131130013222211100122133 "
  //     "3112021330302202320312230100 1123302220013122201132 2020030322 "
  //     "31232222033332201223303332 102332222202332201232003222 "
  //     "301122221222310122320130122202120132 330302102322132212013 "
  //     "20112110213222133332 31312201033012033333220011313013 "
  //     "33123133032030230232233031113112013 23123203023213223303203 "
  //     "1002220101011303223333202003331333 030310330130 "
  //     "313313322222232030220232133033032233223 "
  //     "030031122232220213013212311331301 312211331203330322003332 "
  //     "3002223201301123201101131301 23123203023223223303203 "
  //     "2110232213223000111233320132 22233220012012002201322013
  //     220303113331333 "
  //     "2232222221301 33123331303223312221033303301213132222201223 "
  //     "22322030102030322210233033 211031232013012312133
  //     1123302220013122201132 "
  //     "130120223222011303310113220013 1123302220013122201132 "
  //     "312200200330120333332202322311113001133111220320130 "
  //     "2022220303321223020011021221112030322 "
  //     "32002002022003333232212232213223111203 "
  //     "33230231103103231300100102132233312 0133201001321001121313320 "
  //     "2103333201322131330222212202201301 00322222222013320 "
  //     "1123302220013122201132 12010033322222023331123203 "
  //     "13131111222321122322202230130112210133 23123203023203023303203";
  std::ifstream file;
  file.open("output_truncate.txt");

  std::vector<std::string> vec;
  std::string number;
  while (file >> number) {
    vec.push_back(number);
  }
  // std::vector<std::string> vec;
  //
  // if (std::ifstream input("output_truncate.txt")) {
  //   std::string word;
  //   while (input >> word)
  //     vec.push_back(word);
  // }
  std::cout << "test\n";
  for (int u = 0; u < vec.size(); u++)
    std::cout << "vec[" << u << "]: " << vec[u] << "\n";

  // std::vector<std::string> vec;
  // std::stringstream s2(str);
  // std::string tmp;
  // while (s2 >> tmp) {
  //   vec.push_back(tmp);
  // }
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