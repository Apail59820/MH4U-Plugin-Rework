#ifndef HELPER_HPP
#define HELPER_HPP

#include "stdafx.hpp"

namespace CTRPluginFramework
{
	static Keyboard *KB = new Keyboard("\n\n\n\n\nText"),
					*OptionsKB = new Keyboard("\n\n\n\n\nText");

    class Helper
    {
    public:

        static bool SetKeyboard(const String &Message, bool Hexadecimal, const int Length, u32 &Output, u32 Start, OnInputChange CallBack = nullptr);
        
        static bool SetKeyboard(const String &Message, bool Hexadecimal, const int Length, u16 &Output, u16 Start, OnInputChange CallBack = nullptr);
        
        static bool SetKeyboard(const String &Message, bool Hexadecimal, const int Length, u8 &Output, u8 Start, OnInputChange CallBack = nullptr);
        
        static bool SetKeyboard(const String &Message, bool Hexadecimal, const int Length, float &Output, float Start, OnInputChange CallBack = nullptr);
        
        static bool SetKeyboard(const String &Message, bool Hexadecimal, const int Length, String &Output, String Start, OnInputChange CallBack = nullptr);

        static void Toggle(u32 Offset, u32 Enable, u32 Disable, const String &Notification);
 
        static void ToggleTable(u32 Offset[], u32 Enable[], u32 Disable[], u8 Length, const String &Notification);

        static void WriteTable(u32 Offset[], u8 Value[], u8 Length);

        static void WriteTable(u32 Offset[], u16 Value[], u8 Length);

        static void WriteTable(u32 Offset[], u32 Value[], u8 Length);

        static void WriteTable(u32 Offset[], float Value[], u8 Length);
    };
}

#endif