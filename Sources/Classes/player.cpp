#include "Classes/player.hpp"

namespace CTRPluginFramework
{
    PlayerInstance* MH4U::Instances::MainPlayer = nullptr;

    PlayerInstance::PlayerInstance()
    {
        //PlayerInstance CTOR
    }

    PlayerInstance::~PlayerInstance()
    {
        MH4U::Instances::MainPlayer = nullptr;
    }

    PlayerInstance * PlayerInstance::GetInstance(void)
    {
        if (MH4U::Instances::MainPlayer == nullptr)
            MH4U::Instances::MainPlayer = new PlayerInstance;

        return MH4U::Instances::MainPlayer;
    }

    bool PlayerInstance::IsLoaded(void)
    {
        return MH4U::GamePointers::PlayerPointer.GetPointedAddress() != 0;
    }
}