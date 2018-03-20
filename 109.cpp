#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string data;
    ifstream input_file;
    input_file.open("input.txt");

    input_file >> data;
    input_file.close();

    string unique_characters = "";

    for (int i = 0; i < data.length(); i++) {
        if (unique_characters.find(data[i]) == string::npos) {
            unique_characters += data[i];
        }
        else {
            cout << data[i];
            return 0;
        }
    }
}
