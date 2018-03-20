#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

bool is_delimiter(char c, string delimiters)
{
    for (int i = 0; i < delimiters.length(); i++) {
        if (c == delimiters[i]) {
            return true;
        }
    }
    return false;
}

bool is_valid_symbol(char c){
    if(c == '\0')
    {
        return true;
    }
    if((int)c == 0)
    {
        return true;
    }
    if(c == '.')
    {
        return true;
    }
    if(((int)c>47) and ((int)c<58)){
        return true;
    }
    return false;
}

int main(void)
{
    string s, buffer="";

    ifstream input_file;
    input_file.open("input.txt");

    input_file >> s;

    input_file.close();

    int i = 0, octet=0;
    string delimiters = ".";
    if(s == ""){
        cout<<0;
        return 0;
    }
    while (true) {
        if(!is_valid_symbol(s[i])){
            cout<<0;
            return 0;
        }

        if (s[i] == '\0') {
            if(stoi(buffer, nullptr, 10) > 255){
                cout<<0;
            }else{
                cout<<1;
            }
            return 0;
        }

        if(octet > 4){
            cout<<0;
            return 0;
        }


        if (!is_delimiter(s[i], delimiters)) {

            buffer = buffer + s[i];
            i++;
        }
        else {
            if((buffer == "") || (stoi(buffer, nullptr, 10) > 255)){
                cout<<0;
                return 0;
            }
            if(i+1 >= s.length()){
                cout<<0;
                return 0;
            }
            s = s.substr(i+1);

            octet++;
            buffer = "";
            i = 0;
        }

    }

    return 0;
}