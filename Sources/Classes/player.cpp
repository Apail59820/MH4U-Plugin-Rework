#include "Classes/player.hpp"

namespace CTRPluginFramework
{
    PlayerInstance* PlayerInstance::MainPlayerInstance = nullptr;
    u32 PlayerInstance::PlayerAddy = 0;

    PlayerInstance::PlayerInstance()
    {
        this->Update();
    }

    ~PlayerInstance::PlayerInstance()
    {
        MainPlayerInstance = nullptr;
    }

    PlayerInstance * PlayerInstance::GetInstance(void)
    {
        if (MainPlayerInstance == nullptr)
            MainPlayerInstance = new PlayerInstance;

        return MainPlayerInstance;
    }

    void PlayerInstance::Update(void)
    {
        PlayerInstance = *(u32 *)Player_Pointer;
    }

    bool PlayerInstance::IsLoaded(void)
    {
        return PlayerInstance != 0;
    }
}