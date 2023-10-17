/* CS106B Assign2: Fun with Collections
 * Part2: Search Engine
 * For this part of the assignment, you will recreate this phenomenal technological development
 * by using the Map and Set ADTs to build a document search engine
 * that can find matching pages for a user's query with lighting-fast response time.
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>

using namespace std;

// Step1: Write a word-processing helper CleanToken()
/* The following function will take in a "token" from a webpage
 * and process it into a trimmed down word that we want to store in our index
 * your cleanToken function should meet the following requirements:
 * Trim away leading and trailing punctuation marks (according to ispunct) from each token.
 * Specifically, this means to remove all punctuation characters from the beginning and end of a token,
 * but not from inside a token. The input tokens section and section.
 * and "section" are each trimmed to become the same token (section),
 * which makes searching more effective. It also means that doesn't should be stored as-is, (and likewise for as-is),
 * since for both of these words the punctuation occurs in the middle of the word.
 * Note: There are a few oddball characters (curly quotes, bullets, and the like)
 * that are not reported as punctuation by ispunct, you do not need to make a special case out of this;
 * simply trim according to ispunct.
 * "Discard" any non-word tokens by just returning the empty string
 * if the token does not contain at least one letter.
 * All tokens should be converted to lowercase format to make for easier search eventually.
 */
string cleanToken(string token) {
    string clean = token;
    for (int i = 0; i < clean.size(); ++i) {
        if (ispunct(clean[i])) {
            if (clean[i] == '\'' && isalpha(clean[i + 1])) {
                continue;
            }
            clean.erase(i, 1);
            i--;
        }
        clean[i] = tolower(clean[i]);
    }
    return clean;
}

void test1(string s) {
    cout << cleanToken(s) << endl;
}
// Step2: Process webpages in readDoc()
/*
 *  In this first step, we'll process the consolidated database text file into a map of URLs (strings)
 *  to Set<string>s representing the unique words contained on the given page.
 *  You will complete the following function:
 *  This function opens the named file (passed in as dbfile), reads it line by line,
 *  and builds a map from a URL to a Set<string> representing the unique words contained on that page.
 *  To process the database file, your code will need to:
 *  First, read in the contents of the file into a vector of lines.
 *  You may find it helpful to refer to the provided code in readMazeFile in maze.cpp.
 *  For each page URL, tokenize its contents – in other words,
 *  divide the body text into individual tokens, which will be strings separated by spaces.
 *  Clean each token using your cleanToken helper function.
 *  Store the tokens in your map.
 */
map<string, set<string>> readDocs(string dbfile) {
    map<string, set<string>> db;
    fstream file(dbfile);
    string line;
    string url;
    string noisyToken;
    set<string> token;
    if (file.is_open()) {
        bool urlLine = true;
        while (getline(file, line)) {
            if (urlLine) {
                url = line;
                urlLine = false;
            } else {
                istringstream iss(line);
                while (getline(iss, noisyToken, ' ')) {
                    string clean = cleanToken(noisyToken);
                    if (!clean.empty()) {
                        token.insert(clean);
                    }
                }
                db.insert(make_pair(url, token));
                urlLine = true;
                token.clear();
            }
        }
    } else {
        cout << "Fail to open the file." << endl;
    }
    return db;
}

void test2(string s) {
    map<string, set<string>> db = readDocs(s);
    for (auto it = db.begin(); it != db.end(); it++) {
        string key = it->first;
        cout << key << endl;
        set<string> value = it->second;
        for (string token: value) {
            cout << "\"" << token << "\" ";
        }
        cout << endl;
    }
}

// Step3: Create the inverted index with buildIndex()
/* Given the map of document data (docs) that was created by the readDocs function,
 * your job is to build the inverted index data structure.
 * The output of buildIndex will be a map from word to a set of URLs where that word can be found.
 * In other words, this function will invert the map created by readDocs!
 */
map<string, set<string>> buildIndex(map<string, set<string>> &docs) {
    map<string, set<string>> index;
    for (auto it: docs) {
        for (string s: it.second) {
            auto change = index.find(s);
            if (change != index.end()) {
                change->second.insert(it.first);
            } else {
                index[s] = {it.first};
            }
        }
    }
    return index;
}

void test3(string s) {
    map<string, set<string>> docs = readDocs(s);
    map<string, set<string>> db = buildIndex(docs);
    for (auto it = db.begin(); it != db.end(); it++) {
        string key = it->first;
        cout << key << endl;
        set<string> value = it->second;
        for (string token: value) {
            cout << "\"" << token << "\" ";
        }
        cout << endl;
    }
}

