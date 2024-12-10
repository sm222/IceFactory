#ifndef __ICE_FACTORY__
# define __ICE_FACTORY__

# ifndef VERTION
#  define VERTION 0
# endif

# include "Type/Type.hpp"
# include "Render/Render.hpp"
# include <raylib.h>
# include <raymath.h>

/*
    class Singleton {
    public:
        static Singleton* Instance();
    protected:
        Singleton();
    private:
        static Singleton* _instance;
    };

    Singleton* Singleton::_instance = 0;
    
    Singleton* Singleton::Instance () {
        if (_instance == 0) {
            _instance = new Singleton;
        }
        return _instance;
    }
*/

void initEngine(void);
void closeEngine(void);
int  getStatusEngine(void);
void initRaylib(void);





#endif
