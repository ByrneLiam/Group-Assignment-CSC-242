
/* ---------------------------------------------------------------------------
** I attest that this following code represents my own work and is subject to
** the plagiarism policy found in the course syllabus.
**
** Class:     CSC 242
** Assignment:     Lesson #4
** File:
** Description: Spell Check,
**
** Author:     Maricela Farfan, Liam Byrne, Olivia Macomber
** Date:     8/25/2025
** -------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    // 1. Open the dictionary file.
    ifstream dictionaryFile("words.txt");
    if (!dictionaryFile.is_open())
    {
        cerr << "Error: Could not open words.txt" << endl;
        return 1;
    }

    // 2. Define a vector of strings called words.
    vector<string> words;

    // 3. For each word in the dictionary file, append the word to the words vector.
    string dictWord;
    while (dictionaryFile >> dictWord)
    {
        words.push_back(dictWord);
    }
    dictionaryFile.close();

    // 4. Open the file to be checked.
    ifstream fileToCheck("input.txt");
    if (!fileToCheck.is_open())
    {
        cerr << "Error: Could not open input.txt" << endl;
        return 1;
    }

    // 5. For each word in that file, if the word is not contained in the words vector, print the word.
    string currentWord;
    while (fileToCheck >> currentWord)
    {
        if (find(words.begin(), words.end(), currentWord) == words.end())
        {
            cout << currentWord << endl;
        }
    }
    fileToCheck.close();

    return 0;
}