#include <string>
#include <vector>
#include <iostream>

class TradePair {
    const std::string currencyFirst;
    const std::string currencySecond;
public:
    TradePair(const std::string& nameFirst,
              const std::string& nameSecond) : currencyFirst(nameFirst),
                                               currencySecond(nameSecond) {
        // Проверяем, что nameFirst - существует
        // Проверяем, что nameSecond - существует
        // Создаем подключение к серверу и т.п.
    }
    void Trade() {};
    std::pair<std::string, std::string> GetNames() const {
        return {currencyFirst, currencySecond};
    }
};

class TradePairFactory {
    static int a;
public:
    static TradePair Create(const std::string& nameFirst, const std::string& nameSecond) {
        a++;
        return TradePair(nameFirst, nameSecond);
    }
};

int TradePairFactory::a = 0;

class animal {
    public:
    std::string name;
    animal() {
        std::cout << "animal" <<std::endl;
    }
    virtual ~animal() {
        std::cout << "~animal" <<std::endl;
    }
};

class dog : public animal {
    public:
    dog() {
        std::cout << "dog" <<std::endl;
    }
    virtual ~dog() {
        std::cout << "~dog" <<std::endl;
    }
};

class cat : public animal {
    public:
    virtual ~cat() {
        std::cout << "~cat" <<std::endl;
    }
    cat() {
        std::cout << "cat" <<std::endl;
    }
};

int main() {

std::vector<animal> zoo;

         std::cout <<std::endl<<std::endl<<std::endl << "///////////////////////////////////" <<std::endl;

 
 dog d;

    auto pair1 = TradePairFactory::Create("RUB", "USD");
    auto pair2 = TradePairFactory::Create("USD", "EUR");
}