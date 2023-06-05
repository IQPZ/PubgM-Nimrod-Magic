#include "Includes.h"

const std::vector<std::vector<std::wstring>> fa_AlphabetsAllForms = {
    {L"\u0623", L"\ufe83", L"\u0623", L"\ufe84", L"\ufe84"},
    {L"\u0627", L"\ufe8d", L"\u0627", L"\ufe8e", L"\ufe8e"},
    {L"\u0622", L"\ufe81", L"\u0622", L"\ufe82", L"\ufe82"},
    {L"\u0621", L"\ufe80", L"\u0621", L"\u0621", L"\u0621"},
    {L"\u0624", L"\ufe85", L"\u0624", L"\ufe86", L"\ufe86"},
    {L"\u0625", L"\ufe87", L"\u0625", L"\ufe88", L"\ufe88"},
    {L"\u0626", L"\ufe89", L"\ufe8b", L"\ufe8c", L"\ufe8a"},
    {L"\u0628", L"\ufe8f", L"\ufe91", L"\ufe92", L"\ufe90"},
    {L"\u067e", L"\ufb56", L"\ufb58", L"\ufb59", L"\ufb57"},
    {L"\u062A", L"\ufe95", L"\ufe97", L"\ufe98", L"\ufe96"},
    {L"\u0629", L"\ufe93", L"\u0629", L"\u0629", L"\ufe94"},
    {L"\u062b", L"\ufe99", L"\ufe9b", L"\ufe9c", L"\ufe9a"},
    {L"\u062c", L"\ufe9d", L"\ufe9f", L"\ufea0", L"\ufe9e"},
    {L"\u0686", L"\ufb7a", L"\ufb7c", L"\ufb7d", L"\ufb7b"},
    {L"\u062d", L"\ufea1", L"\ufea3", L"\ufea4", L"\ufea2"},
    {L"\u062e", L"\ufea5", L"\ufea7", L"\ufea8", L"\ufea6"},
    {L"\u062f", L"\ufea9", L"\u062f", L"\ufeaa", L"\ufeaa"},
    {L"\u0630", L"\ufeab", L"\u0630", L"\ufeac", L"\ufeac"},
    {L"\u0631", L"\ufead", L"\u0631", L"\ufeae", L"\ufeae"},
    {L"\u0632", L"\ufeaf", L"\u0632", L"\ufeb0", L"\ufeb0"},
    {L"\u0698", L"\ufb8a", L"\u0698", L"\ufb8b", L"\ufb8b"},
    {L"\u0633", L"\ufeb1", L"\ufeb3", L"\ufeb4", L"\ufeb2"},
    {L"\u0634", L"\ufeb5", L"\ufeb7", L"\ufeb8", L"\ufeb6"},
    {L"\u0635", L"\ufeb9", L"\ufebb", L"\ufebc", L"\ufeba"},
    {L"\u0636", L"\ufebd", L"\ufebf", L"\ufec0", L"\ufebe"},
    {L"\u0637", L"\ufec1", L"\ufec3", L"\ufec4", L"\ufec2"},
    {L"\u0638", L"\ufec5", L"\ufec7", L"\ufec8", L"\ufec6"},
    {L"\u0639", L"\ufec9", L"\ufecb", L"\ufecc", L"\ufeca"},
    {L"\u063a", L"\ufecd", L"\ufecf", L"\ufed0", L"\ufece"},
    {L"\u0641", L"\ufed1", L"\ufed3", L"\ufed4", L"\ufed2"},
    {L"\u0642", L"\ufed5", L"\ufed7", L"\ufed8", L"\ufed6"},
    {L"\u06a9", L"\ufed9", L"\ufedb", L"\ufedc", L"\ufeda"},
    {L"\u0643", L"\ufed9", L"\ufedb", L"\ufedc", L"\ufeda"},
    {L"\u06af", L"\ufb92", L"\ufb94", L"\ufb95", L"\ufb93"},
    {L"\u0644", L"\ufedd", L"\ufedf", L"\ufee0", L"\ufede"},
    {L"\u0645", L"\ufee1", L"\ufee3", L"\ufee4", L"\ufee2"},
    {L"\u0646", L"\ufee5", L"\ufee7", L"\ufee8", L"\ufee6"},
    {L"\u0647", L"\ufee9", L"\ufeeb", L"\ufeec", L"\ufeea"},
    {L"\u0648", L"\ufeed", L"\ufeed", L"\ufeee", L"\ufeee"},
    {L"\u06cc", L"\ufbfc", L"\ufbfe", L"\ufbff", L"\ufbfd"},
    {L"\u064a", L"\ufef1", L"\ufef3", L"\ufef4", L"\ufef2"},
    {L"\u0649", L"\ufeef", L"\u0649", L"\ufef0", L"\ufef0"},
    {L"\u0640", L"\u0640", L"\u0640", L"\u0640", L"\u0640"},
    {L"\ufefb", L"\ufefb", L"\ufefb", L"\ufefc", L"\ufefc"},
    {L"\ufef7", L"\ufef7", L"\ufef7", L"\ufef8", L"\ufef8"},
};

