#include <iostream>
#include <fstream>
#include <string>
#include <istream>

using namespace std;

int main() {
    string path, str;
    /*cout << "Enter file path" << endl;
    cout << "Example: D:\\\\\SkillBox\\\\19_les\\\\file.png" << endl;
    cin >> path;*/
    path="../file.png";
    str=path.substr(path.length()-4);
    if (str!=".png") cout << "It's not PNG file";
    else
    {
        ifstream file(path, ios::binary);
        if (file.is_open())
        {
            char buffer[4];
            file.read(buffer, sizeof(buffer));
            if ((int)buffer[0]==-119 && buffer[1]=='P' && buffer[2]=='N' && buffer[3]=='G') cout << "It's PNG" << endl;
            else cout << "It's not PNG file";
        }
        else cout << "Incorrect path" << endl;
        file.close();
    }
}