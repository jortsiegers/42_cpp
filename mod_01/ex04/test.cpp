
#include <fstream>
#include <iostream>
#include <string>


int main() {
    // TEST 1
    {
        // Test case: Replace all occurrences of s1 in a single-line file
        const std::string inputFilename = "input1.txt";
        const std::string outputFilename = inputFilename + ".replace";
        const std::string s1 = "foo";
        const std::string s2 = "bar";

        // Write test data to input file
        std::ofstream input(inputFilename);
        input << "foofoofoo";
        input.close();

        // Replace s1 with s2 in input file and write result to output file
        int result = system(("./sed42 " + inputFilename + " " + s1 + " " + s2).c_str());
        assert(result == 0);

        // Read output file and check that it is correct
        std::ifstream output(outputFilename);
        std::string line;
        std::getline(output, line);
        assert(line == "barbarbar");
        output.close();

        // Clean up
        std::remove(inputFilename.c_str());
        std::remove(outputFilename.c_str());
        std::cout << "Test 1: Passed" << std::endl;
    }

    {
        // TEST 2
        // Test case: Replace all occurrences of s1 in a multi-line file
        const std::string inputFilename = "input2.txt";
        const std::string outputFilename = inputFilename + ".replace";
        const std::string s1 = "foo";
        const std::string s2 = "bar";

        // Write test data to input file
        std::ofstream input(inputFilename);
        input << "foo bar baz\n";
        input << "foofoo barfoo bazfoo\n";
        input.close();

        // Replace s1 with s2 in input file and write result to output file
        int result = system(("./sed42 " + inputFilename + " " + s1 + " " + s2).c_str());
        assert(result == 0);

        // Read output file and check that it is correct
        std::ifstream output(outputFilename);
        std::string line;
        std::getline(output, line);
        assert(line == "bar bar baz");
        std::getline(output, line);
        assert(line == "barbar barbar bazbar");
        output.close();

        // Clean up
        std::remove(inputFilename.c_str());
        std::remove(outputFilename.c_str());
    
        std::cout << "Test 2: Passed" << std::endl;
    }


    // TEST 3
    {
        // Test case: Replace all occurrences of an empty string with a non-empty string
        const std::string inputFilename = "input4.txt";
        const std::string outputFilename = inputFilename + ".replace";
        const std::string s1 = "\"\"";
        const std::string s2 = "bar";

        // Write test data to input file
        std::ofstream input(inputFilename);
        input << "foo bar baz\n";
        input << "foofoo barfoo bazfoo\n";
        input.close();

        // Replace s1 with s2 in input file and write result to output file
        int result = system(("./sed42 " + inputFilename + " " + s1 + " " + s2).c_str());
        assert(result == 0);

        // Read output file and check that it is correct
        std::ifstream output(outputFilename);
        std::string line;
        std::getline(output, line);
        assert(line == "foo bar baz");
        std::getline(output, line);
        assert(line == "foofoo barfoo bazfoo");
        output.close();

        // Clean up
        std::remove(inputFilename.c_str());
        std::remove(outputFilename.c_str());

        std::cout << "Test 2: Passed" << std::endl;
    }

}
