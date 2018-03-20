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

int main(void)
{
    string s, buffer;
    // cout<<string::npos<<endl;

    ifstream input_file;
    input_file.open("input.txt");

    input_file >> s;

    input_file.close();

    int i = 0, octet;
    string delimiters = ".";
    while (true) {
        if (s[i] == '\0' and octet < 4) {
            cout<<0;
            return 0;
        }
        cout<<"-----------------"<<endl;
        if (!is_delimiter(s[i], delimiters)) {
            buffer = buffer + s[i];
            i++;
        }
        else {

            if((buffer == "") || (stoi(buffer, nullptr, 10) > 255)){
                cout<<0;
                return 0;
            }

            buffer = "";
            
            cout<<s<<" "<<s.length()<<endl;
            if(s.find('.') != string::npos){
              s = s.substr(i + 1);  
            }
            
            // cout<<s<<endl;
            i = 0;
        }
        cout<<"_______"<<endl;

    }

    return 0;
}
