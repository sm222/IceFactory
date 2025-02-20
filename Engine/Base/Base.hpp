#ifndef  __BASE_HPP__
# define __BASE_HPP__

# include "../Type/Type.hpp"

# define TYPE_BASE "TYPE_BASE"

class Base {
  public:
    Base(const char* name);
    Base(const std::string& name);
    virtual ~Base(void);
  //
    // Get
    const char*         GetName(void) const ;
    const char*         GetType(void) const ;
    // Set
    void                SetName(const char* name);
    void                SetName(const std::string& name);
  protected:
  //
    virtual void        Zero(void) = 0;
    char              __name[MAX_NAME_LEN + 1];
    const char*       __type;
  //
  private:
  //
  //
};


#endif