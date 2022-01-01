set(CMAKE_CXX_STANDARD 11)

enable_testing()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 REQUIRED COMPONENTS
        Core
        Test
        )

set(QTJSONSCHEMA_TEST_RESOURCE testdata/testdata.qrc)
qt5_add_resources(QTJSONSCHEMA_TEST_RESOURCE_ADDED ${QTJSONSCHEMA_TEST_RESOURCE})

add_executable(qtjsonschema-test
        common.cpp
        common.h
        main.cpp
        schemavalidationtest.cpp
        schemavalidationtest.h
        ${QTJSONSCHEMA_TEST_RESOURCE_ADDED}
        )

target_link_libraries(qtjsonschema-test
        PRIVATE
        Qt5::Core
        Qt5::Test
        QtJsonSchema
        )