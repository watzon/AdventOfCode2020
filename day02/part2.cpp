#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>

template <typename Out>
void split(const std::string &s, char delim, Out result) {
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *result++ = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}

int main () {
    std::fstream ifile;
    ifile.open("./input.txt", std::ios::in);

    if (ifile.is_open()) {
        int count = 0;
        std::string line;

        while (getline(ifile, line)) {
            int p1, p2, i;
            char c;
            std::string pass;
            std::vector<std::string> parts;

            std::vector<std::string> tokens = split(line, ' ');
            if (tokens.size() < 3) continue;

            for (i = 0; i < 3; i++) {
                switch (i) {
                case 0:
                    // Min/Max
                    parts = split(tokens[i], '-');
                    p1 = std::stoi(parts[0], nullptr, 10);
                    p2 = std::stoi(parts[1], nullptr, 10);
                    break;
                case 1:
                    // Character
                    c = tokens[i][0];
                    break;
                case 2:
                    // Password
                    pass = tokens[i];
                    break;
                }
            }

            if (pass[p1 - 1] == c && pass[p2 - 1] != c) count++;
            if (pass[p2 - 1] == c && pass[p1 - 1] != c) count++;
        }

        std::cout << "Total valid: " << count << "\n";
    }

    ifile.close();
    return 0;
}
