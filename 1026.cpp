#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

// vector<string> split_for_delimeter(string& s, char delimiter)
// {
//     vector<string> tokens;
//     string token;
//     istringstream tokenStream(s);

//     while (getline(tokenStream, token, delimiter)) {

//         tokens.push_back(token);
//         cout << token << endl;
//     }

//     return tokens;
// }



// vector<string> split(string& s, string delimiters)
// {
//     vector<string> tokens;
//     string buffer;
//     int i = 0;
//     while (true) {
//         // cout<<buffer<<endl;
//         if (s[i] == '\0') {
//             tokens.push_back(buffer);
//             break;
//         }
//         if (!is_delimiter(s[i], delimiters)) {
//             buffer = buffer + s[i];
//             i++;
//         }
//         else {
//             tokens.push_back(buffer);
//             buffer = "";

//             s = s.substr(i + 1);
//             // cout<<s.length()<<endl;
//             // cout<<s<<endl;
//             i = 0;
//         }

//         cout << "_________" << endl;
//         // cout<<s<<endl;
//     }
//     // cout<<"BASTA";

//     // for(int i =0; i<delimiters.length();i++){
//     //   // cout<<s<<' '<<delimiters[i]<<endl;
//     //   split_for_delimeter(s, delimiters[i]);
//     //   // tokens.push_back(split_for_delimeter(s, delimiters[i]));
//     // }

//     // while (getline(tokenStream, token, delimiter)) {
//     //   while

//     //     tokens.push_back(token);
//     //     cout << token << endl;
//     // }

//     for (std::vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
//         cout << *it << endl;
//     }

//     return tokens;
// }


bool is_delimiter(char c, string delimiters)
{
    for (int i = 0; i < delimiters.length(); i++) {
        if (c == delimiters[i]) {
            return true;
        }
    }
    return false;
}

int calc_monomial(string monomial, int x){
  int coefficient = 1;
  if(monomial == ""){
    return 0;
  }
  if(monomial.find('x') == string::npos){
    return stoi(monomial, nullptr, 10);
  }else if(monomial.find('x') != 0){
    string str_coefficient = monomial.substr(0, monomial.find('*'));
    coefficient = stoi(str_coefficient, nullptr, 10);
  }
  
  // cout<<monomial<<' '<<monomial.find('x')<<endl;
  int n = monomial.find('x')+2;
  int exponent = stoi(monomial.substr(n), nullptr, 10);


  return coefficient*pow(x, exponent);

  
}



int main(void)
{
    string data;
    int x;

    // cout<<string::npos<<endl;

    ifstream input_file;
    input_file.open("input.txt");

    input_file >> data >> x;

    input_file.close();

    int result = 0;

    string buffer;
    char sign = '+';
    int i = 0;
    string s = data;
    string delimiters = "+-";
    while (true) {
        if (s[i] == '\0') {
            if(sign == '+'){
              result = result + calc_monomial(buffer, x);
            }else{
              result = result - calc_monomial(buffer, x);
            }
            break;
        }
        if (!is_delimiter(s[i], delimiters)) {
            buffer = buffer + s[i];
            i++;
        }
        else {
            
            if(sign == '+'){
              // cout<<"Symbol: "<<s[i];
              result = result + calc_monomial(buffer, x);
            }else{
              result = result - calc_monomial(buffer, x);
            }
            sign = s[i];

            buffer = "";
            s = s.substr(i + 1);  
            // if(s.length() <= i+1){
            //   s = s.substr(i + 1);  
            // }else{
            //   s = s.substr(i);
            // }
            
            cout<<s<<endl;
            i = 0;
        }

    }
    cout<<result;

    return 0;
}
