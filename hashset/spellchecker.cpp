/**
 * \file spellchecker.cpp
 * \authors Ricky Pan, Amy Huang
 *
 * \brief Spell checker for strings
 */

#include "spellchecker.hpp"
#include "hashset.hpp"
#include <cstddef>
#include <ostream>
#include <sstream>	// Convert char to string
#include <fstream>

using namespace std;


SpellChecker::SpellChecker(const std::string& filename)
{
	// Open provided file
	ifstream inputStream(filename);
	if (!inputStream) {
		cerr << "Couldn't open file: " << filename << endl;
        exit(1);
	}

	// Read data from the file, one item per line
    string line;
    while(inputStream.good()) {
        getline(inputStream, line);
        if (inputStream.fail())
            break;

        auto hash = myhash(line);
        dict_.insert(line);
    };
}

void SpellChecker::spellCheck(std::string& word) const
{
	// Read data from the file, one item per line
	stringstream ss;
	string letter;

	// Convert to lowercase
	transform(word.begin(), word.end(), word.begin(), tolower());

	if (!dict_.exists(word)) {

		cout << word << ": ";

		// Check if nearby words exist
		for (size_t i = 0; i < word.size(); ++i) {
			string currWord = word;
			for(size_t ch = 97; ch < 123; ++ch) {
				ss << ch;
				ss >> letter;

				currWord.replace(i, 1, letter);
				if (dict_.exists(currWord)) {
					cout << currWord << " ";
				}
			}
		}
		cout << endl;
	}  
}