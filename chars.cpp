#include <iostream>
#include <map>
#include <string>
#include <vector>

/*
 * Split a given string and place the results in the output vector
 */
void split(std::string input, std::vector<char> &output) {
    for(int i = 0; i < input.size(); i++) {
        // If the character is alphanumeric, add it as a character
        if(std::isalnum(input[i])) {
            output.push_back(input[i]);
        }
    }
}

/*
 * Find the character with the largest amount of occurrences.
 */
int main() {
    std::map<char, int> char_count;
    std::string input;
    std::vector<char> chars;
    std::vector<int> most_dup;

    int first_dup = -1;

    std::cout << "Enter an array of characters: ";

    std::getline(std::cin, input);

    // Split the input string
    ::split(input, chars);

    most_dup.push_back(0);

    for(int i = 0; i < chars.size(); i++) {
        // Update count for the current character
        char_count[chars[i]] = char_count[chars[i]] + 1;

        // Add any characters that have the most duplicates
        if(char_count[chars[most_dup[0]]] < char_count[chars[i]]) {
            most_dup.clear();
            most_dup.push_back(i);
        } else if(chars[most_dup[0]] != chars[i] && char_count[chars[most_dup[0]]] == char_count[chars[i]]) {
            most_dup.push_back(i);
        }

        // Check if the current character is the first duplicate
        if(first_dup == -1 && char_count[chars[i]] == 2) {
            first_dup = i;
        }
    }

    // Print the first duplicate character
    if(first_dup != -1) {
        std::cout << "First duplicated character: " << chars[first_dup] << std::endl;
    }
    
    // Print the character with the most duplicates
    if(chars.size() > 0) {
        std::cout << "Most duplicated character(s)" << std::endl;

        for(int i = 0; i < most_dup.size(); i++) {
            std::cout << chars[most_dup[i]] << ": " << char_count[chars[most_dup[i]]] << std::endl;
        }
    }
    
    return 0;
}