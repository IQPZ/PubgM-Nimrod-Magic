#pragma once
#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#include <iostream>
#include <string>
#include <vector>

enum Ws_ExTashkeel_
{
    fat_FATHEH,
    fat_TANVIN_NASB,
    fat_ZAMMEH,
    fat_TANVIN_RAF,
    fat_KASREH,
    fat_TANVIN_JARR,
    fat_SOKOON,
    fat_TASHDID,
    fat_Tashkeel_Count
};

enum Ws_ExTashkeel_Names_
{
    fat_FATHA = fat_FATHEH,
    fat_FATHA_TAN = fat_TANVIN_NASB,
    fat_DAMMA = fat_ZAMMEH,
    fat_DAMMA_TAN = fat_TANVIN_RAF,
    fat_KASRA = fat_KASREH,
    fat_KASRA_TAN = fat_TANVIN_JARR,
    fat_SUKUN = fat_SOKOON,
    fat_SHADDA = fat_TASHDID
};

enum Ws_ExAlphabets_
{
    faa_ALEF_HAMZEH_ABOVE, // أ
    faa_ALEF, // ا
    faa_ALEF_MAD_ABOVE, // آ
    faa_HAMZEH, // ء
    faa_VAAV_HAMZEH_ABOVE, // ؤ
    faa_ALEF_HAMZEH_BELOW, // إ
    faa_YEH_HAMZEH_ABOVE, // ئ
    faa_BEH, // ب
    faa_PEH, // پ
    faa_TEH, // ت
    faa_TEH_TANIS, // ة
    faa_SEH, // ث
    faa_JEEM, // ج
    faa_CHEH, // چ
    faa_HEH_JEEMY, // ح
    faa_KHEH, // خ
    faa_DAAL, // د
    faa_ZAAL, // ذ
    faa_REH, // ر
    faa_ZEH, // ز
    faa_JEH, // ژ
    faa_SEEN, // س
    faa_SHEEN, // ش
    faa_SAAD, // ص
    faa_ZAAD, // ض
    faa_TAAH, // ط
    faa_ZAAH, // ظ
    faa_AIN, // ع
    faa_GHAIN, // غ
    faa_FEH, // ف
    faa_QAAF, // ق
    faa_KAAF, // ک
    faa_KAAF_NO_HEAD, // ك
    faa_GAAF, // گ
    faa_LAAM, // ل
    faa_MEEM, // م
    faa_NOON, // ن
    faa_VAAV, // و
    faa_HEH, // ه
    faa_YEH, // ی
    faa_Ws_Ws, // ي
    faa_ALEF_MAKSURA, // ى
    faa_TATWEEL, // ـ
    faa_LAAM_ALEF, // لا
    faa_LAAM_ALEF_HAMZA_ABOVE, // لأ
};

enum Ws_ExAlphabets_Forms_
{
    faa_Unicode,
    faa_Isolated,
    faa_Beginner,
    faa_Medium,
    faa_Final,
};

extern const std::vector<std::vector<std::wstring>> fa_AlphabetsAllForms;

namespace Ws_ExType
{
    unsigned char GetFACharPlace(const std::wstring& fa_character, const std::wstring& prevFAChar, const std::wstring& nextFAChar);
    bool IsFACharBeginner(const std::wstring& fa_character);
    unsigned char FindFACharIndex(const std::wstring& fa_character);
    bool IsFAChar(const std::wstring& fa_character);
    bool Check4F(const std::wstring& fa_character);
    std::vector<std::wstring> GetFAChars(const std::wstring& str);
    std::string wstring_to_utf8(const std::wstring& str);
    std::wstring utf8_to_wstring(const std::string& str);
    std::vector<std::wstring> ReverseFAText(const std::wstring& str);
    std::wstring GetFACharGlyph(const std::wstring& fa_character, const std::wstring& prevFAChar, const std::wstring& nextFAChar);
    std::string ConvertToFAGlyphs(const std::wstring& text);
};
