#pragma once

namespace AfUI {


    // todo move to other file
    
    namespace views {                                  // ����������� ��������, ������������� ������������ � render_tree

        struct block_view : public object_header {  // ������� ������� ��� ������������

            virtual void registration(  ) {}  // ����������� �������
            
        };

    }

    namespace controls {        // ����������� ��������, ������������� ������������ � event_tree

        struct block_control : public object_header {  // ������� ������� ��� ������������

            virtual void registration() {}  // ����������� �������

            
        };

    }

    namespace blocks {  // ������� �������� ��������� �� ����������

        struct block : public object_header {  // ������� ������� ��� ������������, ��� �� �������� ������ ��� ���������� layout-��
        private:
            var_list                             vars;      // ������ ����������
            list_header<views::block_view>       views;     // ������ ��������� ��� ���������
            list_header<controls::block_control> controls;  // ������ ��������� ��� ��������� �������

        public:
            var_list&                             get_varlist() { return vars; }
            list_header<views::block_view>&       get_views() { return views; }
            list_header<controls::block_control>& get_controls() { return controls; }
            virtual void                          build() {}  // ��������� ���������� �������� � �������

        public: 
            //// ����������� ������� � ������ ��� ����������� ���� (feature 0.7)
            //virtual void memorymove( void* to_memory ) { assert( false && "not_support" ); }  
            //// 1. ���� ������� � ���� ������ ����� ���� ����� cpp_placement_new
            //// 2. ����������� ���������� � ���������� �������
            //// 3. ���������� ������� ����� memorymove ���� ����������
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
