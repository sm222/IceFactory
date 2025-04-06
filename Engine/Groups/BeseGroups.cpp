
#include "BaseGroups.hpp"

void   BaseGroup::Zero(void) {
  bzero(__name, MAX_NAME_LEN);
}

BaseGroup::BaseGroup(const char* name) : Base(name) {
  __type = TYPE_BASE_GROUP;
  DEBUG_P(magenta, "BaseGroup::char");
  SetName(name);
}

BaseGroup::BaseGroup(const std::string& name) : BaseGroup(name.c_str()) { 
  DEBUG_P(magenta, "BaseGroup::string");
}

BaseGroup::~BaseGroup(void) { 
  DEBUG_P(magenta, "BaseGroup::~");
}


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

void BaseGroup::PrintTree(void) const {
  const char* name = this->GetName();
  Debug("", 0, nullptr, green, name);
  std::vector<Base*>::const_iterator it;
  for (it = __root.begin(); it != __root.end(); it++) {
    const char* type = (*it)->GetType();
    if (strncmp(TYPE_BASE_GROUP, type, strlen(TYPE_BASE_GROUP) + 1) == 0) {
      const BaseGroup& ref = (BaseGroup&)*(*it);
      ref.PrintTree(1);
    }
    else {
      Debug("", 1, nullptr, green, "\tname:%s type:%s" ,(*it)->GetName(), (*it)->GetType());
    }
  }
}

void BaseGroup::PrintTree(int def) const {
  char space[100];
  memset(space, '\t', 99);
  if (def + 1 < 98)
    space[def + 1] = 0;
  else
    space[98] = 0;
  const char* name = this->GetName();
  Debug("", def, nullptr, green, "\t%s", name);
  std::vector<Base*>::const_iterator it;
  for (it = __root.begin(); it != __root.end(); it++) {
    const char* type = (*it)->GetType();
    if (strncmp(TYPE_BASE_GROUP, type, strlen(TYPE_BASE_GROUP) + 1) == 0) {
      const BaseGroup& ref = (BaseGroup&)*(*it);
      ref.PrintTree(def + 1);
    }
    else {
      Debug("", def + 1, nullptr, green, "%sname:%s type:%s", space, (*it)->GetName(), (*it)->GetType());
    }
  }
}

bool  BaseGroup::Add(Base* obj) {
  if (!obj)
    return false;
  std::vector<Base*>::iterator it;
  for (it = __root.begin(); it != __root.end(); it++) {
    if ((*it) == obj) {
      DEBUG_P(red, "BaseGroup::Add %p(%s) is all ready in %s", obj, obj->GetName(), this->GetName());
      return false;
    }
  }
  DEBUG_P(green, "%s add %p(%s)", this->GetName(), obj, obj->GetName());
  obj->__SetParent(*this);
  __root.push_back(obj);
  return true;
}

bool  BaseGroup::Remove(const char* name) {
  if (!name)
    return false;
  std::vector<Base*>::iterator it;
  const size_t nameLen = strlen(name) + 1;
  for (it = __root.begin(); it != __root.end(); it++) {
    if (strncmp(name, (*it)->GetName(), nameLen) == 0) {
      (*it)->__SetParantNone();
      __root.erase(it);
      DEBUG_P(green, "BaseGroup::Remove %s: %s", this->GetName(), name);
      return true;
    }
  }
  DEBUG_P(red, "BaseGroup::Remove %s: can't fine %s", this->GetName(), name);
  return false;
}