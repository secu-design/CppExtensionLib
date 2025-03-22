set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")

   # Compiler flags
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Werror=unused-result -fPIC")
   # Compiler flags - DEBUG
   set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
   # Compiler flags - RELEASE
   set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")

   # Compiler flags
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /permissive- /ifcOutput /W3 /GS /Zc:wchar_t /Gm- /sdl /Zc:inline /fp:precise /D \"_UNICODE\" /D \"UNICODE\" /errorReport:prompt /WX- /Zc:forScope /Gd /FC /EHsc /nologo /diagnostics:column")
   # Compiler flags - DEBUG
   set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /D \"DEBUG\" /JMC /ZI /Od /RTC1 /MDd")
   # Compiler flags - RELEASE
   set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /D \"NDEBUG\" /GL /Zi /MD /O2")

   # Linker flags - STATIC LIBS
   set(CMAKE_STATIC_LINKER_FLAGS "${CMAKE_STATIC_LINKER_FLAGS} /D \"_LIB\"")
   # Linker flags - SHARED LIBS
   set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /D \"DLL1_EXPORTS\" /D \"_WINDOWS\" /D \"_USRDLL\" /D \"_WINDLL\"")

endif ()
