#include <string>
#include <map>
#include <set>
#include <optional>
#include <cassert>

using namespace std;

class AccessControl
{
    //роль и его айди
    map<string, int> roles_;
    //айди пользователя и сет его ролей
    map<int, set<int>> grants_;

public:
    bool HasRole(int id, const std::string &roleName) const
    {
        auto role_id = GetRoleID(roleName);
        if (!role_id.has_value())
        {
            return false;
        }
        auto it = grants_.find(id);
        if (it == grants_.end())
        {
            return false;
        }
        return (it->second.count(role_id.value())) > 0;
    }
    optional<int> GetRoleID(const std::string &roleName) const
    {
        auto it = roles_.find(roleName);
        if (it == roles_.end())
        {
            return nullopt;
        }
        return it->second;
    }
    bool GrantRole(int id, const std::string &roleName)
    {
        // ищем айди роли
        auto role_id = GetRoleID(roleName);
        // проверяем наличие роли
        if (role_id.has_value())
        {
            // находим итератор на пользователя
            auto it = grants_.find(id);
            // проверяем наличие пользователя
            if (it != grants_.end())
            {
                // проверяем наличие роли у пользователя на данный момент
                if (it->second.count(role_id.value()) == 0)
                {
                    // нет такой роли
                    it->second.emplace(role_id.value());
                    return true;
                }
                // такая роль уже есть
                return false;
            }
            else
            {
                // добавляем пользователя и сразу добавляем ему в сет айди роли
                grants_.emplace(id, set<int>({role_id.value()}));
                return true;
            }
        }
        // такой роли не существует
        return false;
    }
    bool RemoveRole(int id, const std::string &roleName)
    {
       auto role_id = GetRoleID(roleName);
       if (role_id.has_value())
       {
             // находим итератор на пользователя
            auto it = grants_.find(id);
            // проверяем наличие пользователя
            if (it != grants_.end())
            {
                // проверяем наличие роли у пользователя на данный момент
                if (it->second.count(role_id.value()) == 0)
                {
                    return false;
                }
                it->second.erase(role_id.value());
                return true;
            }
            return false;
       }
       return false;
    }
    void RegisterRole(const std::string &roleName)
    {
        auto id = GetRoleID(roleName);
        if (!id.has_value())
        {
            roles_.emplace(roleName, roles_.size());
        }
    }
};
int main(int argc, char const *argv[])
{
    AccessControl control;
    control.RegisterRole("ADMIN");
    assert(control.GrantRole(1, "ADMIN") == 1);
    assert(control.GrantRole(1, "BANNED") == 0); // 0
    control.RegisterRole("BANNED");
    assert(control.GrantRole(1, "BANNED") == 1);  // 1
    assert(control.HasRole(1, "BANNED") == 1);    // 1
    assert(control.HasRole(1, "MODERATOR") == 0); // 0
    assert(control.HasRole(2, "ADMIN") == 0);     // 0AccessControl control;
    return 0;
}
