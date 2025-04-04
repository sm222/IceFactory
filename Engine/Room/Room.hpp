
#ifndef  __ROOM__
# define __ROOM__

# include "../Type/Type.hpp"

# include <string.h>

class Room {
  public:
    //
    Room (const char* name);
    ~Room(void);
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
