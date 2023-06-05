#pragma once

namespace CSX
{
	namespace Cvar
	{
//[swap_lines]
		void	InitPath( const char* szPath );

		int		LoadCvar( char* szSection , char* szKey , int DefaultValue );
		std::string	LoadCvar( char* szSection , char* szKey , std::string DefaultValue );
		float	LoadCvar( char* szSection , char* szKey , float DefaultValue );

		void	SaveCvar( char* szSection , char* szKey , int Value );
		void	SaveCvar( char* szSection , char* szKey , float Value );
		void	SaveCvar( char* szSection , char* szKey , std::string Value );
//[/swap_lines]
	}
}