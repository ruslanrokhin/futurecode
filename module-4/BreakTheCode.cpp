#include <string>
#include <cassert>
#include <iostream>
using namespace std;
class SecretClass {
private:
 std::string token;
protected:
 void SetTokenTo(SecretClass& another) {
 another.token = token;
 }
public:
 SecretClass(const std::string& token) : token(token) {};
 std::string GetToken() const {
 return token;
 }
};
class MySecretClass : public SecretClass
{
    public:
    void ChangeTokenTo(SecretClass& another)
    {
        SetTokenTo(another);
    }
    MySecretClass(const string &something) : SecretClass(something)
    {
    }
};
void externalFunction(SecretClass& secret)
{
    MySecretClass another("CODE");
    another.ChangeTokenTo(secret);
}
int main() {
 SecretClass secret("FUTURE");
 externalFunction(secret);
 assert(secret.GetToken() == "CODE");
}
