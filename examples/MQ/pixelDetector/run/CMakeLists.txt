################################################################################
# Copyright (C) 2014-2019 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH  #
#                                                                              #
#              This software is distributed under the terms of the             #
#              GNU Lesser General Public Licence (LGPL) version 3,             #
#                  copied verbatim in the file "LICENSE"                       #
################################################################################

if(DDS_FOUND)
  if (DDS_LIBRARY_DIR)
    set(dds_location ${DDS_LIBRARY_DIR}/..)
  else()
    set(dds_location ${DDS_INSTALL_PREFIX})
  endif()
  MESSAGE(STATUS "dds location is ${dds_location}")
  set(dds_name_tag "name")
  if(DDS_VERSION VERSION_LESS 2.4)
    set(dds_name_tag "id")
  endif()
endif()

set(pixel_file_dir ${CMAKE_CURRENT_BINARY_DIR})
set(pixel_bin_dir ${CMAKE_CURRENT_BINARY_DIR})
set(fairroot_bin_dir ${CMAKE_BINARY_DIR}/bin)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/startFairMQPixel.sh.in           ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixel.sh @ONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/startFairMQPixelSimulation.sh.in ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixelSimulation.sh @ONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/startFairMQPixel_3Levels.sh.in   ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixel_3Levels.sh)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/startFairMQPixelBin.sh.in        ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixelBin.sh)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/startFairMQPixelBinProxy.sh.in   ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixelBinProxy.sh)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/startFairMQPixelMerger.sh.in     ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixelMerger.sh)
if(DDS_FOUND)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/pixel-dds-topology.xml    ${CMAKE_CURRENT_BINARY_DIR}/pixel-dds-topology.xml)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/pixel-dds-simulation.xml  ${CMAKE_CURRENT_BINARY_DIR}/pixel-dds-simulation.xml)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/pixel-dds-chain.xml       ${CMAKE_CURRENT_BINARY_DIR}/pixel-dds-chain.xml)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/controlDDS.sh.in          ${CMAKE_CURRENT_BINARY_DIR}/controlDDS.sh @ONLY)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/run_pixel_dds_chain.sh.in ${CMAKE_CURRENT_BINARY_DIR}/run_pixel_dds_chain.sh @ONLY)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/test-pixelSim.sh.in       ${CMAKE_CURRENT_BINARY_DIR}/test-pixelSim.sh @ONLY)
endif()

set(pixel_file_dir ${CMAKE_INSTALL_PREFIX}/${PROJECT_INSTALL_DATADIR}/examples/MQ/pixelDetector)
set(pixel_bin_dir ${CMAKE_INSTALL_PREFIX}/${PROJECT_INSTALL_DATADIR}/examples/MQ/pixelDetector/bin)
set(fairroot_bin_dir ${CMAKE_INSTALL_PREFIX}/bin)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/startFairMQPixel.sh.in           ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixel.sh_install @ONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/startFairMQPixelSimulation.sh.in ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixelSimulation.sh_install @ONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/startFairMQPixel_3Levels.sh.in   ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixel_3Levels.sh_install)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/startFairMQPixelBin.sh.in        ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixelBin.sh_install)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/startFairMQPixelBinProxy.sh.in   ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixelBinProxy.sh_install)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/startFairMQPixelMerger.sh.in     ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixelMerger.sh_install)
if(DDS_FOUND)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/pixel-dds-topology.xml    ${CMAKE_CURRENT_BINARY_DIR}/pixel-dds-topology.xml_install)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/pixel-dds-simulation.xml  ${CMAKE_CURRENT_BINARY_DIR}/pixel-dds-simulation.xml_install)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/pixel-dds-chain.xml       ${CMAKE_CURRENT_BINARY_DIR}/pixel-dds-chain.xml_install)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/controlDDS.sh.in          ${CMAKE_CURRENT_BINARY_DIR}/controlDDS.sh_install @ONLY)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/run_pixel_dds_chain.sh.in ${CMAKE_CURRENT_BINARY_DIR}/run_pixel_dds_chain.sh_install @ONLY)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/scripts/test-pixelSim.sh.in       ${CMAKE_CURRENT_BINARY_DIR}/test-pixelSim.sh_install @ONLY)
endif()

