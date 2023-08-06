#pragma once

namespace AfUI {
    //..

    struct platformapi {
    public:
        virtual void  log( const char* str, size_t len )      = 0;

    public:
        virtual void  thread_sleep( i32 deltams )             = 0;

    public:
        virtual void* memory_alloc( usize size, usize align ) = 0;
        virtual void  memory_free( void* ptr )                = 0;

    public:
        // version 0.1
        // virtual void render_create()                                                                                        = 0;
        // virtual void render_destroy()                                                                                       = 0;
        // virtual void render_edgeantialias( bool enable )                                                                    = 0;
        // virtual i32  render_texture_create( u32 type, u32 width, u32 height, u32 flags, const unsigned char* data )         = 0;
        // virtual void render_texture_destroy( i32 imghandle )                                                                = 0;
        // virtual void render_texture_update( i32 imghandle, i32 x, i32 y, u32 width, u32 height, const unsigned char* data ) = 0;
        // virtual void render_texture_getinfo( i32 imghandle, u32* type, u32* width, u32* height, u32* flags )                = 0;
        // virtual void render_viewport_set( f32 width, f32 height, f32 pixelratio )                                           = 0;  // установить виев порт для рисования
        // virtual void render_cmd_clear()                                                                                     = 0;
        // virtual void render_cmd_execute()                                                                                   = 0;
        // render_cmd_***
        // render_***
        
    public:     
        // version 0.7 оптимизация рендеринга
        // virtual i32  render_composite_alloc( float width, float height, float pixelratio ) = 0;  
        // virtual void render_composite_destroy( i32 rthandle )                              = 0;
        // virtual void render_composite_clear( i32 rthandle )                                = 0;
        // virtual void render_composite_begin( i32 rthandle )                                = 0;
        // virtual void render_composite_end( i32 rthandle )                                  = 0;
        // virtual void render_composite_draw( i32 rthandle )                                 = 0;
    };

}
