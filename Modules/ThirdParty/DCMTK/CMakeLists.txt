#project(ITKDCMTK)
#set(ITKDCMTK_THIRD_PARTY 1)

if(ITK_USE_SYSTEM_DCMTK)
  set(ITKDCMTK_SYSTEM_INCLUDE_DIRS
    ${DCMTK_INCLUDE_DIRS}
    )
  set(ITKDCMTK_INCLUDE_DIRS ${DCMTK_INCLUDE_DIRS})
  set(ITKDCMTK_LIBRARIES ITKDCMTK)
else()
  set(ITKDCMTK_INCLUDE_ROOT ${ITKDCMTK_SOURCE_DIR}/src/dcmtk)
  set(ITKDCMTK_INCLUDE_DIRS
    ${ITKDCMTK_BINARY_DIR}
    ${ITKDCMTK_BINARY_DIR}/include
    ${ITKDCMTK_BINARY_DIR}/include/dcmtk/config
    ${ITKDCMTK_INCLUDE_ROOT}/config/include/dcmtk
    ${ITKDCMTK_INCLUDE_ROOT}/dcmdata/include/dcmtk
    ${ITKDCMTK_INCLUDE_ROOT}/dcmimage/include/dcmtk
    ${ITKDCMTK_INCLUDE_ROOT}/dcmimgle/include/dcmtk
    ${ITKDCMTK_INCLUDE_ROOT}/dcmjpeg/include/dcmtk
    ${ITKDCMTK_INCLUDE_ROOT}/dcmjpls/include/dcmtk
    ${ITKDCMTK_INCLUDE_ROOT}/dcmnet/include/dcmtk
    ${ITKDCMTK_INCLUDE_ROOT}/dcmpstat/include/dcmtk
    ${ITKDCMTK_INCLUDE_ROOT}/dcmqrdb/include/dcmtk
    ${ITKDCMTK_INCLUDE_ROOT}/dcmsign/include/dcmtk
    ${ITKDCMTK_INCLUDE_ROOT}/dcmsr/include/dcmtk
    ${ITKDCMTK_INCLUDE_ROOT}/dcmtls/include/dcmtk
    ${ITKDCMTK_INCLUDE_ROOT}/dcmwlm/include/dcmtk
    ${ITKDCMTK_INCLUDE_ROOT}/oflog/include/dcmtk
    ${ITKDCMTK_INCLUDE_ROOT}/ofstd/include/dcmtk
    )
  message( "Include dir: ${ITKDCMTK_INCLUDE_ROOT}/dcmimgle/include/dcmtk" )
  set(ITKDCMTK_LIBRARIES  dcmdata dcmdsig dcmimage dcmimgle dcmjpeg dcmnet dcmpstat dcmqrdb dcmsr dcmtls dcmwlm ijg8 ijg12 ijg16 oflog ofstd )
endif()

itk_module_impl()