// Step4: Search webpages using findQueryMatches()
/* When finding the matches for a given query, you should follow these rules:
 * For a single search term, the search matches are the URLs of the webpages that contain the specified term.
 * A sequence of terms is handled as a compound query,
 * where the matches from the individual terms are synthesized into one combined result.
 * A single search team can take on one of three forms:
 * By default when not prefaced with a + or -,
 * the matches are unioned across search terms. (any result matching either term is included)
 * If the user prefaces a search term with +,
 * then matches for this term are intersected with the existing results. (results must match both terms)
 * If the user prefaces a search term with -,
 * then matches for this term are removed from the existing result.
 * (results must match one term without matching the other)
 * The same punctuation stripping rules that apply to webpage contents apply to query terms.
 * Before looking for matches in the inverted index,
 * make sure you strip all punctuation from the beginning and end of the individual query terms.
 * As before, you should reject any search query terms that don’t have at least one alphabetic character.
 */
set<string> findQueryMatches(map<string, set<string>> &index, string query) {
    istringstream iss(query);
    string token;
    vector<string> tokens;
    set<string> matches;
    set<string> temp;
    string newToken;
    while (iss >> token) {
        if (token[0] == '+' || token[0] == '-') {
            if (!token.empty()) {
                token = token[0] + cleanToken(token.substr(1));
                tokens.push_back(token);
            }
        } else if (isalpha(token[0])) {
            if (!token.empty()) {
                tokens.push_back(token);
            }
        }
    }
    for (auto &i: tokens) {
        temp.clear();
        if (isalpha(i[0])) {
            auto it = index.find(i);
            if (it != index.end()) {
                set_union(matches.begin(), matches.end(), it->second.begin(), it->second.end(),
                          inserter(temp, temp.begin()));
                matches = temp;
            }
        } else if (i[0] == '+') {
            newToken = i.substr(1);
            auto it = index.find(newToken);
            if (it != index.end()) {
                set_intersection(matches.begin(), matches.end(), it->second.begin(), it->second.end(),
                                 inserter(temp, temp.begin()));
                matches = temp;
            }
        } else if (i[0] == '-') {
            newToken = i.substr(1);
            auto it = index.find(newToken);
            if (it != index.end()) {
                set_difference(matches.begin(), matches.end(), it->second.begin(), it->second.end(),
                               inserter(temp, temp.begin()));
                matches = temp;
            }
        }
    }
    return matches;
}

void test4(string s) {
    map<string, set<string>> docs = readDocs(s);
    map<string, set<string>> db = buildIndex(docs);
    set<string> matches = findQueryMatches(db, "red +orange");
    for (string url: matches) {
        cout << url << endl;
    }
}

// Step5: Put it all together with searchEngine()
/* This function should implement a console program that should implement the following logic:
 * Using functions you have already written, construct an inverted index from the contents of the specified file.
 * Display to the user how many website URLs were processed to build the index
 * and how many distinct words were found across all website content.
 * Once you have the index constructed, your program should go into a loop
 * that allows the user to enter queries that your program will evaluate.
 * Given a user query, you should calculate the appropriate matches from the inverted index.
 * Once you have computed the resulting set of matching URLs, you should print it to the screen.
 * Repeat this process until the user enters the empty string ("") as their query.
 * At this point, your program should stop running.
 */
void searchEngine(string dbfile) {
    cout << "Stand by while building index..." << endl;
    map<string, set<string>> docs = readDocs(dbfile);
    map<string, set<string>> index = buildIndex(docs);
    set<string> matches;
    string query;
    cout << "Indexed " << docs.size() << " pages containing " << index.size() << " unique terms." << endl;
    cout << "Enter query sentence (RETURN/ENTER to quit):";
    while (getline(cin, query)) {
        if (query.empty()) {
            cout << "All done!" << endl;
            break;
        }
        matches = findQueryMatches(index, query);
        if (matches.empty()) {
            cout << "No required pages indexed." << endl;
            cout << endl;
            cout << "Enter query sentence (RETURN/ENTER to quit):";
            continue;
        }
        for (string url: matches) {
            cout << url << endl;
        }
        cout << endl;
        cout << "Enter query sentence (RETURN/ENTER to quit):";
    }
}

int main() {
    searchEngine("../testwebsite");
    return 0;
}
