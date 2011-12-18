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

#include "dcmimgle/dcmimage.h"

namespace itk
{
/** Constructor */
DCMTKImageIO::DCMTKImageIO()
{
  //m_ByteOrder = BigEndian;
  //m_BitMapOffset = 0;
  this->SetNumberOfDimensions(2);
  //m_PixelType = SCALAR;
  //m_ComponentType = UCHAR;
  //m_Spacing[0] = 1.0;
  //m_Spacing[1] = 1.0;

  //m_Origin[0] = 0.0;
  //m_Origin[1] = 0.0;
  //m_FileLowerLeft = 0;
  //m_Depth = 8;
  //m_NumberOfColors = 0;
  //m_ColorTableSize = 0;

  this->AddSupportedWriteExtension(".dcm");
  this->AddSupportedWriteExtension(".DCM");
  this->AddSupportedWriteExtension(".dicom");
  this->AddSupportedWriteExtension(".DICOM");

  this->AddSupportedReadExtension(".dcm");
  this->AddSupportedReadExtension(".DCM");
  this->AddSupportedReadExtension(".dicom");
  this->AddSupportedReadExtension(".DICOM");
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

void DCMTKImageIO::Read(void *buffer)
{
  // start simple
  DicomImage *image; // = new DicomImage("test.dcm");

  // TBD

  // DCMTK MINMAL EXAMPLE
  //#include "diregist.h"   /* required to support color images */
  ///* ... */
  //DicomImage *image = new DicomImage("test.dcm");
  //if (image != NULL)
  //{
  //  if (image->getStatus() == EIS_Normal)
  //  {
  //  Uint8 *pixelData = (Uint8 *)(image->getOutputData(8 /* bits per sample */));
  //  if (pixelData != NULL)
  //    {
  //    /* do something useful with the pixel data */
  //    }
  //  } else
  //  cerr << "Error: cannot load DICOM image (" << DicomImage::getString(image->getStatus()) << ")" << endl;
  //}
  //delete image;

  // CTK example on how to read with dcmtk and make a QImage
  // EI_Status result = dcmImage.getStatus();
  //  if (result != EIS_Normal)
  //  {
  //    logger.error(QString("Rendering of DICOM image failed for thumbnail failed: ") + DicomImage::getString(result));
  //    return;
  //  }
  //  // Select first window defined in image. If none, compute min/max window as best guess.
  //  // Only relevant for monochrome
  //  if (d->AutoWindowLevel)
  //  {
  //    if (dcmImage.isMonochrome())
  //    {
  //        if (defaultIntensity && dcmImage.getWindowCount() > 0)
  //        {
  //          dcmImage.setWindow(0);
  //        }
  //        else
  //        {
  //          dcmImage.setMinMaxWindow(OFTrue /* ignore extreme values */);
  //          dcmImage.getWindow(d->DicomIntensityLevel, d->DicomIntensityWindow);
  //        }
  //    }
  //  }
  //  else
  //  {
  //    dcmImage.setWindow(d->DicomIntensityLevel, d->DicomIntensityWindow);
  //  }
  //  /* get image extension and prepare image header */
  //  const unsigned long width = dcmImage.getWidth();
  //  const unsigned long height = dcmImage.getHeight();
  //  unsigned long offset = 0;
  //  unsigned long length = 0;
  //  QString header;
  //
  //  if (dcmImage.isMonochrome())
  //  {
  //    // write PGM header (binary monochrome image format)
  //    header = QString("P5 %1 %2 255\n").arg(width).arg(height);
  //    offset = header.length();
  //    length = width * height + offset;
  //  }
  //  else
  //  {
  //    // write PPM header (binary color image format)
  //    header = QString("P6 %1 %2 255\n").arg(width).arg(height);
  //    offset = header.length();
  //    length = width * height * 3 /* RGB */ + offset;
  //  }
  //  /* create output buffer for DicomImage class */
  //  QByteArray buffer;
  //  /* copy header to output buffer and resize it for pixel data */
  //  buffer.append(header);
  //  buffer.resize(length);
  //
  //  /* render pixel data to buffer */
  //  if (dcmImage.getOutputData(static_cast<void *>(buffer.data() + offset), length - offset, 8, 0))
  //  {
  //    if (!image.loadFromData( buffer ))
  //      {
  //          logger.error("QImage couldn't created");
  //      }
  //  }
  //  this->addImage(image);

}

/**
 *  Read Information about the DICOM file
 *  and put the cursor of the stream just before the first data pixel
 */
void DCMTKImageIO::ReadImageInformation()
{
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
}

/** Print Self Method */
void DCMTKImageIO::PrintSelf(std::ostream & os, Indent indent) const
{
  Superclass::PrintSelf(os, indent);
}
} // end namespace itk
