set(lib_name talk)
 
add_library (${lib_name}
  talker.h
  talker.cpp
)

install (TARGETS ${lib_name} DESTINATION bin)
install (FILES talker.h DESTINATION include)