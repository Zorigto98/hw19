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

    char text[2];
    ifstream file(path);

    if (file.is_open())
    {
        while (!file.eof())
        {
            file.read(text, 1);
            cout << text[0];
        }
    }
    else cout << "Incorrect path or file doesn't open" << endl;

    file.close();
}

//D:\\Study\\SkillBox\\19_les\\2\\file.txt