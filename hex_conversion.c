#include <stdio.h>

int strlen(char *str)
{
    char *tmp = str;

    while (*str) {
        ++str;
    }

    return str - tmp;
}

int main(int argc, char *argv[])
{
    // 输入三个参数，

    char raw_data[20];
    int raw_hex, conversion_hex;
    scanf("%d %s %d", &raw_hex, raw_data, &conversion_hex);

    // 将源转换为十进制
    int i, num_10, value;
    for (i = strlen(raw_data); i >= 0; --i) {
        int temp = 0;
        
        if (raw_data[i] >= '0' && raw_data[i] <= '9') {
            temp = raw_data[i] - '0';
        } else {
            // 求出该位对应的十进制数
            temp = raw_data[i] - 'A' + 10;
        }

        num_10 += value * temp;
        value *= raw_hex;
    }

    printf("十进制数字为：%d\n", num_10);

    return 0;
}