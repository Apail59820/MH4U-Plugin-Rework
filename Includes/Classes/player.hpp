#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <3ds.h>
#include <CTRPluginFramework.hpp>

namespace CTRPluginFramework
{
    class PlayerInstance
    {
        public :

            PlayerInstance();
            virtual ~PlayerInstance();

            PlayerInstance * GetInstance(void);

            void Update(void);

            bool IsLoaded(void);

        private : 

        static PlayerInstance* MainPlayerInstance;
        
        static u32 PlayerAddy;

    };
}

#endif