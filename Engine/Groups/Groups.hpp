
#ifndef  __GROUPS_HPP__
# define __GROUPS_HPP__

# include <vector>
# include <stdio.h>
# include <string.h>

// Class declaration
template <typename T>

class Groups {
  public:
    Groups(void);
    ~Groups(void);
    //
    ssize_t Add(const T obj);
    bool    RmI(const unsigned int key);
    bool    Rm(const T self);
    bool    Run(void(*ft)(T),  unsigned int child = 0, const char* type = nullptr);
    //
    bool    AddChild(Groups* g);

  protected:
  private:
    std::vector<T>       __list;
    std::vector<Groups*> __child;
    bool parant;
};

# include "Groups.tpp"

#endif // GROUPS_HPP_
