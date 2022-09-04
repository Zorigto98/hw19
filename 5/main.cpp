#include <iostream>
#include <fstream>
#include <string>
#include <istream>
#include <vector>
#include <Windows.h>

using namespace std;

void chose_question (int sector) // вывод вопроса в консоль из файла в зависимости от сектора
{
    string buffer;
    ifstream questions ("../questions.txt");

    for (int i=0; i<sector; i++)
    {
        getline(questions, buffer);
    }
    cout << buffer << endl;
}

bool check_answer(int sector) // проверка введенного ответа
{
    string answer;
    string buffer;

    cout << "Введите ответ" << endl;
    cin >> answer;

    ifstream answers ("../answers.txt");

    for (int i=0; i<sector; i++)
    {
        getline(answers, buffer);
    }

    return buffer==answer;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    vector <bool> questions (13);
    int sector=1;
    int count_experts=0, count_viewers=0;
    bool win=false;

    while(!win)
    {
        int offset=0;
        cout << "Введите смещение" << endl;
        cin >> offset;

        sector=(sector+offset)%13;

        if (questions[sector-1])
        {
            while (questions[sector-1]) sector++;
            questions[sector-1]=true;
        }
        else questions[sector-1]=true;

        for (int i=0; i<questions.size(); i++) // для проверки, правильно ли выводятся вопросы
        {
            cout << i+1 << "-" << questions[i] << " | ";
        }
        cout << " сектор " << sector << endl; //

        chose_question(sector);

        if (check_answer(sector)) count_experts++; // подсчет очков
        else count_viewers++;
        cout << "Счет: Знатоки - " << count_experts << " Зрители - " << count_viewers << endl;

        if (count_viewers==6 || count_experts==6) // проверка победителя
        {
            if (count_experts>count_viewers)
            {
                cout << "Победили знатоки" << endl;
                win=true;
            }
            else
            {
                cout << "Победили зрители" << endl;
                win=true;
            }
        }
    }
}