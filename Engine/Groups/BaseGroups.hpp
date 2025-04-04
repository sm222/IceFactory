#ifndef  __BASE_GROUPS__
# define __BASE_GROUPS__

# include "../Base/Base.hpp"

# define TYPE_BASE_GROUP "TYPE_BASE_GROUP"

class BaseGroup : public Base {
  public:
    BaseGroup(const char* name);
    BaseGroup(const std::string& name);
    ~BaseGroup(void);
    //
    // Get

    // Set
      bool              Select(const char* name, const char* type);
  protected:
  //
    void                Zero(void);
  //
  private:
  //
  std::vector<Base*>     __root;
  Base*                  __select;
  //
};


#endif