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

#include "itkDCMTKImageIO.h"

#include "itkByteSwapper.h"
#include "itksys/SystemTools.hxx"
#include <iostream>

#include "dcmtk/dcmimgle/dcmimage.h"
#include "dcmtk/dcmjpeg/djdecode.h"

namespace itk
{
/** Constructor */
DCMTKImageIO::DCMTKImageIO()
{
  // standard ImageIOBase variables
  m_ByteOrder = BigEndian;
  this->SetNumberOfDimensions(2);
  m_PixelType = SCALAR;
  m_ComponentType = UCHAR;
  //m_FileType =

  // specific members
  m_UseJPEGCodec = false;
  m_UseJPLSCodec = false;
  m_UseRLECodec  = false;

  this->AddSupportedWriteExtension(".dcm");
  this->AddSupportedWriteExtension(".DCM");
  this->AddSupportedWriteExtension(".dicom");
  this->AddSupportedWriteExtension(".DICOM");

  // this->AddSupportedReadExtension(".dcm");
  // this->AddSupportedReadExtension(".DCM");
  // this->AddSupportedReadExtension(".dicom");
  // this->AddSupportedReadExtension(".DICOM");
}

/** Destructor */
DCMTKImageIO::~DCMTKImageIO()
{}

bool DCMTKImageIO::CanReadFile(const char *filename)
{
  // First check the filename extension
  std::string fname = filename;

  if ( fname == "" )
    {
    itkDebugMacro(<< "No filename specified.");
    }

  bool                   extensionFound = false;
  std::string::size_type dcmPos = fname.rfind(".dcm");
  if ( ( dcmPos != std::string::npos )
       && ( dcmPos == fname.length() - 4 ) )
    {
    extensionFound = true;
    }

  dcmPos = fname.rfind(".DCM");
  if ( ( dcmPos != std::string::npos )
       && ( dcmPos == fname.length() - 4 ) )
    {
    extensionFound = true;
    }

  dcmPos = fname.rfind(".dicom");
  if ( ( dcmPos != std::string::npos )
       && ( dcmPos == fname.length() - 6 ) )
    {
    extensionFound = true;
    }

  dcmPos = fname.rfind(".DICOM");
  if ( ( dcmPos != std::string::npos )
       && ( dcmPos == fname.length() - 6 ) )
    {
    extensionFound = true;
    }

  if ( !extensionFound )
    {
    itkDebugMacro(<< "The filename extension is not recognized");
    return false;
    }

  // check the content by reading the header only (to start)
  return true;
}

bool DCMTKImageIO::CanWriteFile(const char *name)
{
  std::string fname = name;

  if ( fname == "" )
    {
    itkDebugMacro(<< "No filename specified.");
    }

  bool                   extensionFound = false;
  std::string::size_type dcmPos = fname.rfind(".dcm");
  if ( ( dcmPos != std::string::npos )
       && ( dcmPos == fname.length() - 4 ) )
    {
    extensionFound = true;
    }

  dcmPos = fname.rfind(".DCM");
  if ( ( dcmPos != std::string::npos )
       && ( dcmPos == fname.length() - 4 ) )
    {
    extensionFound = true;
    }

  dcmPos = fname.rfind(".dicom");
  if ( ( dcmPos != std::string::npos )
       && ( dcmPos == fname.length() - 6 ) )
    {
    extensionFound = true;
    }

  dcmPos = fname.rfind(".DICOM");
  if ( ( dcmPos != std::string::npos )
       && ( dcmPos == fname.length() - 6 ) )
    {
    extensionFound = true;
    }

  if ( !extensionFound )
    {
    itkDebugMacro(<< "The filename extension is not recognized");
    return false;
    }

  if ( extensionFound )
    {
    return true;
    }
  return false;
}

//------------------------------------------------------------------------------
void DCMTKImageIO::Read(void *buffer)
{
  // start simple
  DicomImage *image = new DicomImage( m_FileName.c_str() );
  if( image != NULL )
    {
    if (image->getStatus() == EIS_Normal)
      {
      m_Dimensions[0] = (unsigned int)(image->getWidth());
      m_Dimensions[1] = (unsigned int)(image->getHeight());
      // m_Spacing[0] =
      // m_Spacing[1] =
      // m_Origin[0] =
      // m_Origin[1] =

      // pick a size for output image (should get it from DCMTK in the ReadImageInformation()))
      // NOTE ALEX: EP_Representation is made for that
      // but i don t know yet where to fetch it from
      const int bitdepth = 8;

      // get the image in the DCMTK buffer
      unsigned long len = image->getOutputDataSize(bitdepth);
      image->getOutputData(buffer, len, bitdepth);
      if( buffer != NULL )
        {
        // we're good
        }
      else
        {
        std::cerr << "Houston, we have a DICOM image." << std::endl;
        // we're not good, deallocate the buffer
        // delete[] buffer;
        /* ynd ... ell */
        }
      }
    else
      {
      std::cerr << "Error: cannot load DICOM image (";
      std::cerr << DicomImage::getString(image->getStatus());
      std::cerr << ")" << std::endl;
      }
    }
  delete image;

}

/**
 *  Read Information about the DICOM file
 */
void DCMTKImageIO::ReadImageInformation()
{
  std::cout << "Starting: ReadImageInformation." << std::endl;

  // NOTE ALEX: this is brutal as it reads the image
  // we shoul dbe able to have something smarter and faster
  // by working with the metadata only
  // http://support.dcmtk.org/wiki/dcmtk/howto/loadmetaheader

  // Make it work first, then make it work better
  // start simple, brutal
  DicomImage *image = new DicomImage( m_FileName.c_str() );
  if( image != NULL )
    {
    if( image->getStatus() != EIS_Normal )
      {
      delete image;
      image = NULL;
      DJDecoderRegistration::registerCodecs(); // register JPEG codecs
      image = new DicomImage( m_FileName.c_str() );
      if( image != NULL )
        {
        if( image->getStatus() != EIS_Normal )
          {
          // try again with other codecs
          }
        }
      }

    // at this stage we have exhausted all codecs,
    if (image->getStatus() == EIS_Normal)
      {
      m_Dimensions[0] = (unsigned int)(image->getWidth());
      m_Dimensions[1] = (unsigned int)(image->getHeight());
      // try to get the "native" pixel type from dcmtk
      }
    else
      {
      std::cerr << "DCMTK could not read the Image.";
      std::cerr << "The transfer syntax might not be supported." << std::endl;
      }
    }
  else
    {
    std::cerr << "DCMTKImageIO::ReadImageInformation: DicomImage could not read the file." << std::endl;
    }
  delete image;

  std::cout << "Ending  : ReadImageInformation." << std::endl;
}

void
DCMTKImageIO
::WriteImageInformation(void)
{}

/** */
void
DCMTKImageIO
::Write(const void *buffer)
{
(void)(buffer);
}

/** Print Self Method */
void DCMTKImageIO::PrintSelf(std::ostream & os, Indent indent) const
{
  Superclass::PrintSelf(os, indent);
}
} // end namespace itk
