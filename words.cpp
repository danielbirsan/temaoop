#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    // Open the input file
    std::ifstream input_file("manywords.txt");
    if (!input_file) {
        std::cerr << "Error: Unable to open input file 'words.txt'\n";
        return 1;
    }

    // Open the output file
    std::ofstream output_file("listofwords.txt");
    if (!output_file) {
        std::cerr << "Error: Unable to open output file 'tastatura.h'\n";
        return 1;
    }

    std::vector<std::string> words;
    std::string word;

    // Read words from input file and store them in vector
    while (input_file >> word) {
        words.push_back(word);
    }

    // Write words to output file in the format listwords={"word1", "word2", ...}
    output_file << "listwords={";
    for (size_t i = 0; i < words.size(); ++i) {
        output_file << "\"" << words[i] << "\"";
        if (i != words.size() - 1) {
            output_file << ", ";
        }
    }
    output_file << "};";

    std::cout << "Words written to 'tastatura.h' successfully.\n";

    // Close files
    input_file.close();
    output_file.close();

    return 0;
}
