project(ITKDCMTK)
set(ITKDCMTK_THIRD_PARTY 1)

if(ITK_USE_SYSTEM_DCMTK)
  set(ITKDCMTK_SYSTEM_INCLUDE_DIRS
    ${DCMTK_INCLUDE_DIRS}
    )
  set(ITKDCMTK_INCLUDE_DIRS ${DCMTK_INCLUDE_DIRS})
  set(ITKDCMTK_LIBRARIES ITKDCMTK)
else()
  set(ITKDCMTK_INCLUDE_ROOT ${ITKDCMTK_SOURCE_DIR}/src/dcmtk)
  set(ITKDCMTK_INCLUDE_DIRS
    ${ITKDCMTK_BINARY_DIR}/src/dcmtk/include
    ${ITKDCMTK_INCLUDE_ROOT}/config/include
    ${ITKDCMTK_INCLUDE_ROOT}/dcmdata/include
    ${ITKDCMTK_INCLUDE_ROOT}/dcmimage/include
    ${ITKDCMTK_INCLUDE_ROOT}/dcmimgle/include
    ${ITKDCMTK_INCLUDE_ROOT}/dcmjpeg/include
    ${ITKDCMTK_INCLUDE_ROOT}/dcmjpls/include
    ${ITKDCMTK_INCLUDE_ROOT}/dcmnet/include
    ${ITKDCMTK_INCLUDE_ROOT}/dcmpstat/include
    ${ITKDCMTK_INCLUDE_ROOT}/dcmqrdb/include
    ${ITKDCMTK_INCLUDE_ROOT}/dcmsign/include
    ${ITKDCMTK_INCLUDE_ROOT}/dcmsr/include
    ${ITKDCMTK_INCLUDE_ROOT}/dcmtls/include
    ${ITKDCMTK_INCLUDE_ROOT}/dcmwlm/include
    ${ITKDCMTK_INCLUDE_ROOT}/oflog/include
    ${ITKDCMTK_INCLUDE_ROOT}/ofstd/include
    )
  set(ITKDCMTK_LIBRARIES  dcmdata dcmdsig dcmimage dcmimgle dcmjpeg dcmnet dcmpstat dcmqrdb dcmsr dcmtls dcmwlm ijg8 ijg12 ijg16 oflog ofstd )
endif()

itk_module_impl()
