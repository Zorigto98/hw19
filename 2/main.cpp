#include <iostream>
#include <fstream>
#include <string>
#include <istream>

using namespace std;

int main() {
    string path;
    /*cout << "Enter file path" << endl;
    cout << "../file.txt" << endl;
    cin >> path;*/

    // or

    path="../file.txt";

    ifstream file(path);

    if (file.is_open())
    {

        while (file)
        {
            char temp[20];
            file.read(temp, sizeof(temp)-1);
            temp[file.gcount()]='\0';
            cout << temp;
        }
    }
    else cout << "Incorrect path or file doesn't open" << endl;

    file.close();
}