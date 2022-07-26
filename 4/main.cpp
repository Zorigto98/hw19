#include <iostream>
#include <fstream>
#include <string>
#include <istream>

using namespace std;

int main() {
    string path;
    /*cout << "Enter file path" << endl;
    cout << "Example: D:\\\\\SkillBox\\\\19_les\\\\file.png" << endl;
    cin >> path;*/

    path="D:\\Study\\SkillBox\\19_les\\4\\file.png";

    ifstream file(path, ios::binary);

    if (file.is_open())
    {
        char buffer[4];
        file.read(buffer, sizeof(buffer));
        if ((int)buffer[0]==-119 && buffer[1]=='P' && buffer[2]=='N' && buffer[3]=='G') cout << "It's PNG" << endl;
    }
    else cout << "Incorrect path" << endl;

    file.close();
}