#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string data;
    int i, j;
    ifstream input_file;
    input_file.open("input.txt");

    input_file >> data >> i >> j;
    input_file.close();

    // cout<<(4+7)/2;
    // return 0;
    j+=1;
    for(int k = i-1;k<(i+j)/2;k++){
        // cout<<k<<endl;
        char b=data[k];
        data[k]=data[i+j-k];
        data[i+j-k]=b;
        // cout<<data[k]<<endl;
    }

    cout<<data;

    // string s = "";

    // string a = data.substr(0, i - 1);
    // string b = data.substr(i - 1, j - i + 1);
    // string c = data.substr(j);

    // s += a;
    // for (int k = b.length(); k >= 0; k--) {
    //     s += b[k];
    // }
    // s += c;

    // cout << s;

    

    return 0;
}
