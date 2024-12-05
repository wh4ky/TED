# Options defined in root CMakeLists.txt

if(ENABLE_STATIC)
    # Output of the static lib
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out)

    # Static library
    add_library(TermEngine-Static STATIC
    input/mouse.cpp
    video/video.cpp
    video/color.cpp
    core/manager.cpp
    core/process_manager_class.cpp
    core/process_class.cpp
    core/log.cpp
    )
    
    # Static library properties
    set_target_properties(TermEngine-Static PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME}_${PROJECT_VERSION}
    )
endif()

if(ENABLE_DYNAMIC)
    # Dynamic library
    add_library(TermEngine-Dynamic SHARED
    input/mouse.cpp
    video/video.cpp
    video/color.cpp
    core/manager.cpp
    core/process_manager_class.cpp
    core/process_class.cpp
    core/log.cpp
    )

    # Dynamic library properties
    set_target_properties(TermEngine-Dynamic PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out
    OUTPUT_NAME ${PROJECT_NAME}_${PROJECT_VERSION}
    )
endif()
