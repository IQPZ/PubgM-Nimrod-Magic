#include "includes.h"

#define ENCRYPTION_KEY 0xA735
namespace CSX
{
	namespace Cvar
	{
		std::string IniFile = "";
		size_t IniFileLen = 0;

		void IniFileED()
		{
			for ( size_t i = 0; i < IniFileLen; i++ ) {
				IniFile[i] ^= ENCRYPTION_KEY;
			}
		}

		void InitPath( const char* szPath )
		{
			IniFile = szPath;
			IniFileLen = IniFile.size();
			IniFileED();
		}

		int LoadCvar( char* szSection , char* szKey , int DefaultValue )
		{
			IniFileED();
			char IntValue[16] = { 0 };
			GetPrivateProfileStringA( szSection , szKey , std::to_string( DefaultValue ).c_str() , IntValue , sizeof( IntValue ) , IniFile.c_str() );
			IniFileED();
			return atoi( IntValue );
		}

		std::string LoadCvar( char* szSection , char* szKey , std::string DefaultValue )
		{
			IniFileED();
			char cTempString[16] = { 0 };
			GetPrivateProfileStringA( szSection , szKey , DefaultValue.c_str() , cTempString , sizeof( cTempString ) , IniFile.c_str() );
			IniFileED();
			return std::string( cTempString );
		}

		float LoadCvar( char* szSection , char* szKey , float DefaultValue )
		{
			IniFileED();
			char FloatValue[16] = { 0 };
			GetPrivateProfileStringA( szSection , szKey , std::to_string( DefaultValue ).c_str() , FloatValue , sizeof( FloatValue ) , IniFile.c_str() );
			IniFileED();
			return (float)atof( FloatValue );
		}

		void SaveCvar( char* szSection , char* szKey , int Value )
		{
			std::string IntValue = std::to_string( Value );
			IniFileED();
			WritePrivateProfileStringA( szSection , szKey , IntValue.c_str() , IniFile.c_str() );
			IniFileED();
		}

		void SaveCvar( char* szSection , char* szKey , float Value )
		{
			std::string FloatValue = std::to_string( Value );
			IniFileED();
			WritePrivateProfileStringA( szSection , szKey , FloatValue.c_str() , IniFile.c_str() );
			IniFileED();
		}

		void SaveCvar( char* szSection , char* szKey , std::string Value )
		{
			IniFileED();
			WritePrivateProfileStringA( szSection , szKey , Value.c_str() , IniFile.c_str() );
			IniFileED();
		}
	}
}