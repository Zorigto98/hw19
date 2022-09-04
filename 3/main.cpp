#include <iostream>
#include <fstream>
#include <string>
#include <istream>

using namespace std;

int main() {

    ifstream payout;
    payout.open("../payout.txt");

    string name, lastName, date, str, Mon;
    float money, sum=0, max=0;

    if (payout.is_open())
    {
        while (!payout.eof())
        {
            payout >> name >> lastName >> money >> date;
            if (payout.eof()) break;
            sum+=money;
            if (money>max)
            {
                max=money;
                str=name + " " + lastName;
            }
        }
        cout << "Total payout: " << sum << endl;
        cout << "Person with highest payout: " << str << endl;
    }
    else cout << "File is not open";

    payout.close();
}