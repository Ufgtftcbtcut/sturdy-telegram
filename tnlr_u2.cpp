// Imports
#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <unordered_map>
#include <regex>

// Defines
#define repeat(repeats) for (i = 0; i < repeats; ++i)
#define iter(toIter) for (auto tii : toIter)

#define arrIncludes(toCheck,wanted) find(toCheck.begin(),toCheck.end(),wanted) != toCheck.end()

#define sopts unsigned char
#define lopts unsigned short int
// Short (255)/Long (65535) OPTionS (for switches)

// Other set
using namespace std;

// Classes

// Constants
const string nl = "\n";
const string sl = "-------------------------";
const string usl = "_________________";

// Configs
unordered_map<string, bool> boolConfigs;
unordered_map<string, int> intConfigs;
unordered_map<string, string> strConfigs;
unordered_map<string, string> interfaceElems;

// General functions
void printStr(string text = "",bool newline = true) {
	if (newline == true) {
		cout << text.append(nl);
		return;
	}
	cout << text;
}

string userInput;

void getUserInput() {
	getline(cin, userInput);
}

// Init variables
double i;

vector<string> orderedSmalls = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
vector<string> orderedCapitals = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
// Consider turning these to chars not strings

vector<string> basicDigits = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

unordered_map<string, string> lowerToUpper;
unordered_map<string, string> upperToLower;

void initVarDataSetup(){
	// For uppercase() and lowercase()
	repeat(26) {
		lowerToUpper[orderedSmalls[i]] = orderedCapitals[i];
    }
    repeat(26) {
    	upperToLower[orderedCapitals[i]] = orderedSmalls[i];
    }
}

// String and vector functions
string mConcat(vector<string> toConcat) {
	string madeStr;
	for (string i: toConcat) {
		madeStr = madeStr.append(i);
	}
	return madeStr;
}

const string spsl = mConcat(vector<string>{nl, sl, nl});

string uppercase(string toCase) {
	string cased;
	repeat(toCase.length()) {
		if (arrIncludes(orderedSmalls,string(1,toCase.at(i)))) {
			cased = cased.append(lowerToUpper[string(1,toCase.at(i))]);
		} else {
			cased = cased.append(string(1,toCase.at(i)));
		}
	}
	return cased;
}

string lowercase(string toCase) {
	string cased;
	repeat(toCase.length()) {
		if (arrIncludes(orderedCapitals,string(1,toCase.at(i)))) {
			cased = cased.append(upperToLower[string(1,toCase.at(i))]);
		} else {
			cased = cased.append(string(1,toCase.at(i)));
		}
	}
	return cased;
}

// Non-positional (substring) regex replace
string nprReplace(string toReplace,string from,string to) {
	return regex_replace(toReplace,regex(from),to);
}

string uppercaseFirst(string toReplace) {
	if (arrIncludes(orderedSmalls,string(1,toReplace[0]))) {
		toReplace[0] = lowerToUpper[string(1,toReplace[0])][0];
	}
	return toReplace;
}

string uppercaseBookTitle(string toReplace) {
	toReplace = uppercaseFirst(toReplace);
	toReplace = nprReplace(toReplace," a"," A");
	repeat(26) {
		toReplace = nprReplace(toReplace,string(" ").append(orderedSmalls[i]),string(" ").append(orderedCapitals[i]));
	}
	return toReplace;
}

string ltrim(string toTrim,string trimmable = " ") {
    toTrim.erase(0, toTrim.find_first_not_of(trimmable));
    return toTrim;
}

string rtrim(string toTrim,string trimmable = " ") {
    toTrim.erase(toTrim.find_last_not_of(trimmable) + 1);
    return toTrim;
}

// Code runner utilities
double doing = 0;
double curLine = 1;

// Run just one line of the code
void runOneLine(string lineContent) {
	// Remove comments, leading spaces (mostly indents), and trailing spaces
	lineContent.erase(string(lineContent).find_last_of('#'));
	lineContent = rtrim(ltrim(lineContent));
	
	// Right now we assume all lines are functions
	// and that its just print() and sqrt(), in order
	// print(sqrt(7)) print() calls sqrt() too (inside)
	// runOneFunction()
}

// Run the code
void runPiznCode(string codeInitGot) {
	printStr(codeInitGot);
}

void setupPiznProcess() {
	initVarDataSetup();
}

// int main
int main() {
	runOneLine("       hey   # jjj");
	
	printStr("/\n| %™©® Pizn Code Interpreter ®©™%\n\\\n\nWelcome! Insert code:");

	while (true) {
		getUserInput();
		printStr(spsl);

		if (userInput == "exit") {
			exit(1);
		}
		setupPiznProcess();
		runPiznCode(userInput);

		printStr(spsl);
		printStr("Previous process done. Insert code:");
	}

	return 0;
}
