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
    void                PrintTree(void) const;
    // Set
    bool                Select(const char* name, const char* type);
    bool                Add(Base* obj);
    bool                Remove(const char* name);
    void                Draw(int metod) const  { (void)metod; };
    size_t              Size(void) const;
    size_t              TotalSize(void) const;
  protected:
    //
    void                PrintTree(int def) const;
    void                Zero(void);
  //
  private:
  //
  std::vector<Base*>     __root;
  Base*                  __select;
  //
};


#endif