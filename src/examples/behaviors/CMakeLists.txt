if(ARGOS_BUILD_FOR_SIMULATOR)
  include_directories(${CMAKE_SOURCE_DIR}/plugins/robots/kilobot/control_interface)

  #
  # Lab0: Blinky
  #
#  add_executable(blinky blinky.c)
#  target_link_libraries(blinky argos3plugin_simulator_kilolib)

  #
  # Lab1.2: Simple Movement
  #
  add_executable(simple_movement simple_movement.c)
  target_link_libraries(simple_movement argos3plugin_simulator_kilolib)

  #
  # Lab1.3: Non-blocked Movement
  #
  add_executable(nonblocked_movement nonblocked_movement.c)
  target_link_libraries(nonblocked_movement argos3plugin_simulator_kilolib)

  #
  # Lab2.1-2.2: Test Speaker and Test Listener
  #
  add_executable(test_speaker test_speaker.c)
  target_link_libraries(test_speaker argos3plugin_simulator_kilolib)
  add_executable(test_listener test_listener.c)
  target_link_libraries(test_listener argos3plugin_simulator_kilolib)

  #
  # Lab2.3-2.4: Modified Test Speaker and Test Listener
  #
  add_executable(test_speaker_mod test_speaker_mod.c)
  target_link_libraries(test_speaker_mod argos3plugin_simulator_kilolib)
  add_executable(test_listener_mod test_listener_mod.c)
  target_link_libraries(test_listener_mod argos3plugin_simulator_kilolib)

  #
  # Lab3: Disperse
  #
  add_executable(disperse disperse.c)
  target_link_libraries(disperse argos3plugin_simulator_kilolib)

  #
  # Lab4: Orbit
  #
  add_executable(orbit_star orbit_star.c)
  target_link_libraries(orbit_star argos3plugin_simulator_kilolib)
  add_executable(orbit_planet orbit_planet.c)
  target_link_libraries(orbit_planet argos3plugin_simulator_kilolib)

  #
  # Lab5: Move to Light
  #
  add_executable(move_to_light move_to_light.c)
  target_link_libraries(move_to_light argos3plugin_simulator_kilolib)

  #
  # Lab6: Simple Gradient
  #
  add_executable(gradient_simple gradient_simple.c)
  target_link_libraries(gradient_simple argos3plugin_simulator_kilolib)

  #
  # Lab7: Sync
  #
  add_executable(sync sync.c)
  target_link_libraries(sync argos3plugin_simulator_kilolib)

  #
  # Debugging example
  #
  add_executable(test_debug test_debug.h test_debug.c)
  target_link_libraries(test_debug argos3plugin_simulator_kilolib)
  
  
  
  
  # ******************************************************************* #
  #                       personal experience lab                       #
  # ******************************************************************* #
  
  
  #
  # Lab_F1: Orbit_message
  #
  add_executable(orbit_star_message orbit_star_message.c)
  target_link_libraries(orbit_star_message argos3plugin_simulator_kilolib)
  add_executable(orbit_planet_message orbit_planet_message.c)
  target_link_libraries(orbit_planet_message argos3plugin_simulator_kilolib)
  
  #
  # Lab_communication
  #
  add_executable(lab_speaker lab_speaker.c)
  target_link_libraries(lab_speaker argos3plugin_simulator_kilolib)
  add_executable(lab_listener lab_listener.c)
  target_link_libraries(lab_listener argos3plugin_simulator_kilolib)
  
   #
  # Lab_communication_mod
  #
  add_executable(lab_speaker_mod lab_speaker_mod.c)
  target_link_libraries(lab_speaker_mod argos3plugin_simulator_kilolib)
  add_executable(lab_listener_mod lab_listener_mod.c)
  target_link_libraries(lab_listener_mod argos3plugin_simulator_kilolib)
  
  #
  # Lab Disperse
  #
  add_executable(lab_disperse lab_disperse.c)
  target_link_libraries(lab_disperse argos3plugin_simulator_kilolib)
  
  
 #
  # Lab Gradient
  #
  add_executable(lab_gradient lab_gradient.c)
  target_link_libraries(lab_gradient argos3plugin_simulator_kilolib)
  
  #
  # Lab lampe hypo
  #
  add_executable(lab_lampe_hypo lab_lampe_hypo.c)
  target_link_libraries(lab_lampe_hypo argos3plugin_simulator_kilolib)
  
    #
  # Lab u
  #
  add_executable(lab_u lab_u.c)
  target_link_libraries(lab_u argos3plugin_simulator_kilolib)
  
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
