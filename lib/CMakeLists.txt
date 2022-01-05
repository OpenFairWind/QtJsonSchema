set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS
        Core
        )

add_library(qtjsonschema SHARED
        include/QtJsonSchema
        src/jsonschemavalidationerror.cpp
        include/QtJsonSchema/jsonschemavalidationerror.h
        include/QtJsonSchema/metaschema/draft04.h
        include/QtJsonSchema/metaschema/draft06.h
        include/QtJsonSchema/metaschema/draft07.h
        src/jsonpointer.cpp
        include/QtJsonSchema/jsonpointer.h
        src/referenceresolver.cpp
        include/QtJsonSchema/referenceresolver.h
        src/jsonschemanodevalidator.cpp
        include/QtJsonSchema/jsonschemanodevalidator.h
        src/jsonschemanodevalidator07.cpp
        include/QtJsonSchema/jsonschemanodevalidator07.h
        include/QtJsonSchema/global.h
        src/hashfunctions.cpp
        include/QtJsonSchema/hashfunctions.h
        src/jsonschema.cpp
        include/QtJsonSchema/jsonschema.h
        include/QtJsonSchema/jsonschema_p.h
        src/utils.cpp
        include/QtJsonSchema/utils.h
        )

target_include_directories(qtjsonschema
        PUBLIC
        include
        PRIVATE
        include/QtJsonSchema
        )

target_compile_definitions(qtjsonschema
        PRIVATE
        QJSONSCHEMA_COMPILE_LIBRARY
        )

target_link_libraries(qtjsonschema
        PRIVATE
        Qt5::Core
        )

add_library(QtJsonSchema ALIAS qtjsonschema)

install(TARGETS qtjsonschema LIBRARY
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
        )

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION include
        FILES_MATCHING PATTERN "*.h*"
        )
