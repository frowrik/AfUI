#pragma once
#include "cpp_macros.h"
#include "cpp_includes.h"
#include "cpp_placement_new.h"
#include "cpp_types.h"
#include "cpp_tools.h"

#include "AfUI_types.h"
#include "AfUI_platform.h"  	// базовая обертка которую имплементирует пользователь
#include "AfUI_styles.h"  		// стили для лайаут системы
#include "AfUI_node.h"			// элемент для dom 
#include "AfUI_dom.h"			// структура документа
#include "AfUI_xml.h"			// загруска-сохранение ui документа
#include "AfUI_events.h"		// система эвентов
#include "AfUI_eventtree.h"		// по аналогии с деревьями отрисовки но для обработки инпутов, не все что рисуется требует обработки эвентов
#include "AfUI_rendertree.h"	// деревья отрисовки 
#include "AfUI_imagesystem.h"	// отдельная система для растеризации изображений использует platform
#include "AfUI_fontsystem.h"	// отдельная система для растеризации шрифтов использует platform
#include "AfUI_render.h"		// основной рендер использует platform
#include "AfUI_layout.h"		// лайоут система для определения что и где рисовать
#include "AfUI_context.h"		// обьединение всех элементов в единый контекст
#include "AfUI_elements.h"		// базовые элементы используеться регестрация в контексте
