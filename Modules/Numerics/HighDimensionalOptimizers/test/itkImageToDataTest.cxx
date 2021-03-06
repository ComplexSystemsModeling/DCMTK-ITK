/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#include "itkImageToData.h"

/*
 * Main test entry function
 */
int itkImageToDataTest(int , char* [])
{
  typedef itk::ImageToData<2, itk::Object> ImageToDataType;

  ImageToDataType::Pointer imageToDataThreader = ImageToDataType::New();

  typedef ImageToDataType::ImageRegionType ImageRegionType;

  typedef ImageRegionType::SizeType   SizeType;
  typedef ImageRegionType::IndexType  IndexType;

  SizeType size;
  IndexType start;

  size.Fill(100);
  start.Fill(0);

  ImageRegionType region;

  region.SetSize( size );
  region.SetIndex( start );

  imageToDataThreader->SetOverallRegion( region );

  return EXIT_SUCCESS;
}
