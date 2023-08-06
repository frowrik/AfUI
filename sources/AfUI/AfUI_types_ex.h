#pragma once

namespace AfUI {

    // tree
    template<typename T>
    struct tree_header {
        T* root = nullptr;
    };

    template<typename T>
    struct tree_item_header {
        T* parent      = nullptr;
        T* next        = nullptr;
        T* prev        = nullptr;
        T* child_first = nullptr;
        T* child_last  = nullptr;
    };

    // list
    template<typename T>
    struct list_header {
        T* first = nullptr;
        T* last  = nullptr;
    };

    template<typename T>
    struct list_item_header {
        T* next = nullptr;
        T* prev = nullptr;
    };

    // object
    struct object_header {
        usize type         = 0;  // уникальный тип блока
        usize id           = 0;  // уникальный id блока
        usize memory_size  = 0;  // размер в памяти
        usize memory_align = 0;  // требуемое выравнивание
    };

}