set(PIXEL_INSTALL_BIN ${PROJECT_INSTALL_DATADIR}/examples/MQ/pixelDetector/bin)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixel.sh_install           DESTINATION ${PIXEL_INSTALL_BIN} RENAME startFairMQPixel.sh)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixelSimulation.sh_install DESTINATION ${PIXEL_INSTALL_BIN} RENAME startFairMQPixelSimulation.sh)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixel_3Levels.sh_install   DESTINATION ${PIXEL_INSTALL_BIN} RENAME startFairMQPixel_3Levels.sh)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixelBin.sh_install        DESTINATION ${PIXEL_INSTALL_BIN} RENAME startFairMQPixelBin.sh)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixelBinProxy.sh_install   DESTINATION ${PIXEL_INSTALL_BIN} RENAME startFairMQPixelBinProxy.sh)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixelMerger.sh_install     DESTINATION ${PIXEL_INSTALL_BIN} RENAME startFairMQPixelMerger.sh)
if(DDS_FOUND)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/pixel-dds-topology.xml_install   DESTINATION ${PIXEL_INSTALL_BIN} RENAME pixel-dds-topology.xml)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/pixel-dds-simulation.xml_install DESTINATION ${PIXEL_INSTALL_BIN} RENAME pixel-dds-simulation.xml)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/pixel-dds-chain.xml_install      DESTINATION ${PIXEL_INSTALL_BIN} RENAME pixel-dds-chain.xml)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/controlDDS.sh_install            DESTINATION ${PIXEL_INSTALL_BIN} RENAME controlDDS.sh)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/run_pixel_dds_chain.sh_install   DESTINATION ${PIXEL_INSTALL_BIN} RENAME run_pixel_dds_chain.sh)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/test-pixelSim.sh_install         DESTINATION ${PIXEL_INSTALL_BIN} RENAME test-pixelSim.sh)
endif()

set(exe_dependencies
  FairRoot::ExPixel
  FairRoot::FairMQ
  Boost::program_options
)

add_executable(pixel-sampler runPixelSampler.cxx)
target_link_libraries(pixel-sampler PRIVATE ${exe_dependencies})

add_executable(pixel-processor runPixelTaskProcessor.cxx)
target_link_libraries(pixel-processor PRIVATE ${exe_dependencies})

add_executable(pixel-sink runPixelFileSink.cxx)
target_link_libraries(pixel-sink PRIVATE ${exe_dependencies})

add_executable(pixel-sampler-bin runPixelSamplerBin.cxx)
target_link_libraries(pixel-sampler-bin PRIVATE ${exe_dependencies})

add_executable(pixel-processor-bin runPixelTaskProcessorBin.cxx)
target_link_libraries(pixel-processor-bin PRIVATE ${exe_dependencies})

add_executable(pixel-sink-bin runPixelFileSinkBin.cxx)
target_link_libraries(pixel-sink-bin PRIVATE ${exe_dependencies})

add_executable(pixel-merger runPixelMerger.cxx)
target_link_libraries(pixel-merger PRIVATE ${exe_dependencies})

add_executable(pixel-sim runMQSim.cxx)
target_link_libraries(pixel-sim PRIVATE
  ${exe_dependencies}
  FairRoot::Base # FairModule, FairPrimaryGenerator
  FairRoot::Generators # FairBoxGenerator
  FairRoot::ParBase # FairParAsciiFileIo
  FairRoot::ExPassive # FairCave

  ROOT::Core # TSystem
  ROOT::MathCore # TRandom
)

install(TARGETS pixel-sampler pixel-processor pixel-sink pixel-sampler-bin pixel-processor-bin pixel-sink-bin pixel-merger pixel-sim
  RUNTIME DESTINATION ${PROJECT_INSTALL_DATADIR}/examples/MQ/pixelDetector/bin
)

set(maxTestTime 100)

if(DDS_VERSION VERSION_GREATER_EQUAL 3.5
   AND FairMQ_VERSION VERSION_GREATER_EQUAL 1.4.23
   AND TARGET FairMQ::fairmq-dds-command-ui)
  add_test(NAME ex_MQ_pixel_simulation
           COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test-pixelSim.sh)
  set_tests_properties(ex_MQ_pixel_simulation PROPERTIES
    FIXTURES_REQUIRED fixtures.ex_MQ_pixel_static
    TIMEOUT ${maxTestTime}
    PASS_REGULAR_EXPRESSION "Shell script finished successfully"
)
endif()

add_test(NAME ex_MQ_pixel_static
         COMMAND ${CMAKE_CURRENT_BINARY_DIR}/startFairMQPixel.sh --work-dir ${CMAKE_CURRENT_BINARY_DIR}/../ -p 3 --command static --force-kill true)
set_tests_properties(ex_MQ_pixel_static PROPERTIES
  FIXTURES_REQUIRED fixtures.ex_pixel_digi_to_bin_${pixel_simulation_engine}
  TIMEOUT ${maxTestTime}
  RUN_SERIAL ON
  PASS_REGULAR_EXPRESSION "Shell script finished successfully"
  FIXTURES_SETUP fixtures.ex_MQ_pixel_static
)
