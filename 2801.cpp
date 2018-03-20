#include <iostream>
#include <fstream>
#include <string>

using namespace std;

float get_a(string data);
float get_b(string data);

int main(void)
{
    string data;
    float a, b, x;

    ifstream input_file;
    input_file.open("input.txt");

    input_file >> data;

    input_file.close();

    a = get_a(data);
    b = get_b(data);

    if (a == 0 and b == 0) 
    {
        cout << "INF";
        return 0;
    }

    if (a == 0 && b != 0) 
    {
        cout << "NO";
        return 0;
    }

    x = -b / a;
    cout << x;

    return 0;
}

float get_a(string data)
{
    int xi;
    
    xi = data.find('x');
    string a = data.substr(0, xi);
    if (a == "") {
        return 1.0;
    }

    return (float)stoi(a, nullptr, 10);
}

float get_b(string data)
{
    int xi, eqi, range;

    xi = data.find('x');
    eqi = data.find('=');
    range = eqi - (xi + 1);
    string b = data.substr(xi + 1, range);

    return (float)stoi(b, nullptr, 10);
}