
#ifndef  __ROOM__
# define __ROOM__

# include "../Type/Type.hpp"
# include "../Groups/BaseGroups.hpp"

class Room {
  public:
    //
    Room (const char* name);
    ~Room(void);
    BaseGroup     Root;
    //
  protected:
    //
    //
  private:
    //
    char    __name[MAX_NAME_LEN + 1];
    //
};



#endif // __ROOM__
