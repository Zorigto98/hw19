#include <iostream>
#include <fstream>
#include <string>
#include <istream>

using namespace std;

int main() {
    string path;
    cout << "Enter file path" << endl;
    cout << "Example: D:\\\\SkillBox\\\\19_les\\\\file.txt" << endl;
    cin >> path;

    string line;
    ifstream file(path);

    if (file.is_open())
    {
        while (getline(file, line))
        {
            cout << line << endl;
        }
    }
    else cout << "Incorrect path" << endl;

    file.close();
}

//D:\\Study\\SkillBox\\19_les\\2\\file.txt