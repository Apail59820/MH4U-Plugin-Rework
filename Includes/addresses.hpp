#ifndef ADDRESSES_HPP
#define ADDRESSES_HPP

#include "stdafx.hpp"

namespace CTRPluginFramework
{
    class MemoryAddress
    {
    public:
        MemoryAddress();

        MemoryAddress(u32 Address);

        void SetAddress(u32 Address);

        template<typename T> void SetValue(T Value);

        u32 GetAddress(void) const;

        template<typename T> T GetValue(void) const;

    private:
        u32 m_Address;
    };

    class MemoryPointer
    {
    public:
        MemoryPointer();

        MemoryPointer(u32 PointerAddress);

        void SetPointer(u32 PointerAddress);

        u32 GetPointerAddress(void) const;

        u32 GetPointedAddress(void) const;

        template<typename T> T GetPointedAddressValue(void) const;

        template<typename T> void AddToPointerAddress(T Offset);

    private:
        u32 m_PointerAddress;
        u32 m_PointedAddress;
    };

    void InitializePluginData_Callback(void);

    namespace MH4U
    {
        namespace GamePointers
        {
            extern MemoryPointer PlayerPointer;

            extern MemoryPointer MonstersArrayPointer;
            extern MemoryPointer FirstMonsterPointer;
            extern MemoryPointer LastMonsterPointer;
        }

        namespace GameAddresses
        {
            extern MemoryAddress Money;
            extern MemoryAddress CaravanPoints;
        }
    }
}

#endif