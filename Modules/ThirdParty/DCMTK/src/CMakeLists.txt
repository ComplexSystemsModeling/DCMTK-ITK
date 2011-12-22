set(EXECUTABLE_OUTPUT_PATH ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(   LIBRARY_OUTPUT_PATH ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# pure DCMTK configuration variable
set(DCMTK_BUILD_APPS OFF)

# configuration variables passed over to DCMTK from ITK
set(DCMTK_TARGETS_NAME ${ITKDCMTK-targets})
set(DCMTK_INSTALL_BIN_DIR ${ITK_INSTALL_RUNTIME_DIR})
set(DCMTK_INSTALL_LIB_DIR ${ITK_INSTALL_LIBRARY_DIR})
set(DCMTK_INSTALL_INCLUDE_DIR ${ITK_INSTALL_INCLUDE_DIR})
#set( ${ITK_INSTALL_ARCHIVE_DIR})
#set( ${ITK_INSTALL_DATA_DIR})
#set( ${ITK_INSTALL_DOC_DIR})
#set( ${ITK_INSTALL_PACKAGE_DIR})


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
