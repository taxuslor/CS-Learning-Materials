/* CS106B Assign1: Getting Your C++ Legs
 * Part2: SoundexSearch
 *
 * A Soundex code is a four-character string in the form of an initial letter followed by three digits, such as Z452.
 * The initial letter is the first letter of the surname,
 * and the three digits are drawn from the sounds within the surname using the following algorithm:
 * 1.Discard all non-letter characters from surname: dashes, spaces, apostrophes, and so on.
 * 2.Encode each letter as a digit using the table below.
 *      Digit	represents the letters
 *      0	    A E I O U H W Y
 *      1	    B F P V
 *      2	    C G J K Q S X Z
 *      3	    D T
 *      4	    L
 *      5	    M N
 *      6	    R
 * 3.Coalesce adjacent duplicate digits from code (e.g. 222025 becomes 2025).
 * 4.Replace the first digit of code with the first letter of the original name, converting to uppercase if necessary.
 * 5.Remove all zeros from code.
 * 6.Make the code exactly length 4 by padding with zeros or truncating the excess.
 * For instance, "Jue" converts to J000 and "Master" converts to M236.
 */

#include <iostream>
#include <cctype>
#include <fstream>
#include <utility>

using namespace std;

// Step1 of the Soundex Algorithm: remove non-letters from the string
void removeNonLetters(string &s) {
    int i = 0;
    while (i < s.length()) {
        if (!isalpha(s[i])) {
            s = s.substr(0, i) + s.substr(i + 1);
        } else {
            i++;
        }
    }
}

// Step2 of the Soundex Algorithm: encode each letter as a digit
void convertToUppercase(string &s) {
    for (char &letter: s) {
        letter = ::toupper(letter);
    }
}

void encodeLetters(string &s) {
    for (int i = 0; i < s.length(); ++i) {
        switch (s.at(i)) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            case 'H':
            case 'W':
            case 'Y':
                s.replace(i, 1, "0");
                break;
            case 'B':
            case 'F':
            case 'P':
            case 'V':
                s.replace(i, 1, "1");
                break;
            case 'C':
            case 'G':
            case 'J':
            case 'K':
            case 'Q':
            case 'S':
            case 'X':
            case 'Z':
                s.replace(i, 1, "2");
                break;
            case 'D':
            case 'T':
                s.replace(i, 1, "3");
                break;
            case 'L':
                s.replace(i, 1, "4");
                break;
            case 'M':
            case 'N':
                s.replace(i, 1, "5");
                break;
            case 'R':
                s.replace(i, 1, "6");
                break;
        }
    }
}

// Step3 of the Soundex Algorithm: coalesce adjacent duplicate digits
void coalesceDigits(string &s) {
    int i = 0;
    while (i < s.length() - 1) {
        if (s[i] == s[i + 1]) {
            s = s.substr(0, i) + s.substr(i + 1);
        } else {
            i++;
        }
    }
}

// Step4 of the Soundex Algorithm: replace the first digit
void replaceFirstDigit(string &s, char letter) {
    s.front() = letter;
}

// Step5 of the Soundex Algorithm: remove all zeros
void removeZeros(string &s) {
    int i = 0;
    while (i < s.length()) {
        if (s[i] == '0') {
            s = s.substr(0, i) + s.substr(i + 1);
        } else {
            i++;
        }
    }
}

// Step6 of the Soundex Algorithm: make the code length 4
void makeLength4(string &s) {
    if (s.length() > 4) {
        s = s.substr(0, 4);
    } else if (s.length() < 4) {
        while (s.length() != 4) {
            s += "0";
        }
    }
}

// Implement Soundex Algorithm
string soundex(string s) {
    removeNonLetters(s);
    convertToUppercase(s);
    char first = s.front();
    encodeLetters(s);
    coalesceDigits(s);
    replaceFirstDigit(s, first);
    removeZeros(s);
    makeLength4(s);
    return s;
}

/* This function defines a console program that allows the user to specify a text file containing a database of names to search.
 * The program then repeatedly allows the user to specify surnames that they want to look up in the database.
 * For each surname that is specified, the program calculates the Soundex code of the specified name
 * and then finds all names in the database that have a matching Soundex code.
 * You should implement the following steps when writing this program:
 * 1.Read a database of surnames from the specified text file.
 * 2.Prompt the user to enter a surname.
 * 3.Compute the Soundex code of the surname.
 * 4.Iterate over the database, compute Soundex of each name, and gather a vector of those surnames with a matching code.
 * 5.Print the matches in sorted order.
 * 6.Repeat steps 2-5 until the user indicates that they are done.
 */
vector<string> readData(const string &filepath) {
    vector<string> data = {};
    ifstream file(filepath);
    if (file.is_open()) {
        string name;
        while (getline(file, name)) {
            data.push_back(name);
        }
        cout << "Read file " << filepath << ", " << data.size() << " names found." << endl;
    } else {
        cout << "Fail to open the file." << endl;
    }
    return data;
}

void soundexSearch(const string &filepath) {
    vector<string> data = readData(filepath);
    string name;
    cout << "Enter a surname (RETURN to quit): ";
    while (getline(cin, name)) {
        if (name.empty()) {
            break;
        }
        string soundex_code = soundex(name);
        vector<string> matches = {};
        cout << "Soundex code is " << soundex_code << endl;
        for (const string &s: data) {
            if (soundex(s) == soundex_code) {
                matches.push_back(s);
            }
        }
        if (!matches.empty()) {
            std::sort(matches.begin(), matches.end());
            cout << "Matches from database: ";
            for (const string &s: matches) {
                cout << s << " ";
            }
            cout << endl;
        } else {
            cout << "No matches in database." << endl;
        }
        cout << endl;
        cout << "Enter a surname (RETURN to quit): ";
    }
}

int main() {
    soundexSearch("../testcase");
    return 0;
}
