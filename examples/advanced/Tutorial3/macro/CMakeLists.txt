################################################################################
# Copyright (C) 2014-2019 GSI Helmholtzzentrum fuer Schwerionenforschung GmbH  #
#                                                                              #
#              This software is distributed under the terms of the             #
#              GNU Lesser General Public Licence (LGPL) version 3,             #
#                  copied verbatim in the file "LICENSE"                       #
################################################################################

set(maxTestTime 60)

GENERATE_ROOT_TEST_SCRIPT(${CMAKE_CURRENT_SOURCE_DIR}/run_sim.C)
GENERATE_ROOT_TEST_SCRIPT(${CMAKE_CURRENT_SOURCE_DIR}/run_digi.C)
GENERATE_ROOT_TEST_SCRIPT(${CMAKE_CURRENT_SOURCE_DIR}/run_reco.C)
GENERATE_ROOT_TEST_SCRIPT(${CMAKE_CURRENT_SOURCE_DIR}/run_digi_timebased.C)
GENERATE_ROOT_TEST_SCRIPT(${CMAKE_CURRENT_SOURCE_DIR}/run_reco_timebased.C)
if(BUILD_PROOF_SUPPORT)
  GENERATE_ROOT_TEST_SCRIPT(${CMAKE_CURRENT_SOURCE_DIR}/run_digi_reco_proof.C)
endif()

foreach(mcEngine IN LISTS mcEngine_list)
  add_test(NAME ex_tutorial3_sim_${mcEngine}
           COMMAND ${CMAKE_CURRENT_BINARY_DIR}/run_sim.sh 100 \"${mcEngine}\")
  math(EXPR testTime 3*${maxTestTime})
  set_tests_properties(ex_tutorial3_sim_${mcEngine} PROPERTIES
    TIMEOUT ${testTime}
    PASS_REGULAR_EXPRESSION "Macro finished successfully"
    FIXTURES_SETUP fixture.ex_tutorial3_sim_${mcEngine}
  )

  add_test(NAME ex_tutorial3_digi_${mcEngine}
           COMMAND ${CMAKE_CURRENT_BINARY_DIR}/run_digi.sh \"${mcEngine}\")
  set_tests_properties(ex_tutorial3_digi_${mcEngine} PROPERTIES
    FIXTURES_REQUIRED fixture.ex_tutorial3_sim_${mcEngine}
    TIMEOUT ${maxTestTime}
    PASS_REGULAR_EXPRESSION "Macro finished successfully"
    FIXTURES_SETUP fixture.ex_tutorial3_digi_${mcEngine}
  )

  add_test(NAME ex_tutorial3_reco_${mcEngine}
           COMMAND ${CMAKE_CURRENT_BINARY_DIR}/run_reco.sh \"${mcEngine}\")
  set_tests_properties(ex_tutorial3_reco_${mcEngine} PROPERTIES
    FIXTURES_REQUIRED fixture.ex_tutorial3_digi_${mcEngine}
    TIMEOUT ${maxTestTime}
    PASS_REGULAR_EXPRESSION "Macro finished successfully"
  )

  add_test(NAME ex_tutorial3_digi_timebased_${mcEngine}
           COMMAND ${CMAKE_CURRENT_BINARY_DIR}/run_digi_timebased.sh \"${mcEngine}\")
  set_tests_properties(ex_tutorial3_digi_timebased_${mcEngine} PROPERTIES
    FIXTURES_REQUIRED fixture.ex_tutorial3_sim_${mcEngine}
    TIMEOUT ${maxTestTime}
    PASS_REGULAR_EXPRESSION "Macro finished successfully"
    FIXTURES_SETUP fixture.ex_tutorial3_digi_timebased_${mcEngine}
  )

  add_test(NAME ex_tutorial3_reco_timebased_${mcEngine}
           COMMAND ${CMAKE_CURRENT_BINARY_DIR}/run_reco_timebased.sh \"${mcEngine}\")
  set_tests_properties(ex_tutorial3_reco_timebased_${mcEngine} PROPERTIES
    FIXTURES_REQUIRED fixture.ex_tutorial3_digi_timebased_${mcEngine}
    TIMEOUT ${maxTestTime}
    PASS_REGULAR_EXPRESSION "Macro finished successfully"
  )

  if(BUILD_PROOF_SUPPORT)
    add_test(NAME ex_tutorial3_digi_reco_proof_${mcEngine}
             COMMAND ${CMAKE_CURRENT_BINARY_DIR}/run_digi_reco_proof.sh 1 \"${mcEngine}\")
    set_tests_properties(ex_tutorial3_digi_reco_proof_${mcEngine} PROPERTIES
      FIXTURES_REQUIRED fixture.ex_tutorial3_sim_${mcEngine}
      TIMEOUT ${maxTestTime}
      PASS_REGULAR_EXPRESSION "Macro finished successfully"
    )
  endif()
endforeach()

install(FILES
  run_sim.C run_digi.C run_reco.C eventDisplay.C run_digi_timebased.C run_reco_timebased.C
  DESTINATION ${PROJECT_INSTALL_DATADIR}/examples/advanced/Tutorial3
)

install(FILES
  data/dummy.txt
  DESTINATION ${PROJECT_INSTALL_DATADIR}/examples/advanced/Tutorial3/macro/data
)
