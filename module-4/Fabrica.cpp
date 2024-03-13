#include <iostream>
#include <memory>

class ITradePair {
    const std::string currencyFirst;
    const std::string currencySecond;
public:
    ITradePair(const std::string& nameFirst,
               const std::string& nameSecond) : currencyFirst(nameFirst),
                                                currencySecond(nameSecond) {
    }

    virtual void Trade() = 0;

    std::pair<std::string, std::string> GetNames() const {
        return {currencyFirst, currencySecond};
    }
    virtual ~ITradePair() {};
};

class MoexTradePair : public ITradePair {
public:
    MoexTradePair(const std::string& nameFirst,
                  const std::string& nameSecond) : ITradePair(nameFirst, nameSecond) {};

    void Trade() override {
        // Пусть здесь идет отправка на обычную биржу
        std::cout << "Trade MOEX\n";
    };

};

class CryptoTradePair : public ITradePair {
    const std::string currencyFirst;
    const std::string currencySecond;
public:
    CryptoTradePair(const std::string& nameFirst,
                    const std::string& nameSecond) : ITradePair(nameFirst, nameSecond) {};

    void Trade() {
        // Пусть здесь идет отправка на криптовалютную биржу
        // Рассчитывается газ на отправку и т.п.
        std::cout << "Trade Crypto\n";
    };
};

class ITradePairFactory {
public:
    virtual std::shared_ptr<ITradePair> Create(const std::string& nameFirst, const std::string& nameSecond) = 0;
};

class MoexTradePairFactory : public ITradePairFactory{
public:
    std::shared_ptr<ITradePair> Create(const std::string& nameFirst, const std::string& nameSecond) {
        return std::make_shared<MoexTradePair>(nameFirst, nameSecond);
    }
};

class CryptoTradePairFactory : public ITradePairFactory {
public:
    std::shared_ptr<ITradePair> Create(const std::string& nameFirst, const std::string& nameSecond) {
        return std::make_shared<CryptoTradePair>(nameFirst, nameSecond);
    }
};

void DoSomeStuff(const std::shared_ptr<ITradePairFactory>& factory) {
    auto pair1 = factory->Create("USD", "RUB");
    auto pair2 = factory->Create("USD", "EUR");
    pair1->Trade();
    pair2->Trade();
}

int main() {
    std::shared_ptr<ITradePairFactory> factory;
    if ("Если код для MOEX") {
        factory = std::make_shared<MoexTradePairFactory>();
    } else {
        factory = std::make_shared<CryptoTradePairFactory>();
    }
    DoSomeStuff(factory);
}