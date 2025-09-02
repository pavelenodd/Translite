cmake_minimum_required(VERSION 4.0)
set(PROJECT_NAME MinimalQmlApp)  

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON) # Включаем автогенерацию moc файлов
set(CMAKE_AUTORCC ON) # Включаем автогенерацию rcc опционально
set(CMAKE_AUTOUIC ON) # Включаем автогенерацию uic опционально 

find_package(Qt6 REQUIRED COMPONENTS Quick Qml)  
qt_policy(SET QTP0001 NEW) # убираем нудный warning

# Экзешник с другим именем, чтобы не конфликтовать с каталогом MinimalQml
qt_add_executable(${PROJECT_NAME}
	Src/main.cpp
)

qt_add_qml_module(${PROJECT_NAME}
	URI MinimalQml # URI модуля должен не совпадать с именем проекта
	QML_FILES # QML файлы модуля
	Main.qml
)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Quick Qt6::Qml)