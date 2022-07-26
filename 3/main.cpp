#include <iostream>
#include <fstream>
#include <string>
#include <istream>

using namespace std;

int main() {

    ifstream payout;
    payout.open("D:\\Study\\SkillBox\\19_les\\3\\payout.txt");

    string name, lastName, date, str;
    int money, sum=0, max=0, count=0;

    if (payout.is_open())
    {
        while (!payout.eof())
        {
            count++;
            payout >> name >> lastName >> money >> date;
            sum+=money;

            if (money>max)
            {
                max=money;
                str=name + " " + lastName;
            }
        }
    }
    else cout << "File is not open";

    payout.close();

    cout << "Total payout: " << sum << endl;
    cout << "Person with highest payout: " << str << endl;
}