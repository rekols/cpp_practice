#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>

using namespace std;

// 函数：得到list容器中的某个元素
string get_value(list<string> ls, int index) {
    list<string>::iterator itor = ls.begin();
    for (int i = 0; i < index; ++i) {
        itor++;
    }
    return *itor;
}

// 函数功能: 将字符串数字前补0 (小于4位前面自动补0)
string format_number(string str) {
    int place = 4;
    string num = str;
    if (num.size() < place) {
        // 需要补上的位数
        int lack = place - num.size();
        // 往前追加 0
        while (lack) {
            num.insert(0, "0");
            --lack;
        }
    }

    return num;
}

// 函数：将一些4, 5, 6位数存入txt文档
void save_to_file(const string path)
{
    ofstream out;
    // 打开文件
    out.open(path, ios::binary | ios::app | ios::in | ios::out);

    for (int i = 0; i < 50; ++i) {
        // 随机生成0-999999的数字，并转换成字符串类型
        string num = to_string(rand() % 999999);
        // 格式化这个数字，前面补0
        num = format_number(num);
        // 将数字字符串写入txt文件中
        out << num << endl;
    }

    out.close();
}

int main(int argc, char *argv[])
{
    // 首先随机生成50个数并且保存到txt
    save_to_file("test.txt");

    // 存储数字容器
    list<string> numbers;
    // 读取txt文件内容
    ifstream in;
    in.open("test.txt", ios::binary);
    string line;
    // 每行每行读取
    while (getline(in, line)) {
        // 添加到容器中
        numbers.push_back(line);
    }

    // 首先随机读取
    int index = rand() % numbers.size();
    string num = get_value(numbers, index);

    // 循环终止条件为正确数50
    int correct_count = 1;
    while (correct_count < 10) {
        string in_num;
        cout << "当前的数为: " << num << endl; //这句话可以去掉
        cout << "请输入一个数: ";
        cin >> in_num;

        // 正确返回 true，然后随机才能随机读取一个数
        if (in_num == num) {
            cout << "true" << endl;
            // 计正确数
            ++correct_count;

            // 再重新随机读取一个数
            int index = rand() % numbers.size();
            num = get_value(numbers, index);
        } else {
            // 不正确返回 try again，然后重新输入直到正确 
            cout << "try again" << endl;
        }
    }

    // 返回over程序结束
    cout << "over" << endl;

    return 0;
}
