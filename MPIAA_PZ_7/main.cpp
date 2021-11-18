#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
#include<string>
#include <chrono> // для функций из std::chrono

class Timer
{
private:
    // Псевдонимы типов используются для удобного доступа к вложенным типам
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now())
    {
    }

    void reset()
    {
        m_beg = clock_t::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

using namespace std;

void task_1() {

    fstream out, in;
    out.open("output.txt", ios::out);
    in.open("input/input.txt", ios::in);
    streambuf* _cout = cout.rdbuf();
    cout.rdbuf(out.rdbuf());
    

    int a, b, n, m;
    in >> n >> m;

    vector<vector<int> > graph;
    graph.resize(n);
    for (int i = 0; i < m; ++i)
    {
        in >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (auto i : graph)
    {
        sort(i.begin(), i.end());
    }
    for (int i = 0; i < graph.size(); ++i)
    {
        cout << i + 1 << ": ";
        for (int j : graph[i])
            cout << j + 1 << " ";
        cout << endl;
    }

    std::cout.rdbuf(_cout);
}

void task_2() {
    fstream out, input;
    int a, n, gn;

    out.open("output.txt", ios::out);
    streambuf* _cout = cout.rdbuf();
    cout.rdbuf(out.rdbuf());

    input.open("input\\n.txt", ios::in);
    input >> gn;
    input.close();

    vector<vector<int>> graph;

    for (int curFile = 1; curFile <= gn; ++curFile) {
        input.open("input\\"+to_string(curFile) + ".txt");
        input >> n;
        if (graph.size() < n) graph.resize(n);
        vector<int> curVertecies;

        for (int i = 0; i < n; ++i) {
            input >> a;
            --a;
            if (graph.size() < a) graph.resize(a + 1);
            curVertecies.push_back(a);
        }
        for (int i = 0; i < curVertecies.size(); ++i) {
            for (int j = i + 1; j < curVertecies.size(); ++j) {
                graph[curVertecies[i]].push_back(curVertecies[j]); 
                graph[curVertecies[j]].push_back(curVertecies[i]);
            }
        }
        input.close();
    }

    for (int i = 0; i < graph.size(); ++i)
    {
        cout << i + 1 << ": ";
        sort(graph[i].begin(), graph[i].end());
        graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
        for (int j : graph[i])
            cout << j + 1 << " ";
        cout << endl;
    }

    std::cout.rdbuf(_cout);
    out.close();
}

void task_3() {
    fstream input;
    input.open("input\\matrix.txt", ios::in);

    int n, m;
    input >> n >> m;

    vector<vector<double>> mat_vec{(unsigned int)n};
    double** mat_arr = new double*[n];

    double el;
    for (int i = 0; i < n; ++i) {
        mat_arr[i] = new double[m];
        mat_vec[i].resize(m);
        for (int j = 0; j < m; ++j) {
            input >> el;
            mat_vec[i][j] = el;
            mat_arr[i][j] = el;
        }
    }

    double sum = 0, time;
    //vector sum
    Timer timer;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum += mat_vec[i][j];
        }
    }
    time = timer.elapsed();
    
    cout << "Вектор:" << endl << " Сумма: " << sum << " Время: " << time << endl;

    sum = 0;
    timer.reset();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            sum += mat_arr[i][j];
        }
    }
    time = timer.elapsed();

    cout << "Массив:" << endl << " Сумма: " << sum << " Время: " << time << endl;

    input.close();

    for (int i = 0; i < n; ++i) {
        delete[] mat_arr[i];
    }
    delete[] mat_arr;
}

//-----------------------------------------------------------------------------
double Sum(int n, double* a)
{
    double s = 0;

    for (int i = 0; i < n; i++)
    {
        s += a[i];
    }

    return s;
}
//-----------------------------------------------------------------------------
double SumVectorVector(vector< vector<double> >& a)
{
    double s = 0;

    int sz1 = a.size();
    for (int i = 0; i < sz1; i++)
    {
        int sz2 = a[i].size();
        for (int j = 0; j < sz2; j++)
        {
            s += a[i][j];
        }
    }

    return s;
}

//-----------------------------------------------------------------------------
void TestSumMatrix(int n, int m)
{
    vector< vector<double> > a;
    a.resize(n, vector<double>(m, 1));

    cout <<"| n: "<<n<<"\t| m: "<<m <<"\t| "<< SumVectorVector(a) << "\t| " << Sum(n * m, &a[0][0]) << "\t|" << endl;
}
//-----------------------------------------------------------------------------
void task_3_main()
{
    int n, m;
    int nm[] = {1, 1, 1, 10, 2, 1, 2, 10, 10, 10};
    for (int i = 0; i < 5; ++i) {
        TestSumMatrix(nm[i*2], nm[i*2+1]);
        cout << endl;
    }
    
}
//-----------------------------------------------------------------------------


int main() {
    setlocale(LC_ALL, "rus");
    int task = 0;
    cout << "Введите номер задания: ";
    cin >> task;
    switch (task) {
        case 1:
            task_1();
            break;
        case 2:
            task_2();
            break;
        case 3:
            task_3_main();
            break;
        default:
            cout << "Неверный ввод";
    }
    return 0;
}