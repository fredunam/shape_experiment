if(ARGOS_BUILD_FOR_SIMULATOR)
  include_directories(${CMAKE_SOURCE_DIR}/plugins/robots/kilobot/control_interface)

  #
  # Lab ark
  #
  add_executable(lab_foraging lab_foraging.c)
  target_link_libraries(lab_foraging argos3plugin_simulator_kilolib)

  #
  # Lab shape
  #
  add_executable(shape_experiment shape_experiment.c)
  target_link_libraries(shape_experiment argos3plugin_simulator_kilolib)
  
endif(ARGOS_BUILD_FOR_SIMULATOR)
