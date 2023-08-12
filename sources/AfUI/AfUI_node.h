#pragma once

namespace AfUI {

    namespace views { 
        struct block_view;
    }
    namespace controls { 
        struct block_control;
    }
    namespace blocks {
        struct block;
    }




    namespace views { // примитивные элементы, автоматически добавл€ютьс€ в render_tree


        struct block_view : public object_header {  // базовые элемент дл€ наследовани€

            virtual void registration( blocks::block* parent ) {}  // регистраци€ эвентов
            virtual void draw( render* rapi, irect allowrect ) {}  // отрисовка элемента
        };

    }

    namespace controls {        // примитивные элементы, автоматически добавл€ютьс€ в event_tree

        
        struct event_header;

        struct event_list : private list_header<var_header> {
        public:
            void            add( event_header& ev_ ); 
            void            remove( event_header& ev_ ); 
            event_header*   begin();
            event_header*   end();
        };

        
        struct event_header : public object_header, private list_item_header<var_header> {  // базовые элемент дл€ хранени€ данных в блоке
            friend event_list;

        private:
            std::string name = "null";

        public:
            std::string_view get_name();

            event_header() = delete;
            event_header( std::string_view name_, event_list& eventslist ) {
                name = name_;
                eventslist.add( *this );
            }
        };

        struct var_remove {  // удаление блока
        public:
            var_remove() = delete;
            var_remove( event_header& ev_, event_list& eventslist ) { eventslist.remove( ev_ ); }
        };


        struct block_control : public object_header {  // базовые элемент дл€ наследовани€

            virtual void registration( blocks::block* parent ) {}  // регистраци€ эвентов

            
        };

    }

    namespace blocks {  // готовые элементы собранные из примитивов

        struct block : public object_header {  // базовые элемент дл€ наследовани€, так же содержит данные дл€ вычислени€ layout-ов
        private:
            var_list                             vars;      // список переменных
            list_header<views::block_view>       views;     // список элементов дл€ отрисовки
            list_header<controls::block_control> controls;  // список элементов дл€ обработки эвентов

        public:
            var_list&                             get_varlist() { return vars; }
            list_header<views::block_view>&       get_views() { return views; }
            list_header<controls::block_control>& get_controls() { return controls; }
            virtual void                          registration() {}  // регистраци€ внутренних обьектов и списков

        public: 
            //// перемещение обьекта в пам€ти дл€ оптимизации кэша (feature 0.7)
            //virtual void memorymove( void* to_memory ) { assert( false && "not_support" ); }  
            //// 1. надо создать в этой пам€ти новый блок через cpp_placement_new
            //// 2. скопировать переменные и внутренние обьекты
            //// 3. рекурсивно вызвать метод memorymove кого используем
        };

    }

    namespace blocks {
        struct example_block : block {
            var_string var_string{ "var_string", "defstring", get_varlist() };
            var_f32    var_f32{ "var_f32", get_varlist() };
            var_remove var_string_remove{ var_string, get_varlist() };
        };
    }
}
