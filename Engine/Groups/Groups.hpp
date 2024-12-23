
#ifndef  __GROUPS_HPP__
# define __GROUPS_HPP__

# include <vector>
# include <stdio.h>

// Class declaration
template <typename T>

class Groups {
  public:
    Groups(void);
    ~Groups(void);
    ssize_t Add(const T obj);
    bool    Rm(const size_t key);
    bool    Rm(const T self);
    bool    Run(int(*ft)(T));
  protected:
  private:
    std::vector<T>       __list;
    std::vector<Groups*> __child;
    bool parant;
};

# include "Groups.tpp"

#endif // GROUPS_HPP_
