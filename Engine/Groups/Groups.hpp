
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
    ssize_t Add(const T& obj);
    ssize_t Add(std::vector<T>& objs);
    bool    RmI(const unsigned int key);
    bool    Rm(const T self);
    bool    Run(void(*ft)(T, int), int setting, unsigned int depth = 0, const char* type = nullptr);
    //
    unsigned int GetId(void) const ;
    //
    Groups* GetGroupChildById(unsigned int id);
    T*      Find(const char* name, unsigned int depth = 0);
    //
    bool    AddChild(Groups* group);
    //
    bool    RmChildI(const size_t key);
    bool    RmChild(const Groups *self);
    //
    void    MoveToward(const Vector3& direction, const float ammout);
    //
    void    Delete(unsigned int depth = 0, const char* type = nullptr);
    //
  protected:
  private:
    static unsigned int  __MakeId(void);
    std::vector<T>       __list;
    std::vector<Groups*> __child;
    unsigned int         __id;
    bool parant;
};


# include "Groups.tpp"

#endif // GROUPS_HPP_
