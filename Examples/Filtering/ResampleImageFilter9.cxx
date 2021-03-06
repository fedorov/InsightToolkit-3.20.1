/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    ResampleImageFilter9.cxx
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif

#ifdef __BORLANDC__
#define ITK_LEAN_AND_MEAN
#endif

//  Software Guide : BeginLatex
//
//  Resampling can also be performed in multi-component images. 
//  This example compares nearest neighbor resampling using the Nearest 
//  neighbor and the linear interpolators for vector images.
//  
//  Try 
//    ResampleImageFilter9 Examples/Data/VisibleWomanEyeSlice.png 
//        SliceNearestNeighbor.png SliceLinear.png
//
//  \index{itk::VectorResampleImageFilter!Image internal transform}
//
//  Software Guide : EndLatex 


#include "itkImage.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkVectorResampleImageFilter.h"
#include "itkIdentityTransform.h"
#include "itkVectorNearestNeighborInterpolateImageFunction.h"
#include "itkLinearInterpolateImageFunction.h"
#include "itkRGBPixel.h"


int main( int argc, char * argv[] )
{
  if( argc < 4 )
    {
    std::cerr << "Usage: " << std::endl;
    std::cerr << argv[0] << 
      "  inputImageFile  outputImageFile_NearestNeighbor" << 
      "  outputImageFile_Linear " << std::endl;
    return EXIT_FAILURE;
    }

  const     unsigned int   Dimension = 2;
  typedef   unsigned char  PixelComponentType;
  typedef   itk::RGBPixel< PixelComponentType > PixelType;

  typedef itk::Image< PixelType,  Dimension >   ImageType;


  typedef itk::ImageFileReader< ImageType >  ReaderType;
  typedef itk::ImageFileWriter< ImageType >  WriterType;

  ReaderType::Pointer reader = ReaderType::New();
  WriterType::Pointer writerNearest = WriterType::New(); // writer for nearest neighbor
  WriterType::Pointer writerLinear = WriterType::New(); // writer for linear

  reader->SetFileName( argv[1] );
  writerNearest->SetFileName( argv[2] );
  writerLinear->SetFileName( argv[3] );

  typedef itk::VectorResampleImageFilter<
                            ImageType, ImageType >  FilterType;

  FilterType::Pointer nearestFilter = FilterType::New();
  FilterType::Pointer linearFilter = FilterType::New();

  //Interpolators
  typedef itk::VectorNearestNeighborInterpolateImageFunction< 
                       ImageType, double >  NearestInterpolatorType;
  NearestInterpolatorType::Pointer interpolatorNearest = NearestInterpolatorType::New();
  
  typedef itk::VectorLinearInterpolateImageFunction< 
                       ImageType, double >  LinearInterpolatorType;
  LinearInterpolatorType::Pointer interpolatorLinear = LinearInterpolatorType::New();

  nearestFilter->SetInterpolator( interpolatorNearest );
  linearFilter->SetInterpolator( interpolatorLinear );

  typedef itk::IdentityTransform< double, Dimension >  TransformType;
  TransformType::Pointer transform = TransformType::New();

  nearestFilter->SetTransform( transform );
  linearFilter->SetTransform( transform );

  // Software Guide : BeginCodeSnippet
  PixelType defaultValue;
  defaultValue.Fill(50);
  nearestFilter->SetDefaultPixelValue( defaultValue );
  linearFilter->SetDefaultPixelValue( defaultValue );
  // Software Guide : EndCodeSnippet


  // Software Guide : BeginCodeSnippet
  ImageType::SpacingType spacing;
  spacing[0] = .35; // pixel spacing in millimeters along X
  spacing[1] = .35; // pixel spacing in millimeters along Y

  nearestFilter->SetOutputSpacing( spacing );
  linearFilter->SetOutputSpacing( spacing );
  // Software Guide : EndCodeSnippet


  // Software Guide : BeginCodeSnippet
  ImageType::PointType origin;
  origin[0] = 0.4;  // X space coordinate of origin
  origin[1] = 0.4;  // Y space coordinate of origin
  nearestFilter->SetOutputOrigin( origin );
  linearFilter->SetOutputOrigin( origin );
  // Software Guide : EndCodeSnippet


  // Software Guide : BeginCodeSnippet
  ImageType::DirectionType direction;
  direction.SetIdentity();
  nearestFilter->SetOutputDirection( direction );
  linearFilter->SetOutputDirection( direction );
  // Software Guide : EndCodeSnippet


  ImageType::SizeType   size;

  size[0] = 300;  // number of pixels along X
  size[1] = 300;  // number of pixels along Y

  nearestFilter->SetSize( size );
  linearFilter->SetSize( size );

  nearestFilter->SetInput( reader->GetOutput() );
  linearFilter->SetInput( reader->GetOutput() );
  writerNearest->SetInput( nearestFilter->GetOutput() );
  writerLinear->SetInput( linearFilter->GetOutput() );


  
  try
    {
    writerNearest->Update();
    }
  catch( itk::ExceptionObject & excp )
    {
    std::cerr << "Exception thrown " << std::endl;
    std::cerr << excp << std::endl;
    }

  try
    {
    writerLinear->Update();
    }
  catch( itk::ExceptionObject & excp )
    {
    std::cerr << "Exception thrown " << std::endl;
    std::cerr << excp << std::endl;
    }

  return EXIT_SUCCESS;

}

