#pragma once

namespace AfUI {

    struct color {
        f32 r, g, b, a;

        bool operator==( const color& rhs ) { return ( r == rhs.r ) && ( g == rhs.g ) && ( b == rhs.b ) && ( a == rhs.a ); }
        bool operator!=( const color& rhs ) { return ( r != rhs.r ) || ( g != rhs.g ) || ( b != rhs.b ) || ( a != rhs.a ); }
    };

    struct ivec2 {
        i32 x, y;

        ivec2() : x( 0 ), y( 0 ) {}
        ivec2( i32 x_, i32 y_ ) : x( x_ ), y( y_ ) {}
        ivec2 operator*( const i32 rhs ) { return ivec2( x * rhs, y * rhs ); }
        ivec2 operator/( const i32 rhs ) { return ivec2( x / rhs, y / rhs ); }
        ivec2 operator+( const ivec2& rhs ) { return ivec2( x + rhs.x, y + rhs.y ); }
        ivec2 operator-( const ivec2& rhs ) { return ivec2( x - rhs.x, y - rhs.y ); }
        ivec2 operator*( const ivec2& rhs ) { return ivec2( x * rhs.x, y * rhs.y ); }
        ivec2 operator/( const ivec2& rhs ) { return ivec2( x / rhs.x, y / rhs.y ); }
        bool  operator==( const ivec2& rhs ) { return ( x == rhs.x ) && ( y == rhs.y ); }
        bool  operator!=( const ivec2& rhs ) { return ( x != rhs.x ) || ( y != rhs.y ); }
    };

    struct fvec2 {
        f32 x, y;

        fvec2() : x( 0.0f ), y( 0.0f ) {}
        fvec2( f32 x_, f32 y_ ) : x( x_ ), y( y_ ) {}
        fvec2 operator*( const f32 rhs ) { return fvec2( x * rhs, y * rhs ); }
        fvec2 operator/( const f32 rhs ) { return fvec2( x / rhs, y / rhs ); }
        fvec2 operator+( const fvec2& rhs ) { return fvec2( x + rhs.x, y + rhs.y ); }
        fvec2 operator-( const fvec2& rhs ) { return fvec2( x - rhs.x, y - rhs.y ); }
        fvec2 operator*( const fvec2& rhs ) { return fvec2( x * rhs.x, y * rhs.y ); }
        fvec2 operator/( const fvec2& rhs ) { return fvec2( x / rhs.x, y / rhs.y ); }
        bool  operator==( const fvec2& rhs ) { return ( x == rhs.x ) && ( y == rhs.y ); }
        bool  operator!=( const fvec2& rhs ) { return ( x != rhs.x ) || ( y != rhs.y ); }
    };

    struct ivec4 {
        i32 x, y, z, w;

        ivec4() : x( 0 ), y( 0 ), z( 0 ), w( 0 ) {}
        ivec4( i32 x_, i32 y_, i32 z_, i32 w_ ) : x( x_ ), y( y_ ), z( z_ ), w( w_ ) {}
        ivec4 operator+( const ivec4& rhs ) { return ivec4( x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w ); }
        ivec4 operator-( const ivec4& rhs ) { return ivec4( x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w ); }
        ivec4 operator*( const ivec4& rhs ) { return ivec4( x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w ); }
        ivec4 operator*( const i32& rhs ) { return ivec4( x * rhs, y * rhs, z * rhs, w * rhs ); }
        bool  operator==( const ivec4& rhs ) { return ( x == rhs.x ) && ( y == rhs.y ) && ( z == rhs.z ) && ( w == rhs.w ); }
        bool  operator!=( const ivec4& rhs ) { return ( x != rhs.x ) || ( y != rhs.y ) || ( z != rhs.z ) || ( w != rhs.w ); }
    };

    struct fvec4 {
        f32 x, y, z, w;

        fvec4() : x( 0.0f ), y( 0.0f ), z( 0.0f ), w( 0.0f ) {}
        fvec4( f32 x_, f32 y_, f32 z_, f32 w_ ) : x( x_ ), y( y_ ), z( z_ ), w( w_ ) {}
        fvec4( const color& color_ ) : x( color_.r ), y( color_.g ), z( color_.b ), w( color_.a ) {}
        inline operator color() { return { x, y, z, w }; }
        fvec4  operator+( const fvec4& rhs ) { return fvec4( x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w ); }
        fvec4  operator-( const fvec4& rhs ) { return fvec4( x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w ); }
        fvec4  operator*( const fvec4& rhs ) { return fvec4( x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w ); }
        fvec4  operator*( const f32& rhs ) { return fvec4( x * rhs, y * rhs, z * rhs, w * rhs ); }
        bool   operator==( const fvec4& rhs ) { return ( x == rhs.x ) && ( y == rhs.y ) && ( z == rhs.z ) && ( w == rhs.w ); }
        bool   operator!=( const fvec4& rhs ) { return ( x != rhs.x ) || ( y != rhs.y ) || ( z != rhs.z ) || ( w != rhs.w ); }
    };

    struct irect {
        ivec2 min, max;

