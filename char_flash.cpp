/*
  output the background of the hacker.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

void sec_sleep(int sec)
{
    std::time_t start_time, current_time;
    std::time(&start_time);

    do {
        std::time(&current_time);
    } while ((current_time - start_time) < sec);
}

int main(int argc, char *argv[])
{
    std::string texts = "0123456789";

    int columns = 40;
    int rows = 50;

    std::srand((unsigned)std::time(nullptr));

    while (1) {
        for (int row = 0; row < rows; ++row) {
            int num = std::rand() % 9;
            std::string column_texts = "";

            for (int column = 0; column < columns; ++column) {
                column_texts.push_back(texts[num]);
            }

            std::cout << column_texts;
            std::cout << std::endl;
        }

        sec_sleep(1);
        system("clear");
    }


    return 0;
}
