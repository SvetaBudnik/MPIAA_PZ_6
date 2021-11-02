#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

void task_1() {
    int a;
    stack<int> S;
    cout << "Начальная последовательность:" << endl;
    cin >> a;
    while (a != 0)
    {
        S.push(a);
        cin >> a;
    }
    S.push(0);

    a = S.size();

    cout << "Обратная последовательность:" << endl;
    for (int i = 0; i < a; i++)
    {
        cout << S.top() << " ";
        S.pop();
    }

    cout << endl;
}

void task_2() {
    int a;
    vector<int> V;
    cout << "Начальная последовательность:" << endl;
    cin >> a;
    while (a != 0)
    {
        V.push_back(a);
        cin >> a;
    }
    V.push_back(a);
    sort(V.begin(), V.end());

    cout << "Отсортированная последовательность:" <<endl;
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << " ";
    }
    cout << endl;

    V.erase(unique(V.begin(), V.end()), V.end());

    cout << "Конечная последовательность:" << endl;
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << " ";
    }
}

void task_3() {
    cout << "Введите пары чисел:"<< endl;

    fstream out;
    out.open("output.txt", ios::out);
    streambuf* _cout = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    int a, b;
    vector<vector<int> > V = {};
    cin >> a >> b;

    while (a != 0 or b != 0)
    {
        if (V.size() < a + 1) {
            V.resize(a + 1);
        }
        V[a].push_back(b);
        cin >> a >> b;
    }
    for (auto i : V)
    {
        sort(i.begin(), i.end());
    }
    for (int i = 0; i < V.size(); ++i)
    {
        cout << "[" << i << "]: ";
        for (int j : V[i])
            cout << j << " ";
        cout << endl;
    }

    std::cout.rdbuf(_cout);
}

int main()
{
    setlocale(LC_ALL, "rus");
    int a = 0;
    while (a != 4) {
        cout << "Введите номер задания" << endl
            << "[1]: Задание 1" << endl
            << "[2]: Задание 2" << endl
            << "[3]: Задание 3" << endl
            << "[4]: Выход из программы" << endl;
        cin >> a;
        switch (a)
        {
            case 1:
                task_1();
                break;
            case 2:
                task_2();
                break;
            case 3:
                task_3();
                break;
            case 4:
                break;
            default:
                cout << "Неверный ввод" << endl;
                break;
        }
    }
}
