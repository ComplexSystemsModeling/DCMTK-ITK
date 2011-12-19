set(EXECUTABLE_OUTPUT_PATH ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(LIBRARY_OUTPUT_PATH ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set(DCMTK_BUILD_APPS OFF)
set(DCMTK_TARGETS_NAME ${ITKDCMTK-targets})

add_subdirectory(dcmtk)

#foreach(lib
#  dcmdata
#  dcmdsig
#  dcmimage
#  dcmimgle
#  dcmjpeg
#  dcmnet
#  dcmpstat
#  dcmqrdb
#  dcmsr
#  dcmtls
#  dcmwlm
#  ijg8
#  ijg12
#  ijg16
#  oflog
#  ofstd
#  )
#  itk_module_target(${lib}) # NO_INSTALL)
#endforeach()
