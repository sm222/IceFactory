#ifndef  __RENDER__
# define __RENDER__

#include "../Base/Base.hpp"

typedef std::vector<Base*>         VectorBase;
typedef VectorBase::iterator       GroupIt;
typedef VectorBase::const_iterator GroupCIt;

# define GROUP_DEFAULT_SIZE 50

class Group {
  public:
    //
    Group(const char* name, unsigned int size);
    Group(const char* name);
    ~Group(void);
    //
    bool Add(Base* b);
    bool CopyFrom(VectorBase& list);
    bool RemoveFrom(VectorBase& list);
    bool Remove(t_id id);
    bool Remove(char* name);
    //
    const Base* Get(t_id id) const;
    const Base* Get(char* name) const;
    //
    Base*       Get(t_id id);
    Base*       Get(char* name);
    //
    GroupIt GetStart(void);
    GroupIt GetEnd(void);
    //
    GroupCIt GetStart(void) const;
    GroupCIt GetEnd(void) const;
    //
    void     List(void) const;
  private:
    VectorBase     __list;
    char           __name[MAX_NAME_LEN + 1];
    //
};



#endif
