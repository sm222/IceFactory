
#include "BaseGroups.hpp"

void   BaseGroup::Zero(void) {
  bzero(__name, MAX_NAME_LEN);
}

BaseGroup::BaseGroup(const char* name) : Base(name) {
  __type = TYPE_BASE_GROUP;
  SetName(name);
}

BaseGroup::BaseGroup(const std::string& name) : BaseGroup(name.c_str()) { /*\*/ }

BaseGroup::~BaseGroup(void) { /*\*/ }


/// @brief if return false, __select alway set back to nullptr
/// @param name
/// @return 
bool    BaseGroup::Select(const char* name, const char* type = nullptr) {
  std::vector<Base*>::iterator it;
  for (it = __root.begin(); it != __root.end(); it++) {
    Base& ref = *(*it);
    if (strncmp(name, ref.GetName(), strlen(name))) {
      __select = (*it);
      return true;
    }
  }
  __select = nullptr;
  return false;
}
