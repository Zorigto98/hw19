#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ifstream word;
    word.open("../word.txt");

    int count=0;

    if (word.is_open())
    {
        string searchWord, str;
        cout << "Enter a search word" << endl;
        cin >> searchWord;

        while (!word.eof())
        {
            word >> str;
            if (str==searchWord) count++;
        }
        cout << "The word '" << searchWord << "' occurs " << count << " time(s) in the text.";
    }
    else cout << "File doesn't open" << endl;

    word.close();
}
