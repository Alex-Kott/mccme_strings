#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<string> split_for_delimeter(string& s, char delimiter)
{
  vector<string> tokens;
  string token;
  istringstream tokenStream(s);

  while (getline(tokenStream, token, delimiter)) {

    tokens.push_back(token);
    cout << token << endl;
  }  

  return tokens;
}

bool is_delimiter(char c, string delimiters){
  for(int i = 0; i < delimiters.length(); i++){
    if(c == delimiters[i]){
      return true;
    }
  }
  return false;
}

void split(string& s, string delimiters)
{
  vector<string> tokens;
  string buffer;
  int i = 0;
  while(s){
    if(!is_delimiter(s[i], delimiters)){
      boofer = boofer + s[i];

    } else {
      boofer = "";
    }
  }
    

    // for(int i =0; i<delimiters.length();i++){
    //   // cout<<s<<' '<<delimiters[i]<<endl;
    //   split_for_delimeter(s, delimiters[i]);
    //   // tokens.push_back(split_for_delimeter(s, delimiters[i]));
    // }

    // while (getline(tokenStream, token, delimiter)) {
    //   while

    //     tokens.push_back(token);
    //     cout << token << endl;
    // }
    // cout<<tokens;
    // return tokens;
}

struct monomial {
    int coefficient;
    int power;
};

int main(void)
{
    string data;
    int x;

    ifstream input_file;
    input_file.open("input.txt");

    input_file >> data >> x;

    input_file.close();

    split(data, "+-");

    // vector<string> *monomials = &data;

    // cout<<monomials;

    // s = "sxsaxsa";
    // s = split(*data, "+");
    // cout<<s;

    return 0;
}
