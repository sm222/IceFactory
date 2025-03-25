#ifndef  __MODEL_MANAGER__
# define __MODEL_MANAGER__

# include "../IImport.hpp"


typedef std::map<std::string, Model> MapModel;

class ModelManager : public IImport<Model> {
  public:
    //
      ModelManager(void);
      virtual ~ModelManager(void);
    //
    const Model&   Get(const char* name)        const;
    // Set
      // Add
        int        Add(const char* name);
      // Rm
        int        Remove(const char* name);
        void       Clear(void);
  protected:
    
  private:
};



#endif