unsigned char Ws_ExType::GetFACharPlace(const std::wstring& fa_character, const std::wstring& prevFAChar, const std::wstring& nextFAChar)
{
    bool in_previous = false;
    bool in_next = false;
    for (auto const& fachar : fa_AlphabetsAllForms)
    {
        if (prevFAChar != L"None" || fachar[faa_Unicode] == prevFAChar)
            in_previous = true;
        if (nextFAChar != L"None" || fachar[faa_Unicode] == nextFAChar)
            in_next = true;
    }

    if (in_previous && in_next)
        return 3;
    if (in_next)
        return 2;
    if (in_previous)
        return 1;
    else
        return 0;
}

bool Ws_ExType::IsFACharBeginner(const std::wstring& fa_character)
{
    return
        fa_character == fa_AlphabetsAllForms[faa_ALEF_HAMZEH_ABOVE][faa_Unicode] ||
        fa_character == fa_AlphabetsAllForms[faa_ALEF_HAMZEH_ABOVE][faa_Unicode] ||
        fa_character == fa_AlphabetsAllForms[faa_ALEF_MAD_ABOVE][faa_Unicode] ||
        fa_character == fa_AlphabetsAllForms[faa_ALEF][faa_Unicode] ||
        fa_character == fa_AlphabetsAllForms[faa_HAMZEH][faa_Unicode] ||
        fa_character == fa_AlphabetsAllForms[faa_VAAV_HAMZEH_ABOVE][faa_Unicode] ||
        fa_character == fa_AlphabetsAllForms[faa_ALEF_HAMZEH_BELOW][faa_Unicode] ||
        fa_character == fa_AlphabetsAllForms[faa_DAAL][faa_Unicode] ||
        fa_character == fa_AlphabetsAllForms[faa_ZAAL][faa_Unicode] ||
        fa_character == fa_AlphabetsAllForms[faa_REH][faa_Unicode] ||
        fa_character == fa_AlphabetsAllForms[faa_ZEH][faa_Unicode] ||
        fa_character == fa_AlphabetsAllForms[faa_JEH][faa_Unicode] ||
        fa_character == fa_AlphabetsAllForms[faa_VAAV][faa_Unicode] ||
        fa_character == fa_AlphabetsAllForms[faa_ALEF_MAKSURA][faa_Unicode]
        ;
}

unsigned char Ws_ExType::FindFACharIndex(const std::wstring& fa_character)
{
    for (int i = 0; i < fa_AlphabetsAllForms.size(); ++i)
    {
        if (fa_character == fa_AlphabetsAllForms[i][faa_Unicode] ||
            fa_character == fa_AlphabetsAllForms[i][faa_Isolated] ||
            fa_character == fa_AlphabetsAllForms[i][faa_Beginner] ||
            fa_character == fa_AlphabetsAllForms[i][faa_Medium] ||
            fa_character == fa_AlphabetsAllForms[i][faa_Final])
            return i;
        else
            continue;
    }
    return fa_AlphabetsAllForms.size();
}

