#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>

struct attributes {
  std::string d_gene;
  int score;
  std::vector<int> ranges;
};
struct align_info {
  std::string query_name;
  std::vector<attributes> attributes_vec;
};

void ToVector(std::vector<std::string> &vec, std::string str) {
  std::stringstream s2(str);
  std::string tmp;
  while (s2 >> tmp) {
    vec.push_back(tmp);
  }
}

std::vector<int> Ranges(std::vector<std::string> &v, std::string line) {
  ToVector(v, line);
  int i = 0;
  while (true) {
    if (v[i] == "range:") {
      int a = std::stoi(v[i + 1]);
      int b = std::stoi(v[i + 3]);
      std::vector<int> temp;
      temp.push_back(a);
      temp.push_back(b);
      return temp;
      break;
    }
    i++;
  }
}

bool CheckDirection(std::string line) {
  std::vector<std::string> v;
  std::vector<int> range = Ranges(v, line);
  return (range[0] < range[1]);
}

void AddRanges(std::vector<int> &vec, std::string line) {
  std::vector<std::string> v;
  std::vector<int> range = Ranges(v, line);
  vec.push_back(range[0]);
  vec.push_back(range[1]);
}

std::string StripLabel(std::string label, std::string name, bool query) {
  std::vector<std::string> v;
  ToVector(v, label);
  int i = 0;
  std::string nolabel = "";
  while (true) {
    if (v[i] == name) {
      if (query)
        for (int j = i + 1; j < v.size(); j++)
          nolabel += v[j] + " ";
      else
        nolabel = v[i + 1];
      break;
    }
    i++;
  }
  return nolabel;
  return v[1];
}

int main(int argc, char const *argv[]) {
  // Opening File
  std::ifstream file;
  std::string filename;
  getline(std::cin, filename);
  file.open(filename);

  // Initializing
  std::string line;
  align_info ai_temp;
  attributes att_temp;
  std::vector<align_info> alignments;
  std::string current_query = "";
  std::vector<int> current_ranges;
  bool direct;

  if (file.is_open()) {
    while (std::getline(file, line)) {

      if (line.find("Query:") != std::string::npos) {
        std::string line_q = StripLabel(line, "Query:", true);
        if (line_q != current_query &&
            line_q.find("|:[revcomp]") == std::string::npos) {
          if (current_query != "")
            alignments.push_back(ai_temp);
          ai_temp = align_info();
          ai_temp.query_name = line_q;
          current_query = line_q;
        }
      }
      if (line.find("Target:") != std::string::npos) {
        std::string line_temp = StripLabel(line, "Target:", false);
        att_temp.d_gene = line_temp;
      }
      if (line.find("Raw score:") != std::string::npos) {
        int score = std::stoi(StripLabel(line, "score:", false));
        att_temp.score = score;
      }
      if (line.find("Query range:") != std::string::npos) {
        direct = CheckDirection(line);
        AddRanges(current_ranges, line);
      }
      if (line.find("Target range:") != std::string::npos) {
        AddRanges(current_ranges, line);
        if (direct) {
          for (int z = 0; z < current_ranges.size(); z++)
            att_temp.ranges.push_back(current_ranges[z]);
          ai_temp.attributes_vec.push_back(att_temp);
        }
        att_temp.ranges.clear();
        current_ranges.clear();
      }
    }
  }
  for (int q = 0; q < alignments.size(); q++) {
    std::cout << "Query: " << alignments[q].query_name << "\n\n";
    for (int p = 0; p < alignments[q].attributes_vec.size(); ++p) {
      std::cout << "d gene: " << alignments[q].attributes_vec[p].d_gene << "\n";
      std::cout << "score: " << alignments[q].attributes_vec[p].score << "\n";
      std::cout << "Query range: " << alignments[q].attributes_vec[p].ranges[0]
                << "-" << alignments[q].attributes_vec[p].ranges[1] << "\n";
      std::cout << "Target range: " << alignments[q].attributes_vec[p].ranges[2]
                << "-" << alignments[q].attributes_vec[p].ranges[3] << "\n\n";
    }
  }
  file.close();
  return 0;
}
