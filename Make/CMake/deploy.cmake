if(WINDOWS)
  add_custom_target(deploy "cmd.exe" /c "bash -c \"if [ -f ../../Build/Linux/Nao/$<CONFIG>/success ]; then ./deployDialog $<CONFIG>; fi\"" WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../Common")
  set_property(TARGET deploy PROPERTY FOLDER Utils)
  add_dependencies(deploy Nao)
  add_dependencies(deploy DeployDialog)
endif()