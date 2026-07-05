#include "Group.hpp"

Group::Group(const char* name) : Group(name, GROUP_DEFAULT_SIZE) {
}

Group::Group(const char* name, unsigned int size) {
  bzero(__name, MAX_NAME_LEN + 1);
  memcpy(__name, name, strlen(name));
  __list.reserve(size);
  DEBUG_P(TXT_MAG, " %s", name);
}


Group::~Group(void) {
  DEBUG_P(TXT_MAG, "%s", __name);
}


bool Group::Add(Base* b) {
  if (!b)
    return false;
  __list.push_back(b);
  return true;
}


bool Group::CopyFrom(VectorBase& list) {
  for (GroupIt it = list.begin(); it != list.end(); it++) {
    __list.push_back(*it);
  }
  return true;
}

bool Group::RemoveFrom(VectorBase& list) {
  for (GroupIt it = list.begin(); it != list.end(); it++) {
    Base& a = *(*it);
    for (GroupIt it2 = __list.begin(); it2 != __list.end(); it2++) {
      Base& b = *(*it2);
      if (a.GetId() == b.GetId()) {
        __list.erase(it2);
        break ;
      }
    }
  }
  return true;
}

bool Group::Remove(t_id id) {
  for (GroupIt it = GetStart(); it != GetEnd(); it++) {
    if ((*it)->GetId() == id) {
      __list.erase(it);
      return true;
    }
  }
  return false;
}

bool Group::Remove(char* name) {
  for (GroupIt it = GetStart(); it != GetEnd(); it++) {
    if (std::strcmp((*it)->GetName(), name) == 0) {
      __list.erase(it);
      return true;
    }
  }
  return false;
}

const Base* Group::Get(t_id id) const {
  for (GroupCIt it = GetStart(); it != GetEnd(); it++) {
    if (id == (*it)->GetId())
      return *it;
  }
  return nullptr;
}

const Base* Group::Get(char* name) const {
  for (GroupCIt it = GetStart(); it != GetEnd(); it++) {
    if (std::strcmp((*it)->GetName(), name) == 0)
      return *it;
  }
  return nullptr;
}

Base* Group::Get(t_id id) {
  for (GroupIt it = GetStart(); it != GetEnd(); it++) {
    if (id == (*it)->GetId())
      return *it;
  }
  return nullptr;
}

Base* Group::Get(char* name) {
  for (GroupIt it = GetStart(); it != GetEnd(); it++) {
    if (std::strcmp((*it)->GetName(), name) == 0)
      return *it;
  }
  return nullptr;
}

void Group::List(void) const {
  DEBUG_P(TXT_YEL, "Group Name:%s");
  for (GroupCIt it = GetStart(); it != GetEnd(); it++) {
    (*it)->PrintId();
  }
}

GroupIt  Group::GetStart(void) { return __list.begin(); }
GroupCIt Group::GetStart(void) const { return __list.begin(); }

GroupIt  Group::GetEnd(void) { return __list.end(); }
GroupCIt Group::GetEnd(void) const { return __list.end(); }