bool Ws_ExType::IsFAChar(const std::wstring& fa_character)
{
    for (auto const& fachar : fa_AlphabetsAllForms)
    {
        if (fa_character == fachar[faa_Unicode] ||
            fa_character == fachar[faa_Isolated] ||
            fa_character == fachar[faa_Beginner] ||
            fa_character == fachar[faa_Medium] ||
            fa_character == fachar[faa_Final])
            return true;
        else continue;
    }
    return false;
}
bool Ws_ExType::Check4F(const std::wstring& fa_character)
{
    std::vector<std::wstring> reversed_text = ReverseFAText(fa_character);
    for (int i = 0; i < reversed_text.size(); ++i)
    {
        if (IsFAChar(reversed_text[i]))
            return true;
    }
    return false;
}
std::vector<std::wstring> Ws_ExType::GetFAChars(const std::wstring& str)
{
    std::vector<std::wstring> reversed_text = ReverseFAText(str);
    std::vector<std::wstring> FChars;
    for (int i = 0; i < reversed_text.size(); ++i)
    {
        if (IsFAChar(reversed_text[i]))
        {
            FChars.push_back(reversed_text[i]);
        }
    }
    return FChars;
}
std::vector<std::wstring> Ws_ExType::ReverseFAText(const std::wstring& str)
{
    std::vector<std::wstring> reversedStr;

    for (int j = str.size() - 1; j > -1; j -= 2)
    {
        if ((str[j] & 0xFF) <= 0x7F)
        {
            std::wstring tempStr = std::wstring() + str[j];
            reversedStr.insert(tempStr._Equal(L" ") || IsFAChar(tempStr) ? reversedStr.end() : reversedStr.begin(), tempStr);
            j++;
            continue;
        }

        if ((str[j - 1] & 0xFF) <= 0x7F)
        {
            std::wstring tempStr = std::wstring() + str[j - 1];
            reversedStr.insert(tempStr._Equal(L" ") || IsFAChar(tempStr) ? reversedStr.end() : reversedStr.begin(), tempStr);
            j++;
            continue;
        }
        std::wstring tempStr = std::wstring() + str[j - 1] + str[j];
        reversedStr.insert(tempStr._Equal(L" ") || IsFAChar(tempStr) ? reversedStr.end() : reversedStr.begin(), tempStr);
    }
    return reversedStr;
}
std::wstring Ws_ExType::GetFACharGlyph(const std::wstring& fa_character, const std::wstring& prevFAChar, const std::wstring& nextFAChar)
{
    if (!IsFAChar(fa_character)) return fa_character;

    unsigned char facharPlace;
    unsigned char facharIndex;
    facharPlace = GetFACharPlace(fa_character, prevFAChar, nextFAChar);
    facharIndex = FindFACharIndex(fa_character);

    if (facharPlace == 3)
    {
        if (IsFACharBeginner(prevFAChar))
        {
            if (fa_AlphabetsAllForms[facharIndex][faa_Beginner] == fa_AlphabetsAllForms[faa_YEH][faa_Beginner])
            {
                return fa_AlphabetsAllForms[faa_Ws_Ws][faa_Beginner];
            }
            return fa_AlphabetsAllForms[facharIndex][faa_Beginner];
        }
        else
        {
            if (fa_AlphabetsAllForms[facharIndex][faa_Medium] == fa_AlphabetsAllForms[faa_YEH][faa_Medium])
            {
                return fa_AlphabetsAllForms[faa_Ws_Ws][faa_Medium];
            }
            return fa_AlphabetsAllForms[facharIndex][faa_Medium];
        }
    }
    else if (facharPlace == 2)
    {
        if (fa_AlphabetsAllForms[facharIndex][faa_Beginner] == fa_AlphabetsAllForms[faa_YEH][faa_Beginner])
        {
            return fa_AlphabetsAllForms[faa_Ws_Ws][faa_Beginner];
        }
        return fa_AlphabetsAllForms[facharIndex][faa_Beginner];
    }
    else if (facharPlace == 1)
    {
        if (IsFACharBeginner(prevFAChar))
        {
            if (fa_AlphabetsAllForms[facharIndex][faa_Isolated] == fa_AlphabetsAllForms[faa_YEH][faa_Isolated])
            {
                return fa_AlphabetsAllForms[faa_ALEF_MAKSURA][faa_Isolated];
            }
            return fa_AlphabetsAllForms[facharIndex][faa_Isolated];
        }
        else
        {
            if (fa_AlphabetsAllForms[facharIndex][faa_Final] == fa_AlphabetsAllForms[faa_YEH][faa_Final])
            {
                return fa_AlphabetsAllForms[faa_ALEF_MAKSURA][faa_Final];
            }
            return fa_AlphabetsAllForms[facharIndex][faa_Final];
        }
    }
    else
    {
        if (fa_AlphabetsAllForms[facharIndex][faa_Isolated] == fa_AlphabetsAllForms[faa_YEH][faa_Isolated])
        {
            return fa_AlphabetsAllForms[faa_ALEF_MAKSURA][faa_Isolated];
        }
        return fa_AlphabetsAllForms[facharIndex][faa_Isolated];
    }
}
std::string Ws_ExType::wstring_to_utf8(const std::wstring& str)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
    return myconv.to_bytes(str);
}
std::wstring Ws_ExType::utf8_to_wstring(const std::string& str)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
    return myconv.from_bytes(str);
}

std::string Ws_ExType::ConvertToFAGlyphs(const std::wstring& text)
{
    std::vector<std::wstring> reversed_text = ReverseFAText(text);
    std::string convertedText;
    std::wstring previous_fachar, next_fachar;

    bool fChar = false;
    for (int i = 0; i < reversed_text.size(); ++i)
    {
        if (IsFAChar(reversed_text[i]))
        {
            fChar = true;
            break;
        }
    }

    if (!fChar) return wstring_to_utf8(text);

    for (int i = 0; i < reversed_text.size(); ++i)
    {
        if (!IsFAChar(reversed_text[i]))
        {
            convertedText.append(Ws_ExType::wstring_to_utf8(reversed_text[i]));
            continue;
        }
        if ((i - 1) < 0)
            previous_fachar = L"None";
        else
        {
            if (IsFAChar(reversed_text[i - 1]))
                previous_fachar = reversed_text[i - 1];
            else
                previous_fachar = L"None";
        }

        if ((i + 1) <= (reversed_text.size() - 1))
        {
            if (IsFAChar(reversed_text[i + 1]))
                next_fachar = reversed_text[i + 1];
            else
                next_fachar = L"None";
        }
        else
            next_fachar = L"None";

        std::wstring fa_glyph = GetFACharGlyph(reversed_text[i], next_fachar, previous_fachar);
        convertedText.append(Ws_ExType::wstring_to_utf8(fa_glyph));
    }
    return convertedText;
}
