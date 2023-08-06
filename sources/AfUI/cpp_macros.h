#pragma once

#define ALIGN_SIZE( Size, AlSize ) ( ( Size + ( AlSize - 1 ) ) & ( ~( AlSize - 1 ) ) )
#define STRING_MAKE_( x )          #x
#define STRING_MAKE( x )           STRING_MAKE_( x )
#define STRING_CONCAT_( a, b )     a##b
#define STRING_CONCAT( a, b )      MACRO_CONCAT_( a, b )
#define BIT( Num )                 ( 1 << Num )
