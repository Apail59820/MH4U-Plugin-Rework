#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <3ds.h>
#include <CTRPluginFramework.hpp>

#include "addresses.hpp"

namespace CTRPluginFramework
{
    class PlayerInstance
    {
        public :

            PlayerInstance();
            virtual ~PlayerInstance();

            static PlayerInstance * GetInstance(void);

            bool IsLoaded(void);
    };

    namespace MH4U
    {
        namespace Instances
        {
            extern PlayerInstance* MainPlayer;
        }
    }
}

#endif