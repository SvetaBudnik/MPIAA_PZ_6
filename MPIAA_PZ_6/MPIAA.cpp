#include<stack>
#include <iostream>
#include <vector>
#include<algorithm>
#include<set>
#include<fstream>

void task_1() {
    int a;
    std::stack<int> s;
    do {
        std::cin >> a;
        s.push(a);
    } while (a != 0);
    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }

}

void task_2() {
    int a;
    std::vector<int> v;
    do {
        std::cin >> a;
        v.push_back(a);
    } while (a != 0);
    auto s = std::set<int>(v.begin(), v.end());
    v.assign(s.begin(), s.end());
    for (auto i : v) {
        std::cout << i<<" ";
    }
}

void task_3() {
    std::vector<std::vector<int>> v;
    int a, b;
    do {
        std::cin >> a >>b;
        if (a == 0 && b == 0) break;
        if (v.size() < a + 1) {
            v.resize(a+1);
        }
        v.at(a).push_back(b);
    } while (true);

    for (auto i : v) {
        std::sort(i.begin(), i.end());
        for (auto j : i) {
            std::cout << j << " ";
        }
        std::cout<<std::endl;
    }
}

int main()
{
    std::cout<< "Starting task_1" << std::endl;
    task_1();
    std::cout << std::endl << "Starting task_2" << std::endl;
    task_2();

    std::fstream out;
    out.open("output.txt", std::ios::out);
    std::streambuf* _cout = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());
    task_3();
    std::cout.rdbuf(_cout);
}
