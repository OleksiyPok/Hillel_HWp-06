cmake_minimum_required(VERSION 3.16)

project(TCalc VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

# Добавим ресурс иконки Windows
if(WIN32)
    set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/app_icon.rc")
endif()

qt_add_executable(appTCalc
    main.cpp
    ${APP_ICON_RESOURCE_WINDOWS}  # Иконка для .exe файла Windows
)

qt_add_qml_module(appTCalc
    URI TCalc
    VERSION 1.0
    QML_FILES
        Main.qml
    SOURCES
        tcalccontroller.h tcalccontroller.cpp
        tcalcmodel.h tcalcmodel.cpp
)

qt_add_resources(APP_RESOURCES resources.qrc)
target_sources(appTCalc PRIVATE ${APP_RESOURCES})

set_target_properties(appTCalc PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTCalc
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appTCalc
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
