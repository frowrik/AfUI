#pragma once

#ifndef __PLACEMENT_NEW_INLINE
#define __PLACEMENT_NEW_INLINE

inline void* __cdecl operator new( size_t _Size, void* _Where ) noexcept {
    (void)_Size;
    return _Where;
}

inline void __cdecl operator delete( void*, void* ) noexcept {}

#endif

#ifndef __PLACEMENT_VEC_NEW_INLINE
#define __PLACEMENT_VEC_NEW_INLINE

inline void* __cdecl operator new[]( size_t _Size, void* _Where ) noexcept {
    (void)_Size;
    return _Where;
}

inline void __cdecl operator delete[]( void*, void* ) noexcept {}

#endif

#define CALL_CONSTRUCTOR( Memory, Type )            ( new ( Memory ) Type )
#define CALL_CONSTRUCTOR_ARR( Memory, Type, Count ) ( new ( Memory ) Type[Count] )
