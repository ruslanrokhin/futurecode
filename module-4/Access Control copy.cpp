#include <string>
#include <map>
#include <set>
#include <optional>
#include <iostream>
#include <cassert>

using namespace std;
using namespace std::literals;

using UserSetPtr = std::set<int> *;

const char *ADMIN = "ADMIN";
const char *MODERATOR = "MODERATOR";
const char *BANNED = "BANNED";
const char *USER = "USER";

class AccessControl
{
public:
    // роль и его айди
    map<string, int> roles_;
    // айди пользователя и сет его ролей
    map<int, set<int>> grants_;
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

class MyAccessControl : public AccessControl
{
public:
    int role_admin_id, role_moderator_id, role_banned_id, role_user_id;
    MyAccessControl(int admin)
    {
        RegisterRole(ADMIN);
        role_admin_id = GetRoleID(ADMIN).value();
        RegisterRole(MODERATOR);
        role_moderator_id = GetRoleID(MODERATOR).value();
        RegisterRole(BANNED);
        role_banned_id = GetRoleID(BANNED).value();
        RegisterRole(USER);
        role_user_id = GetRoleID(USER).value();

        GrantRole(admin, role_admin_id);
    };
    bool HasUser(int id)
    {
        return (grants_.find(id) != grants_.end());
    }
    bool HasRole(UserSetPtr user_ptr, const int role_id) const
    {
        return (user_ptr->count(role_id)) > 0;
    }
    bool HasRole(int user_id, const int role_id) const
    {
        auto user_ptr = grants_.find(user_id);
        return (user_ptr->second.count(role_id)) > 0;
    }
    bool GrantRole(int id, const int role_id)
    {
        // находим итератор на пользователя
        auto it = grants_.find(id);
        // проверяем наличие пользователя
        if (it != grants_.end())
        {
            // проверяем наличие роли у пользователя на данный момент
            if (it->second.count(role_id) == 0)
            {
                // нет такой роли
                it->second.emplace(role_id);
                return true;
            }
            // такая роль уже есть
            return false;
        }
        else if (role_id != role_banned_id)        
        {
            // добавляем пользователя и сразу добавляем ему в сет айди роли
            grants_.emplace(id, set<int>({role_id}));
            return true;
        }
        // такой роли не существует
        return false;
    };
    bool RemoveRole(int id, int role_id)
    {
        if (role_id)
        {
            // находим итератор на пользователя
            auto it = grants_.find(id);
            // проверяем наличие пользователя
            if (it != grants_.end())
            {
                // проверяем наличие роли у пользователя на данный момент
                if (it->second.count(role_id) == 0)
                {
                    return false;
                }
                it->second.erase(role_id);
                return true;
            }
        }
        return false;
    };
};
struct ResposeData
{
    ResposeData(bool Success) : Success(Success), Response("")
    {
    }
    ResposeData() : Success(false), Response("")
    {
    }
    bool Success;
    std::string Response;
};
class Pausable
{
    bool chat_stream = true;

public:
    ResposeData StopChat()
    {
        ResposeData result;
        if (chat_stream == true)
        {
            chat_stream = false;
            result.Success = true;
        }
        return result;
    }
    ResposeData ResumeChat()
    {
        ResposeData result;
        if (chat_stream == false)
        {
            chat_stream = true;
            result.Success = true;
        }
        return result;
    }
};

class SystemBase : MyAccessControl, Pausable
{

public:
    SystemBase(int admin) : MyAccessControl(admin){};
    ResposeData BanUser(int sender, int user)
    {
        return (GrantAnyRole(sender, user, role_banned_id));
    }
    ResposeData UnBanUser(int sender, int user)
    {
        ResposeData result;
        if (HasUser(user))
        {
            // проверяем права сендера, если баним то пропускам и модератора
            if (HasRole(sender, role_admin_id) || HasRole(sender, role_moderator_id))
            {
                result.Success = RemoveRole(user, role_banned_id);
            }
        }
        return result;
    }
    ResposeData GrantAnyRole(int sender, int user, int role_id)
    {
        ResposeData result;
        if (HasUser(sender))
        {
            if (HasRole(sender, role_admin_id) && (role_id == role_moderator_id || role_id == role_admin_id || role_id == role_user_id))
            {
                result.Success = GrantRole(user, role_id);
            }
            
            if ((role_id == role_moderator_id ||role_id == role_banned_id) && HasRole(sender, role_moderator_id))
            {
                result.Success = GrantRole(user, role_id);
            }
        }
        return result;
    }
    ResposeData RegisterNewUser(int sender, int newUser)
    {
        return GrantAnyRole(sender, newUser, role_user_id);
    }
    ResposeData GrantModeratorRole(int sender, int user)
    {
        return GrantAnyRole(sender, user, role_moderator_id);
    }
    ResposeData GrantAdminRole(int sender, int user)
    {
        return GrantAnyRole(sender, user, role_admin_id);
    }
    ResposeData StopChat(int sender)
    {
        ResposeData result;
        if (HasRole(sender, role_admin_id))
        {
            result = Pausable::StopChat();
        }
        return result;
    }
    ResposeData ResumeChat(int sender)
    {
        ResposeData result;
        if (HasRole(sender, role_admin_id))
        {
            result = Pausable::ResumeChat();
        }
        return result;
    }
};

void PrintResponse(const ResposeData &response)
{
    std::cout << "result: " << response.Success << "\nresponse: " << response.Response << "\n";
}

int main()
{
    const int ADMiN = 1;
    const int MODeRATOR = 2;
    const int BANNeD = 3;
    const int BANNeD32 = 4;
    SystemBase chat(1);
    std::cout << "hello" << std::endl;

    assert(chat.RegisterNewUser(ADMiN, MODeRATOR).Success == 1);

    assert(chat.RegisterNewUser(ADMiN, MODeRATOR).Success == 0);

    assert(chat.BanUser(MODeRATOR, BANNeD32).Success == 0);

    assert(chat.GrantModeratorRole(ADMiN, MODeRATOR).Success == 1);

    assert(chat.RegisterNewUser(MODeRATOR, BANNeD).Success == 0);

    assert(chat.RegisterNewUser(ADMiN, BANNeD).Success == 1);

    assert(chat.BanUser(MODeRATOR, BANNeD).Success == 1);

    assert(chat.BanUser(ADMiN, BANNeD).Success == 0);

    assert(chat.StopChat(MODeRATOR).Success == 0);

    assert(chat.StopChat(ADMiN).Success == 1);

    assert(chat.StopChat(ADMiN).Success == 0);

    assert(chat.ResumeChat(MODeRATOR).Success == 0);

    assert(chat.ResumeChat(ADMiN).Success == 1);

    assert(chat.ResumeChat(ADMiN).Success == 0);

    assert(chat.UnBanUser(ADMiN, BANNeD).Success == 1);

    assert(chat.BanUser(MODeRATOR, BANNeD).Success == 1);

    assert(chat.UnBanUser(MODeRATOR, BANNeD).Success == 1);

    assert(chat.UnBanUser(ADMiN, BANNeD).Success == 0);

    assert(chat.UnBanUser(MODeRATOR, BANNeD).Success == 0);

    assert(chat.BanUser(MODeRATOR, BANNeD32).Success == 0);

    assert(chat.BanUser(MODeRATOR, BANNeD).Success == 1);
    
    assert(chat.UnBanUser(BANNeD, ADMiN).Success == 0);

    assert(chat.UnBanUser(ADMiN, BANNeD32).Success == 0);

    assert(chat.GrantModeratorRole(MODeRATOR, BANNeD32).Success == 1);
}
