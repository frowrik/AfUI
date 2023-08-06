#include "AfUI.h"

namespace AfUI {

    void var_list::add( var_header& var ) {
        var.prev = last;
        if ( last ) last->next = &var;
        last = &var;
        if ( !first ) first = last;
    }

    void var_list::remove( var_header& var ) {
        auto _next = var.next;
        auto _prev = var.prev;
        if ( _next ) _next->prev = _prev;
        if ( _prev ) _prev->next = _next;
        if ( &var == first ) first = _next;
        if ( &var == last ) last = _prev;
    }

    var_header* var_list::find( std::string name ) {
        for ( var_header* var = first; var != nullptr && var != last; var = var->next ) {
            if ( var->name == name ) return var;
        }
        return nullptr;
    }

    var_header* var_list::find( usize id ) {
        for ( var_header* var = first; var != nullptr && var != last; var = var->next ) {
            if ( var->id == id ) return var;
        }
        return nullptr;
    }

    var_header* var_list::begin() { return first; }

    var_header* var_list::end() { return last; }



    std::string_view var_header::get_name() { return name; }

}
