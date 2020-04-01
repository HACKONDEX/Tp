add_library(buffer SHARED buffer.cpp)

install( 
    TARGETS buffer
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib 
)




