#include <string>

using namespace std;

string toLower(string s)
{
	for (char& c : s)
		c = tolower(c);
	return s;
}
