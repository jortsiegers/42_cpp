#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Error: Invalid number of arguments.\n";
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];


    std::ifstream input(filename);
    if (!input) {
        std::cerr << "Error: Could not open file '" << filename << "'.\n";
        return 1;
    }

    std::string outputFilename = filename + ".replace";
    std::ofstream output(outputFilename);
    if (!output) {
        std::cerr << "Error: Could not open file '" << outputFilename << "'.\n";
        input.close();
        return 1;
    }

    std::string line;
    while (std::getline(input, line)) {
        if (s1.length() != 0) {
            size_t pos = 0;
            while ((pos = line.find(s1, pos)) != std::string::npos) {
                line.erase(pos, s1.length());
                line.insert(pos, s2);
                pos += s2.length();
            }
        }
        output << line << std::endl;
    }

    input.close();
    output.close();
    return 0;
}
