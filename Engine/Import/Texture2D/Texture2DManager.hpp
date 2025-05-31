#ifndef  __TEXTURE2D_MANAGER__
# define __TEXTURE2D_MANAGER__


#include "../IImport.hpp"

typedef std::map<std::string, Texture2D> MapTexture2D;


class Texture2DManager : public IImport<Texture2D> {
  public:
    //
      Texture2DManager(void);
      virtual ~Texture2DManager(void);
    //
    const Texture2D Get(const char* name)            const;
    bool            IsAllReadyLoad(const char* name) const;
    // Set
      // Add
        int         Add(const char* name);
      // Rm
        int         Remove(const char* name);
        void        Clear(void);
  protected:
    
  private:
};



#endif