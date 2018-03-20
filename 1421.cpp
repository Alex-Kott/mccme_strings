#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string data;
    ifstream input_file;
    input_file.open("input.txt");

    getline(input_file, data);
    input_file.close();

    string s = "";

    for (int i = 0; i < data.length(); i++) {
        int len = s.length();
        if ((s[len - 1] == ' ') and (data[i] == ' ')) {
        }
        else {
            s += data[i];
        }
    }
    cout << s;

    return 0;
}
