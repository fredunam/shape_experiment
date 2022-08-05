# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "examples/behaviors/CMakeFiles/blinky_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/blinky_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/disperse_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/disperse_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/gradient_simple_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/gradient_simple_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/lab_disperse_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/lab_disperse_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/lab_foraging_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/lab_foraging_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/lab_gradient_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/lab_gradient_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/lab_lampe_hypo_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/lab_lampe_hypo_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/lab_listener_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/lab_listener_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/lab_listener_mod_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/lab_listener_mod_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/lab_speaker_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/lab_speaker_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/lab_speaker_mod_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/lab_speaker_mod_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/lab_u_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/lab_u_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/move_to_light_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/move_to_light_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/nonblocked_movement_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/nonblocked_movement_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/orbit_planet_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/orbit_planet_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/orbit_planet_message_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/orbit_planet_message_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/orbit_star_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/orbit_star_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/orbit_star_message_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/orbit_star_message_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/shape_experiment_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/shape_experiment_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/simple_movement_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/simple_movement_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/sync_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/sync_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/test_debug_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/test_debug_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/test_listener_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/test_listener_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/test_listener_mod_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/test_listener_mod_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/test_speaker_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/test_speaker_autogen.dir/ParseCache.txt"
  "examples/behaviors/CMakeFiles/test_speaker_mod_autogen.dir/AutogenUsed.txt"
  "examples/behaviors/CMakeFiles/test_speaker_mod_autogen.dir/ParseCache.txt"
  "examples/behaviors/blinky_autogen"
  "examples/behaviors/disperse_autogen"
  "examples/behaviors/gradient_simple_autogen"
  "examples/behaviors/lab_disperse_autogen"
  "examples/behaviors/lab_foraging_autogen"
  "examples/behaviors/lab_gradient_autogen"
  "examples/behaviors/lab_lampe_hypo_autogen"
  "examples/behaviors/lab_listener_autogen"
  "examples/behaviors/lab_listener_mod_autogen"
  "examples/behaviors/lab_speaker_autogen"
  "examples/behaviors/lab_speaker_mod_autogen"
  "examples/behaviors/lab_u_autogen"
  "examples/behaviors/move_to_light_autogen"
  "examples/behaviors/nonblocked_movement_autogen"
  "examples/behaviors/orbit_planet_autogen"
  "examples/behaviors/orbit_planet_message_autogen"
  "examples/behaviors/orbit_star_autogen"
  "examples/behaviors/orbit_star_message_autogen"
  "examples/behaviors/shape_experiment_autogen"
  "examples/behaviors/simple_movement_autogen"
  "examples/behaviors/sync_autogen"
  "examples/behaviors/test_debug_autogen"
  "examples/behaviors/test_listener_autogen"
  "examples/behaviors/test_listener_mod_autogen"
  "examples/behaviors/test_speaker_autogen"
  "examples/behaviors/test_speaker_mod_autogen"
  "examples/controllers/kilobot_diffusion/CMakeFiles/kilobot_diffusion_autogen.dir/AutogenUsed.txt"
  "examples/controllers/kilobot_diffusion/CMakeFiles/kilobot_diffusion_autogen.dir/ParseCache.txt"
  "examples/controllers/kilobot_diffusion/kilobot_diffusion_autogen"
  "examples/controllers/kilobot_phototaxis/CMakeFiles/kilobot_phototaxis_autogen.dir/AutogenUsed.txt"
  "examples/controllers/kilobot_phototaxis/CMakeFiles/kilobot_phototaxis_autogen.dir/ParseCache.txt"
  "examples/controllers/kilobot_phototaxis/kilobot_phototaxis_autogen"
  "examples/loop_functions/ARKloopfunction/ARKloopfunction_autogen"
  "examples/loop_functions/ARKloopfunction/CMakeFiles/ARKloopfunction_autogen.dir/AutogenUsed.txt"
  "examples/loop_functions/ARKloopfunction/CMakeFiles/ARKloopfunction_autogen.dir/ParseCache.txt"
  "examples/loop_functions/debug_loop_functions/CMakeFiles/debug_loop_functions_autogen.dir/AutogenUsed.txt"
  "examples/loop_functions/debug_loop_functions/CMakeFiles/debug_loop_functions_autogen.dir/ParseCache.txt"
  "examples/loop_functions/debug_loop_functions/debug_loop_functions_autogen"
  "examples/loop_functions/trajectory_loop_functions/CMakeFiles/trajectory_loop_functions_autogen.dir/AutogenUsed.txt"
  "examples/loop_functions/trajectory_loop_functions/CMakeFiles/trajectory_loop_functions_autogen.dir/ParseCache.txt"
  "examples/loop_functions/trajectory_loop_functions/trajectory_loop_functions_autogen"
  "plugins/robots/kilobot/CMakeFiles/argos3plugin_simulator_kilobot_autogen.dir/AutogenUsed.txt"
  "plugins/robots/kilobot/CMakeFiles/argos3plugin_simulator_kilobot_autogen.dir/ParseCache.txt"
  "plugins/robots/kilobot/CMakeFiles/argos3plugin_simulator_kilolib_autogen.dir/AutogenUsed.txt"
  "plugins/robots/kilobot/CMakeFiles/argos3plugin_simulator_kilolib_autogen.dir/ParseCache.txt"
  "plugins/robots/kilobot/argos3plugin_simulator_kilobot_autogen"
  "plugins/robots/kilobot/argos3plugin_simulator_kilolib_autogen"
  )
endif()
