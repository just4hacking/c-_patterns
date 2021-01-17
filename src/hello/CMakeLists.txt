  
set(lib_name hello)

add_library (${lib_name} 
  speaker.h
  speaker.cpp
)

install (TARGETS ${lib_name} DESTINATION bin)
install (FILES speaker.h DESTINATION include)