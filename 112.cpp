#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string filter_symbol(string s, char symbol);
bool check_palindrome(string phrase);

int main()
{
    string data, phrase = "";
    ifstream input_file;
    input_file.open("input.txt");

    getline(input_file, data);
    phrase = filter_symbol(data, ' ');
    if (check_palindrome(phrase)) {
        cout << "yes";
    }
    else {
        cout << "no";
    }

    input_file.close();

    return 0;
}

bool check_palindrome(string phrase)
{
    int len, i;

    len = phrase.length();
    for (i = 0; i < len; i++) 
    {
        if (phrase[i] != phrase[len - i - 1]) 
        {
            return false;
        }
    }
    return true;
}

string filter_symbol(string s, char symbol)
{
    int i;
    string buffer = "";

    for (i = 0; i < s.length(); i++) 
    {
        if (s[i] != symbol) 
        {
            buffer += s[i];
        }
    }
    return buffer;
}