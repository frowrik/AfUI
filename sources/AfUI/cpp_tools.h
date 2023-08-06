#pragma once

namespace AfUI {
	
	inline std::string tools_to_string( double& val ) {  // microsoft std is problem
		const auto _Len = static_cast<size_t>( std::snprintf( nullptr, 0, "%.17g", val ) );
		assert( _Len >= 0 );
		if ( _Len < 0 ) return "";
		std::string _Str( _Len + 1, '\0' );
		std::snprintf( &_Str[0], _Len + 1, "%.17g", val );
		return _Str;
	}

	template<typename... Args>
	inline std::string string_format( const char* format, Args... args ) {
		const auto _Len = static_cast<size_t>( std::snprintf( nullptr, 0, format, args... ) ) + 1;
		assert( _Len >= 0 );
		if ( _Len < 0 ) return "";
		std::string _Str;
		_Str.resize( _Len );
		std::snprintf( _Str.data(), _Str.length(), format, args... );
		_Str.resize( _Len - 1 ); // remove 0
		return _Str;
	}

}
