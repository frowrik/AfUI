#pragma once

namespace AfUI {

    enum class var_id : usize { unk = 0, data, string, bool32, u32, i32, u64, i64, f32, f64, ivec2, ivec4, irect, fvec2, fvec4, frect, fcolor };

    struct var_header;

    struct var_offset { // т.к. смещение остаёться одним и тем-же то можно хранить оффсет и налету его востанавливать
    private:
        usize offset_ptr = 0;

    public:
        void set( struct block* block_ptr, var_header* var_ptr ) { offset_ptr = (usize)var_ptr - (usize)block_ptr; }
        
        template<typename T>
        inline T* get(struct block* block_ptr) { return (T)(offset_ptr + (usize)block_ptr); }

        template<typename T>
        inline T& get(struct block* block_ptr) { return (T)(offset_ptr + (usize)block_ptr); }
    };

    struct var_list : private list_header<var_header> {
    public:
        void        add( var_header& var );     // добавить переменную
        void        remove( var_header& var );  // удалить переменную (она останица в памяти но перестанет быть доступной из поиска )
        var_header* find( std::string name );   // поиск переменной в списке
        var_header* find( usize id );           // поиск переменной в списке
        var_header* begin();
        var_header* end();
    };

    struct var_header : public object_header, private list_item_header<var_header> {  // базовые элемент для хранения данных в блоке
        friend var_list;

    private:
        std::string name = "null";

    public:
        std::string_view get_name();

        var_header() = delete;
        var_header( std::string_view name_, var_list& varslist ) {
            name = name_;
            varslist.add( *this );
        }
    };

    struct var_remove {  // удаление блока
    public:
        var_remove() = delete;
        var_remove( var_header& var_, var_list& varslist ) { varslist.remove( var_ ); }
    };
    


    //
    template<typename T, var_id idtype>
    struct var_simple : public var_header {
        T value = {};

        var_simple() = delete;
        var_simple( std::string_view name_, var_list& varslist ) : var_header( name_, varslist ) { type = (usize)idtype; }
        var_simple( std::string_view name_, const T& value_, var_list& varslist ) : var_header( name_, varslist ), value( value_ ) { type = (usize)idtype; }

        inline operator T() { return value; }  // get value

        inline T* operator->() { return &value; }  // get value
        inline T& operator&() { return value; }    // get value
        inline var_simple& operator=( const T& value_ ) {   // set value =
            this->value = value_;
            return *this;
        }

        //.. todo serialize deserialize
    };

    template<typename T, var_id idtype>
    struct var_simple_special : public var_simple<T, idtype> {
        var_simple_special() = delete;

        //.. todo serialize deserialize
    };

    
    //
    using var_string = var_simple<std::string, var_id::string>;
    using var_u32    = var_simple<u32, var_id::u32>;
    using var_i32    = var_simple<i32, var_id::i32>;
    using var_u64    = var_simple<u32, var_id::u64>;
    using var_f32    = var_simple<f32, var_id::f32>;
    using var_f64    = var_simple<f64, var_id::f64>;
    using var_bool   = var_simple<bool, var_id::bool32>;

    using var_ivec2 = var_simple_special<ivec2, var_id::ivec2>;
    using var_ivec4 = var_simple_special<ivec4, var_id::ivec4>;
    using var_irect = var_simple_special<irect, var_id::irect>;
    using var_fvec2 = var_simple_special<fvec2, var_id::fvec2>;
    using var_fvec4 = var_simple_special<fvec4, var_id::fvec4>;
    using var_frect = var_simple_special<frect, var_id::frect>;

    struct var_color : public var_header {
        color value = {};

        var_color() = delete;
        var_color( std::string_view name_, var_list& varslist ) : var_header( name_, varslist ) { type = (usize)var_id::fcolor; }
        var_color( std::string_view name_, const color& value_, var_list& varslist ) : var_header( name_, varslist ), value( value_ ) { type = (usize)var_id::fcolor; }
        var_color( std::string_view name_, const fvec4& value_, var_list& varslist ) : var_header( name_, varslist ) {
            type    = (usize)var_id::fcolor;
            value.r = value_.x;
            value.g = value_.y;
            value.b = value_.z;
            value.a = value_.w;
        }
        inline operator color() { return value; }  // get value
        inline operator fvec4() { return fvec4( value.r, value.g, value.b, value.a ); }  // get value
        inline var_color& operator=( const color& value_ ) {  // set value =
            this->value = value_;
            return *this;
        }
        inline var_color& operator=( const fvec4& value_ ) {  // set value =
            this->value.r = value_.x;
            this->value.g = value_.y;
            this->value.b = value_.z;
            this->value.a = value_.w;
            return *this;
        }

        //.. todo serialize deserialize
    };
    
}
