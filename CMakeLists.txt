cmake_minimum_required(VERSION 3.30)

project(hospital LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(${PROJECT_NAME}
    include/appointment.h
    include/surgery.h
    include/global.h
    include/list.h
    include/menu.h
    include/actions.h
    include/person.h
    src/appointment.cpp
    src/surgery.cpp
    src/global.cpp
    src/list.cpp
    src/menu.cpp
    src/appointmentActions.cpp
    src/surgeryActions.cpp
    src/personActions.cpp
    src/person.cpp
    src/nurse.cpp
    src/doctor.cpp
    src/fileIO.cpp
    src/inpatient.cpp
    src/outpatient.cpp
    src/main.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC include)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/DB.txt ${CMAKE_CURRENT_BINARY_DIR}/DB.txt COPYONLY)