#include <cassert>
#include <string>
#include <set>

struct NamesHolder
{
  std::set<std::string> names_;
  void AddName(const std::string &name)
  {
    names_.insert(name);
  }
  bool HasName(const std::string &name)
  {
    return (names_.find(name) != names_.end());
  }
  unsigned long long Size()
  {
    return names_.size();
  }
};

int main()
{
  NamesHolder holder;
  holder.AddName("Alice");
  holder.AddName("Bob");
  holder.AddName("Bob");
  holder.AddName("Bob");
  assert(holder.HasName("Mark") == false);
  assert(holder.HasName("Alice") == true);
  assert(holder.HasName("Bob") == true);
  assert(holder.Size() == 2);
}