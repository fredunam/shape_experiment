# If Qt+OpenGL dependencies were found, descend into these directories
if(ARGOS_QTOPENGL_FOUND)
  add_subdirectory(debug_loop_functions)
  add_subdirectory(trajectory_loop_functions)
  add_subdirectory(ARKloopfunction)
endif(ARGOS_QTOPENGL_FOUND)
