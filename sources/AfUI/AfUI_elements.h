#pragma once

// version 0.01

namespace AfUI {

    namespace views {           // примитивные элементы, автоматически добавляються в render_tree
        struct block_view {     // базовые элемент для наследования

        };
    }

    namespace controls {        // примитивные элементы, автоматически добавляються в event_tree
        struct block_control {  // базовые элемент для наследования

        };
    }

    namespace blocks {           // готовые элементы собранные из примитивов
        struct block {          // базовые элемент для наследования, так же содержит данные для вычисления layout-ов

        };
    }

}

// version 0.1
#include "elements/view_rect.h"
#include "elements/view_circle.h"
#include "elements/view_text.h"
#include "elements/view_image.h"
#include "elements/control_button.h"
#include "elements/block_rect_color.h"
#include "elements/block_circle_color.h"
#include "elements/block_text.h"
#include "elements/block_image.h"
#include "elements/block_button.h"
#include "elements/block_imagebutton.h"
#include "elements/block_checkbox.h"
#include "elements/block_radio.h"

// version 0.2
#include "elements/view_slider.h"
#include "elements/control_textedit.h"
#include "elements/control_slider.h"
#include "elements/block_textedit.h"
#include "elements/block_progressbar.h"
#include "elements/block_slider.h"

// version 0.3
#include "elements/view_scroll.h"
#include "elements/control_scroll.h"
#include "elements/block_scroll.h"

// version 0.4
#include "elements/block_item.h"
#include "elements/block_listbox.h"
#include "elements/block_combo.h"
#include "elements/block_treebox.h"
#include "elements/block_tablebox.h"

// version 0.5
#include "elements/block_popuplist.h"
#include "elements/block_menubar.h"

// version 0.6
#include "elements/view_multitext.h"
#include "elements/control_multitextedit.h"
#include "elements/block_multitext.h"
#include "elements/block_multitextedit.h"
