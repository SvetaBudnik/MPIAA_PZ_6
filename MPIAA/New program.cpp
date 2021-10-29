#include<stack>
#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int a = 0;
    cout << "�������-1" << endl;
    cout << "�������-2" << endl;
    cout << "�������-3" << endl;
    cin >> a;
    cout << endl;
    switch (a)
    {
    case 1:
    {
        stack<int> S;
        cout << "��������� ������������������:";
        cin >> a;
        while (a != 0)
        {
            S.push(a);
            cin >> a;
        }
        S.push(0);

        a = S.size();

        cout << "�������� ������������������:";
        for (int i = 0; i < a; i++)
        {
            cout << S.top() << " ";
            S.pop();
        }

        cout << endl;

        break;
    }
    case 2:
    {
        vector<int> V;
        cout << "��������� ������������������:";
        cin >> a;
        while (a != 0)
        {
            V.push_back(a);
            cin >> a;
        }
        V.push_back(a);
        sort(V.begin(), V.end());

        cout << "��������������� ������������������:";
        for (int i = 0; i < V.size(); i++)
        {
            cout << V[i] << " ";
        }
        cout << endl;

        V.erase(unique(V.begin(), V.end()), V.end());

        cout << "�������� ������������������:";
        for (int i = 0; i < V.size(); i++)
        {
            cout << V[i] << " ";
        }
        break;
    }
    case 3:
    {
        int b, n;
        cout << "������� ������ �������:";
        cin >> n;
        cout << "������� ���� �����:";
        cin >> a >> b;
        vector<vector<int> > V2(n, vector<int>());
        while (a != 0 or b != 0)
        {
            V2[a].push_back(b);
            cin >> a >> b;
        }
        for (int i = 0; i < n; i++)
        {
            sort(V2[i].begin(), V2[i].end());
        }
        for (int i = 0; i < n; i++)
        {
            for (int a : V2[i])
                cout << a << " ";
            cout << endl;
        }
        break;
    }
    }
}
