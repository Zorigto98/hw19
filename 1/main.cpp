#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string searchWord, str;
    cout << "Enter a search word" << endl;
    cin >> searchWord;

    ifstream word;
    word.open("D:\\Study\\SkillBox\\19_les\\1\\word.txt");

    int count=0;
    while (!word.eof())
    {
        word >> str;
        if (str==searchWord) count++;
    }

    cout << "The word '" << searchWord << "' occurs " << count << " time(s) in the text.";

    word.close();
}
