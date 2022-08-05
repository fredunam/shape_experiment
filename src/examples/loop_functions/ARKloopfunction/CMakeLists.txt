
add_library(ARKloopfunction MODULE 
	ark_experiment2.h 
	ark_experiment2.cpp)

target_link_libraries(ARKloopfunction
  argos3core_simulator
  argos3plugin_simulator_dynamics2d
  argos3plugin_simulator_entities
  argos3plugin_simulator_media
  argos3plugin_simulator_kilobot
  argos3plugin_simulator_kilolib
	${ARGOS_QTOPENGL_LIBRARIES})
