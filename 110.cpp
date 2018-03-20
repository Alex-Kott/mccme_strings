#include <fstream>
#include <string>
#include <iostream>

using namespace std;
 
int main()
{
	string s1, s2;
	ifstream in("input.txt");
	ofstream out("output.txt");

	in >> s1 >> s2;
	out << (s2.find(s1) != string::npos ? "yes" : "no");

	return 0;
}
