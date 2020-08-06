#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {	
	return s.length() % 2  == 1 ? s.substr(s.length() / 2, 1) : s.substr(s.length() / 2 - 1, 2);
}
int main()
{
	string s = "qwer";

	cout << solution(s);
	return 0;
}