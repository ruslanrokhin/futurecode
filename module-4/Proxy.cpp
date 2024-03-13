#include <iostream>

class Subject {
public:
    virtual void request() = 0;
};

class RealSubject : public Subject {
public:
    void request() override {
        std::cout << "RealSubject: Handling request." << std::endl;
    }
};

class Proxy : public Subject {
private:
    RealSubject* real_subject_;

public:
    Proxy(RealSubject* real_subject) : real_subject_(real_subject) {}

    void request() override {
        if (check_access()) {
            real_subject_->request();
            log_request();
        }
    }

    bool check_access() {
        std::cout << "Proxy: Checking access prior to firing a real request." << std::endl;
        return true;
    }

    void log_request() {
        std::cout << "Proxy: Logging the time of request." << std::endl;
    }
};

int main() {
    RealSubject* real_subject = new RealSubject();
    Proxy* proxy = new Proxy(real_subject);

    proxy->request();

    delete real_subject;
    delete proxy;
}