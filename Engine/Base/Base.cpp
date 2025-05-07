#include "Base.hpp"

t_id  Base::__totalId = 0; // id

Base::Base(const char* name) : __type(TYPE_BASE), __id(MakeId()) {
  DEBUG_P(magenta, "Base::char %s", name);
  SetName(name);
  SetFtList();
  __metod = -1;
  __parent = nullptr;
  __isAlloc = false;
  #if (PRINT_ID_AT_BUILD)
    PrintId();
  #endif
}

Base::Base(const std::string& name) : __type(TYPE_BASE), __id(MakeId()) {
  DEBUG_P(magenta, "Base::string %s", name.c_str());
  SetName(name);
  SetFtList();
  __metod = -1;
  __parent = nullptr;
  __isAlloc = false;
  #if (PRINT_ID_AT_BUILD)
    PrintId();
  #endif
}

Base::~Base(void) {
  DEBUG_P(magenta, "Base::~");
}


void Base::Draw(int metod) const {
  (void)metod;
  return;
}

//*                  *//*                  *//
//*                                        *//
//*                  Name                  *//
//*                    &                   *//
//*                  Type                  *//
//*                                        *//
//*                  *//*                  *//

//* //
//* Get
//* //

const char* Base::GetName(void) const {
  return __name;
}

const char* Base::GetType(void) const {
  return __type;
}

t_id        Base::GetId(void) const {
  return __id;
}

// print name, type and id
void      Base::PrintId(void) const {
  DEBUG_P(cyan, "Name:%s Type:%s Id:%u", this->__name, this->__type, this->__id);
}

/// @brief return the total of Base made from the start of icefactory
t_id     Base::GetCurrentMaxId(void) {
  return __totalId;
}

//* //
//* Set
//* //

void Base::SetName(const char* name) {
  if (!name) {
    sprintf(__name, "noName");
  }
  else {
    size_t len = strlen(name);
    if (len > MAX_NAME_LEN) {
      memcpy(__name, name, MAX_NAME_LEN - 1);
      __name[MAX_NAME_LEN] = 0;
    }
    else {
      memcpy(__name, name, len);
      __name[len] = 0;
    }
  }
}

void Base::SetName(const std::string& name) {
  SetName(name.c_str());
}

void  Base::Help(void) {
  DEBUG_P(blue, "Base::Help");
}

void    Base::Hello(Base& self) {
  DEBUG_P(yello, "Hello from %s, Type:%s Id:%u", self.GetName(), self.GetType(), self.GetId());
}

void  Base::SetFtList(void) {
  interface.Add(Base::Hello, "hello", "say hello");
}



t_id  Base::MakeId(void) {
  return ++__totalId;
}

int Base::GetMetod(void) const {
  return __metod;
}


//*                  *//*                  *//
//*                                        *//
//*                                        *//
//*                                        *//
//*                                        *//
//*                  *//*                  *//




// SET

void    Base::SetMetod(const int metod) {
  __metod = metod;
}

void  Base::SetIsAlloc(bool v) {
  __isAlloc = v;
}

bool  Base::GetIsAlloc(void) {
  return __isAlloc;
}

/// @brief set the parant to addr of parant
/// @return return false if parent was all ready set
bool Base::__SetParent(const Base& parant) {
  if (__parent)
    return false;
  DEBUG_P(pink, "set parant to %p", &parant);
  __parent = &parant;
  return true;
}

/// @brief set parant ptr to nullptr
/// @return return false if ptr all ready at nullptr
bool Base::__SetParantNone(void) {
  bool rm = false;
  if (__parent) {
    DEBUG_P(pink, "remove parant %p", __parent);
    __parent = nullptr;
    rm = true;
  }
  return rm;
}