        irect() : min( 0, 0 ), max( 0, 0 ) {}
        irect( i32 x1_, i32 y1_, i32 x2_, i32 y2_ ) : min( x1_, y1_ ), max( x2_, y2_ ) {}
        irect( const ivec2& min_, const ivec2& max_ ) : min( min_ ), max( max_ ) {}
        irect( const ivec4& v ) : min( v.x, v.y ), max( v.z, v.w ) {}
        bool  operator==( const irect& rhs ) { return ( min == rhs.min ) && ( max == rhs.max ); }
        bool  operator!=( const irect& rhs ) { return ( min != rhs.min ) || ( max != rhs.max ); }
        ivec2 center() const { return ivec2( ( min.x + max.x ) / 2, ( min.y + max.y ) / 2 ); }
        ivec2 size() const { return ivec2( max.x - min.x, max.y - min.y ); }
        i32   width() const { return max.x - min.x; }
        i32   height() const { return max.y - min.y; }
        i32   area() const { return ( max.x - min.x ) * ( max.y - min.y ); }
        bool  contains( const ivec2& p ) const { return p.x >= min.x && p.y >= min.y && p.x < max.x && p.y < max.y; }
        bool  contains( const irect& r ) const { return r.min.x >= min.x && r.min.y >= min.y && r.max.x <= max.x && r.max.y <= max.y; }
        bool  overlaps( const irect& r ) const { return r.min.y < max.y && r.max.y > min.y && r.min.x < max.x && r.max.x > min.x; }
        void  expand( const ivec2& p ) {
            if ( min.x > p.x ) min.x = p.x;
            if ( min.y > p.y ) min.y = p.y;
            if ( max.x < p.x ) max.x = p.x;
            if ( max.y < p.y ) max.y = p.y;
        }
        void expand( const irect& r ) {
            if ( min.x > r.min.x ) min.x = r.min.x;
            if ( min.y > r.min.y ) min.y = r.min.y;
            if ( max.x < r.max.x ) max.x = r.max.x;
            if ( max.y < r.max.y ) max.y = r.max.y;
        }
        void move( const ivec2& d ) {
            min.x += d.x;
            min.y += d.y;
            max.x += d.x;
            max.y += d.y;
        }
        void move_x( i32 dx ) {
            min.x += dx;
            max.x += dx;
        }
        void move_y( i32 dy ) {
            min.y += dy;
            max.y += dy;
        }
        bool  is_invert() const { return min.x > max.x || min.y > max.y; }
        ivec4 to_ivec4() const { return ivec4( min.x, min.y, max.x, max.y ); }
    };

    struct frect {
        fvec2 min, max;

        frect() : min( 0, 0 ), max( 0, 0 ) {}
        frect( f32 x1_, f32 y1_, f32 x2_, f32 y2_ ) : min( x1_, y1_ ), max( x2_, y2_ ) {}
        frect( const fvec2& min_, const fvec2& max_ ) : min( min_ ), max( max_ ) {}
        frect( const fvec4& v ) : min( v.x, v.y ), max( v.z, v.w ) {}
        bool operator==( const frect& rhs ) { return ( min == rhs.min ) && ( max == rhs.max ); }
        bool operator!=( const frect& rhs ) { return ( min != rhs.min ) || ( max != rhs.max ); }
        fvec2 center() const { return fvec2( ( min.x + max.x ) / 2, ( min.y + max.y ) / 2 ); }
        fvec2 size() const { return fvec2( max.x - min.x, max.y - min.y ); }
        f32   width() const { return max.x - min.x; }
        f32   height() const { return max.y - min.y; }
        f32   area() const { return ( max.x - min.x ) * ( max.y - min.y ); }
        bool  contains( const fvec2& p ) const { return p.x >= min.x && p.y >= min.y && p.x < max.x && p.y < max.y; }
        bool  contains( const irect& r ) const { return r.min.x >= min.x && r.min.y >= min.y && r.max.x <= max.x && r.max.y <= max.y; }
        bool  overlaps( const irect& r ) const { return r.min.y < max.y && r.max.y > min.y && r.min.x < max.x && r.max.x > min.x; }
        void  expand( const fvec2& p ) {
            if ( min.x > p.x ) min.x = p.x;
            if ( min.y > p.y ) min.y = p.y;
            if ( max.x < p.x ) max.x = p.x;
            if ( max.y < p.y ) max.y = p.y;
        }
        void expand( const frect& r ) {
            if ( min.x > r.min.x ) min.x = r.min.x;
            if ( min.y > r.min.y ) min.y = r.min.y;
            if ( max.x < r.max.x ) max.x = r.max.x;
            if ( max.y < r.max.y ) max.y = r.max.y;
        }
        void move( const fvec2& d ) {
            min.x += d.x;
            min.y += d.y;
            max.x += d.x;
            max.y += d.y;
        }
        void move_x( f32 dx ) {
            min.x += dx;
            max.x += dx;
        }
        void move_y( f32 dy ) {
            min.y += dy;
            max.y += dy;
        }
        bool  is_invert() const { return min.x > max.x || min.y > max.y; }
        fvec4 to_fvec4() const { return fvec4( min.x, min.y, max.x, max.y ); }
    };

}  // namespace AfUI
