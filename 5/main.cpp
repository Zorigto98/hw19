#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <vector>


using namespace std;

void chose_question (int sector) // вывод вопроса в консоль из файла в зависимости от сектора
{
    string buffer;
    ifstream questions ("../questions.txt");

    for (int i=0; i<=sector; i++)
    {
        getline(questions, buffer);
    }
    cout << buffer << endl;
}

bool check_answer(int sector) // проверка введенного ответа
{
    string answer;
    string buffer;

    cout << "Input answer " << endl;
    cin >> answer;

    ifstream answers ("../answers.txt");

    for (int i=0; i<=sector; i++)
    {
        getline(answers, buffer);
    }

    return buffer==answer;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector <bool> questions (13);
    int sector=0;
    int count_experts=0, count_viewers=0;
    bool win=false;

    while(!win)
    {
        int offset=0;
        cout << "Input offset" << endl;
        cin >> offset;

        sector=(sector+offset)%13;

        if (questions[sector])
        {
            while (questions[sector]) sector++;
            questions[sector]=true;
        }
        else questions[sector]=true;

        for (int i=0; i<questions.size(); i++) // для проверки, правильно ли выводятся вопросы
        {
            cout << i+1 << "-" << questions[i] << " | ";
        }
        cout << " sector " << sector+1 << endl; // для проверки сектора

        chose_question(sector);

        if (check_answer(sector)) count_experts++; // подсчет очков
        else count_viewers++;
        cout << "Score: Experts - " << count_experts << " Viewers - " << count_viewers << endl;

        if (count_viewers==6 || count_experts==6) // проверка победителя
        {
            if (count_experts>count_viewers)
            {
                cout << "Experts won" << endl;
                win=true;
            }
            else
            {
                cout << "Viewers won" << endl;
                win=true;
            }
        }
    }
}