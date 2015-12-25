#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using std::string;
using std::cin;
using std::cout;
using std::endl;

bool isMySpace (char c);
void deleteSpaces(string& s);
void addTabs(string& s, int tabsNum);
bool isFirstChar(string& s, char c);

int main (int argc, const char* argv[])
{
	string s;

	int tabSize = 0;
	while ( !cin.eof() )
	{
		getline(cin, s);
		deleteSpaces(s);

		if (isFirstChar(s, '{')) {
			addTabs(s, tabSize);
			cout << s << endl;
			++tabSize;
			continue;
		} else if (isFirstChar(s, '}')) {
			--tabSize;
		}

		addTabs(s, tabSize);
		cout << s << endl;
	}

	cin.get();
	return 0;
}

bool isMySpace (char c) 
{
	return isspace(c) != 0 && c != '\n';
}

void deleteSpaces(string& s) 
{
	for (string::iterator it = s.begin(); it != s.end(); ++it) {
		if (isMySpace(*it)) {
			continue;
		} else {
			s.erase(s.begin(), it);
			break;
		}
	}
}

void addTabs(string& s, int tabsNum)
{	
	for (int i = 0; i < tabsNum; ++i) {
		s = '\t' + s;		
	}	
}

bool isFirstChar(string& s, char c) {
	if (!s.empty()) {
		if (s.at(0) == c) {
			return true;
		}
	}
	return false;
}