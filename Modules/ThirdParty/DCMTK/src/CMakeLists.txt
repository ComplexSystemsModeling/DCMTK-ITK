if( ITK_USE_SYSTEM_DCMTK )
#  TBD
endif()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
set(   LIBRARY_OUTPUT_PATH ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# pure DCMTK configuration variable
# NOTE ALEX: there must be more than that, to investigate later
set(DCMTK_BUILD_APPS OFF)

#-------------------------------------------------------------------------------
# Note regarding libraries and targets
#
# First you need to have a thirdparty library whose targets can be redirected
# through configurable EXPORT. This is done here through the DCMTK_TARGETS_NAME
# in the dcmtk submodule itself
#
# Then you need to define here the right target.
#
# add the source code (add_subdirectory), so the targets are declared
#
# finally register the targets in the module (itk_module_target())
#
# For internal linking you have to declare the needed libs (which can be a
# subset of the targets) in the module lib: ITKDCMTK_LIBRARIES

# configuration variables passed over to DCMTK from ITK
set(DCMTK_TARGETS_NAME ${ITKDCMTK-targets})
set(DCMTK_INSTALL_BIN_DIR ${ITK_INSTALL_RUNTIME_DIR})
set(DCMTK_INSTALL_LIB_DIR ${ITK_INSTALL_LIBRARY_DIR})
set(DCMTK_INSTALL_INCLUDE_DIR ${ITK_INSTALL_INCLUDE_DIR})
#set( ${ITK_INSTALL_ARCHIVE_DIR})
#set( ${ITK_INSTALL_DATA_DIR})
#set( ${ITK_INSTALL_DOC_DIR})
#set( ${ITK_INSTALL_PACKAGE_DIR})

add_subdirectory(dcmtk)

foreach(lib
  dcmdata
  dcmdsig
  dcmimage
  dcmimgle
  dcmjpeg
  dcmnet
  dcmpstat
  dcmqrdb
  dcmsr
  dcmtls
  dcmwlm
  ijg8
  ijg12
  ijg16
  oflog
  ofstd
  )
  if(TARGET ${lib})
    itk_module_target(${lib} NO_INSTALL)
  endif()
endforeach()
