#include "addresses.hpp"

#define SHOW_DEBUG

namespace CTRPluginFramework
{   

    MemoryAddress::MemoryAddress()
    {
        //MemoryAddress CTOR
    }

    MemoryAddress::MemoryAddress(u32 Address)
    {
        this->SetAddress(Address);
    }

    void MemoryAddress::SetAddress(u32 Address)
    {
        if (Process::CheckAddress(Address)) this->m_Address = Address; 
    }

    template<typename T> void MemoryAddress::SetValue(T Value)
    {
        *(T *)this->GetAddress() = Value;
    }

    u32 MemoryAddress::GetAddress(void) const
    {
        return this->m_Address; 
    }

    template<typename T> T MemoryAddress::GetValue(void) const
    {
        return *(T *)this->m_Address;
    }

    MemoryPointer::MemoryPointer()
    {
        //MemoryPointer CTOR
    }

    MemoryPointer::MemoryPointer(u32 PointerAddress)
    {
        this->SetPointer(PointerAddress); 
    }

    void MemoryPointer::SetPointer(u32 PointerAddress)
    {
        if (Process::CheckAddress(PointerAddress))
        {
            this->m_PointerAddress = PointerAddress;
            this->m_PointedAddress = *(u32 *)PointerAddress;
        }
    }

    u32 MemoryPointer::GetPointerAddress(void) const
    {
        return this->m_PointerAddress; 
    }

    u32 MemoryPointer::GetPointedAddress(void) const
    {
        return this->m_PointedAddress; 
    }

    template<typename T> T MemoryPointer::GetPointedAddressValue(void) const
    {
        return *(T *)this->m_PointedAddress; 
    }

    template<typename T> void MemoryPointer::AddToPointerAddress(T Offset)
    {
        this->m_PointerAddress += Offset;
        this->SetPointer(this->m_PointerAddress);
    }

    void InitializePluginData_Callback(void)
    {
        static bool hasBeenInitializedOnce = false;

        #ifdef SHOW_DEBUG
        if (!hasBeenInitializedOnce)
        {
            OSD::Notify(Color::Olive << "Data Initialization has started!");
            Sleep(Seconds(10));
        }
        #endif

        MH4U::GamePointers::PlayerPointer.SetPointer(0x81C780C);

        MH4U::GamePointers::MonstersArrayPointer.SetPointer(0x8353610);
        MH4U::GamePointers::FirstMonsterPointer.SetPointer((0x8353610 + 0x18));
        MH4U::GamePointers::LastMonsterPointer.SetPointer(((0x8353610 + 0x18) + 0x7C));

        #ifdef SHOW_DEBUG
        if (!hasBeenInitializedOnce) OSD::Notify(Color::LimeGreen << "CTRPluginFramework::MH4U::GamePointers" << Color::Cyan << " has been Initialized!");
        #endif

        MH4U::GameAddresses::Money.SetAddress(0x8369880);
        MH4U::GameAddresses::CaravanPoints.SetAddress(0x83780EC);

        #ifdef SHOW_DEBUG
        if (!hasBeenInitializedOnce) OSD::Notify(Color::LimeGreen << "CTRPluginFramework::MH4U::GameAddresses" << Color::Cyan << " has been Initialized!");
        #endif

        #ifdef SHOW_DEBUG
        if (!hasBeenInitializedOnce)
        {
            OSD::Notify(Color::Lime << "Data Initialization Done!");
            OSD::Notify(Color::Cyan << "Plugin Ready!");
        }
        #endif

        hasBeenInitializedOnce = true;
    }
    
    namespace MH4U
    {
        namespace GamePointers
        {
            MemoryPointer PlayerPointer;
            
            MemoryPointer MonstersArrayPointer;
            MemoryPointer FirstMonsterPointer;
            MemoryPointer LastMonsterPointer;
        }

        namespace GameAddresses
        {
            MemoryAddress Money;
            MemoryAddress CaravanPoints;
        }

    }
}