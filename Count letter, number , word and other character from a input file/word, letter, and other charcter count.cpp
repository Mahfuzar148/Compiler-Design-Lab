#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream input("C:\\Users\\DELL\\Documents\\Compiler Design Lab\\input.txt"); // Open input file
    ofstream output("C:\\Users\\DELL\\Documents\\Compiler Design Lab\\output.txt"); // Open output file

    if (!input.is_open()) {
        cerr << "Failed to open input file." << endl;
        return 1;
    }

    if (!output.is_open()) {
        cout << "Failed to open output file." << endl;
        return 1;
    }

    string line;
    int word = 1, letter = 0, digit= 0, other = 0;

    while (getline(input, line)) {
        // Process each line read from input file
        // For example, count alphanumeric characters and write to output file

        for (char ch : line) {
            if (isspace(ch)) {
                word++;
            }
            else if(isalpha(ch))
            {
                letter++;
            }
            else if(isdigit(ch))
            {
                digit++;
            }
            else
            {
                other++;
            }

        }
    }
    output << "Number of  word: " << word << endl;
    output<< "Number of  letter: " << letter << endl;
    output<< "Number of  digit: " << digit << endl;
    output<< "Number of  other: " << other << endl;

    // Close files
    input.close();
    output.close();

    std::cout << "Output has been written to output.txt" << std::endl;

    return 0;
}
