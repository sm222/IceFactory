#ifndef  __I_IMPORT__
# define __I_IMPORT__

# include "../Type/Type.hpp"
# include <map>

/// / / / / / / / / / / / / / / / / / / / / / /
//*    storage of data import by the engine
//* like
//*  - Model
//*  - Sound
//*  - Texture
/// / / / / / / / / / / / / / / / / / / / / / /

template <typename T>
class IImport {
  public:
    IImport(void) { __total = 0; };
    virtual  ~IImport(void) {/*\*/}; // clean what was import
    // Get
      virtual const T& Get(const char* name)        const = 0;
    // Set
      // Add
      virtual int      Add(const char* name)              = 0;
      // Rm
      virtual int      Remove(const char* name)           = 0;
      // Rm all
      virtual void     Clear(void)                        = 0;
    //
  protected:
    //
    std::map<std::string, T>    __data;
    size_t                      __total;
    //
  private:
    //
    //
};



#endif