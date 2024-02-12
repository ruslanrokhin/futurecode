// Программирование на С++ - онлайн
// Контесты 2 модуля доступны по ссылкам:
// Программирование на С++ - онлайн
// - Классная работа - https://official.contest.yandex.ru/contest/50740/enter
// - Домашняя работа - https://official.contest.yandex.ru/contest/50741/enter
// - Промежуточная аттестация - https://official.contest.yandex.ru/contest/50742/enter

// - Классная работа - https://official.contest.yandex.ru/contest/50768/enter
// - Домашняя работа - https://official.contest.yandex.ru/contest/50769/enter
// - Промежуточная аттестация - https://official.contest.yandex.ru/contest/50770/enter

// https://vk.com/video-221370537_456239889

#include <iostream>
#include <vector>


int main()
{
std::vector<int> vec;
int N, a, obmen;
std::cin » N;
for (int i = 0; i < N; i++) {
std::cin » a;
vec.push_back(a);
}
for (int i = 0; i < N; i++) {
std::cout « vec[i] « " ";
}
// while (пока флаг = 1)
for (int i = 0; i < N-1; i++) {
if (vec[i] > vec[i + 1]){
// флаг = 1
obmen = vec[i];
vec[i] = vec[i + 1];
vec[i + 1] = vec[i];

}
// конец while 1 4 7 3
1 4 3 7 (1)
1 3 4 7 (1)
1 3 4 7 (0) -вышли

std::cout « "Hello World!\n";
}



Классная задача "Толя Карп"
#include <iostream>
#include <string>

struct MyStruct {
std::string namev;
int numberv;
std::string name;
std::string number;
void read(std::string s, int a) {
namev = s;
numberv = a;
}
std::string info() {
name = "Name: " + namev + ";";
number = "Number: " + std::to_string(numberv) + ";";
std::cout « name «"\n";
std::cout « number «"\n";
return (name + "\n" + number);
}
};
int main()
{
MyStruct ms;
std::string name1 = "Tolya - Karp";
int number1 = 777;
ms.read(name1, number1);
ms.info();
std::cout « "Hello World!\n";
}