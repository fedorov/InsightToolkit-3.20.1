/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkQuadEdgeTest1.cxx
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

#include "itkQuadEdge.h"
#include <iostream>

int itkQuadEdgeTest1( int , char* [] )
{
  typedef itk::QuadEdge        QuadEdgeType;

  // Tests for the GetRot() SetRot() methods
    { // create a local scope for these tests
    QuadEdgeType * quadEdge1 = new QuadEdgeType;
    QuadEdgeType * quadEdge2 = new QuadEdgeType;
    QuadEdgeType * quadEdge3 = new QuadEdgeType;
    const QuadEdgeType * quadEdge1c = quadEdge1;

    quadEdge1->GetRot(); // testing null case

    // Verify that it can be set.
    quadEdge1->SetRot( quadEdge2 );
    if( quadEdge1->GetRot() != quadEdge2 )
      {
      std::cerr << "Error in SetRot() / GetRot() " << std::endl;
      return EXIT_FAILURE;
      }
    // Test the const version
    if( quadEdge1c->GetRot() != quadEdge2 )
      {
      std::cerr << "Error in const GetRot() " << std::endl;
      return EXIT_FAILURE;
      }

    // Verify that it can be changed.
    quadEdge1->SetRot( quadEdge3 );
    if( quadEdge1->GetRot() != quadEdge3 )
      {
      std::cerr << "Error in changing SetRot() / GetRot() " << std::endl;
      return EXIT_FAILURE;
      }
    // Test the const version
    if( quadEdge1c->GetRot() != quadEdge3 )
      {
      std::cerr << "Error in changed const GetRot() " << std::endl;
      return EXIT_FAILURE;
      }

    std::cout << "GetRot()/SetRot() Test passed ! " << std::endl;

    delete quadEdge1;
    delete quadEdge2;
    delete quadEdge3;
    } // end of local scope for tests

    // Tests for the GetOnext() SetOnext() methods
    { // create a local scope for these tests
    QuadEdgeType * quadEdge1 = new QuadEdgeType;
    QuadEdgeType * quadEdge2 = new QuadEdgeType;
    QuadEdgeType * quadEdge3 = new QuadEdgeType;
    const QuadEdgeType * quadEdge1c = quadEdge1;

    quadEdge1->GetOnext(); // testing null case

    // Verify that it can be set.
    quadEdge1->SetOnext( quadEdge2 );
    if( quadEdge1->GetOnext() != quadEdge2 )
      {
      std::cerr << "Error in SetOnext() / GetOnext() " << std::endl;
      return EXIT_FAILURE;
      }
    // Test the const version
    if( quadEdge1c->GetOnext() != quadEdge2 )
      {
      std::cerr << "Error in const GetOnext() " << std::endl;
      return EXIT_FAILURE;
      }

    // Verify that it can be changed.
    quadEdge1->SetOnext( quadEdge3 );
    if( quadEdge1->GetOnext() != quadEdge3 )
      {
      std::cerr << "Error in changing SetOnext() / GetOnext() " << std::endl;
      return EXIT_FAILURE;
      }
    // Test the const version
    if( quadEdge1c->GetOnext() != quadEdge3 )
      {
      std::cerr << "Error changed const GetOnext() " << std::endl;
      return EXIT_FAILURE;
      }

    std::cout << "GetOnext()/SetOnext() Test passed ! " << std::endl;

    delete quadEdge1;
    delete quadEdge2;
    delete quadEdge3;
    } // end of local scope for tests

    // Tests for the GetSym() methods
    { // create a local scope for these tests
    QuadEdgeType * quadEdge1 = new QuadEdgeType;
    QuadEdgeType * quadEdge2 = new QuadEdgeType;
    QuadEdgeType * quadEdge3 = new QuadEdgeType;
    QuadEdgeType * quadEdge4 = new QuadEdgeType;
    const QuadEdgeType * quadEdge1c = quadEdge1;
    const QuadEdgeType * quadEdge2c = quadEdge2;
    const QuadEdgeType * quadEdge3c = quadEdge3;
    const QuadEdgeType * quadEdge4c = quadEdge4;

    // testing first GetSym()'s fail case
    if( quadEdge1->GetSym() || quadEdge1c->GetSym() )
      {
      std::cerr << "Error GetSym( ) should fail here " << std::endl;
      return EXIT_FAILURE;
      }

    // testing the second GetSym()'s fail case
    quadEdge1->SetRot( quadEdge2 );
    if( quadEdge1->GetSym() || quadEdge1c->GetSym() )
      {
      std::cerr << "Error GetSym( ) should fail here " << std::endl;
      return EXIT_FAILURE;
      }

    quadEdge2->SetRot( quadEdge3 );
    quadEdge3->SetRot( quadEdge4 );
    quadEdge4->SetRot( quadEdge1 );

    if( quadEdge1->GetSym() != quadEdge3 )
      {
      std::cerr << "Error in GetSym() " << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdge1c->GetSym() != quadEdge3 )
      {
      std::cerr << "Error in const GetSym() " << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdge2->GetSym() != quadEdge4 )
      {
      std::cerr << "Error in GetSym() B " << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdge2c->GetSym() != quadEdge4 )
      {
      std::cerr << "Error in const GetSym() B" << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdge3->GetSym() != quadEdge1 )
      {
      std::cerr << "Error in GetSym() C " << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdge3c->GetSym() != quadEdge1 )
      {
      std::cerr << "Error in const GetSym() C" << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdge4->GetSym() != quadEdge2 )
      {
      std::cerr << "Error in GetSym() D " << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdge4c->GetSym() != quadEdge2 )
      {
      std::cerr << "Error in const GetSym() D" << std::endl;
      return EXIT_FAILURE;
      }

    delete quadEdge1;
    delete quadEdge2;
    delete quadEdge3;
    delete quadEdge4;

    std::cout << "GetSym()   Test passed ! " << std::endl;
    }


    // Tests for the GetLnext() methods
    // returns the next edge with same left face
    { // create a local scope for these tests
    QuadEdgeType * quadEdge1 = new QuadEdgeType;
    QuadEdgeType * quadEdge2 = new QuadEdgeType;
    QuadEdgeType * quadEdge3 = new QuadEdgeType;
    QuadEdgeType * quadEdge4 = new QuadEdgeType;
    QuadEdgeType * quadEdgeA = new QuadEdgeType;
    QuadEdgeType * quadEdgeB = new QuadEdgeType;
    const QuadEdgeType * quadEdge1c = quadEdge1;

#ifndef NDEBUG
    // testing first fail case
    if( quadEdge1->GetLnext() || quadEdge1c->GetLnext() )
      {
      std::cerr << "Error in GetLNext()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    //                        /
    //                       / quadEdgeA
    //          Face        /
    //                     /
    //                    /
    //   --------------->O
    //   quadEdge1
    //

    quadEdge1->SetRot( quadEdge2 );
    quadEdge2->SetRot( quadEdge3 );
    quadEdge3->SetRot( quadEdge4 );
    quadEdge4->SetRot( quadEdge1 );

#ifndef NDEBUG
    // testing second fail case
    quadEdge4->SetOnext( NULL );
    if( quadEdge1->GetLnext() || quadEdge1c->GetLnext() )
      {
      std::cerr << "Error in GetLnext()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    // testing third fail case
    quadEdge4->SetOnext( quadEdgeB );
#ifndef NDEBUG
    if( quadEdge1->GetLnext() || quadEdge1c->GetLnext() )
      {
      std::cerr << "Error in GetLnext()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    quadEdgeB->SetRot( quadEdgeA );

    if( quadEdge1->GetLnext() != quadEdgeA )
      {
      std::cerr << "Error in GetLnext()" << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdge1c->GetLnext() != quadEdgeA )
      {
      std::cerr << "Error in const GetLnext()" << std::endl;
      return EXIT_FAILURE;
      }

    delete quadEdge1;
    delete quadEdge2;
    delete quadEdge3;
    delete quadEdge4;
    delete quadEdgeA;
    delete quadEdgeB;

    std::cout << "GetLnext() Test passed ! " << std::endl;
    }

    // Tests for the GetRnext() methods
    // returns the next edge with same right face
    { // create a local scope for these tests
    QuadEdgeType * quadEdge1 = new QuadEdgeType;
    QuadEdgeType * quadEdge2 = new QuadEdgeType;
    QuadEdgeType * quadEdge3 = new QuadEdgeType;
    QuadEdgeType * quadEdge4 = new QuadEdgeType;
    QuadEdgeType * quadEdgeA = new QuadEdgeType;
    QuadEdgeType * quadEdgeB = new QuadEdgeType;
    const QuadEdgeType * quadEdgeAc = quadEdgeA;

#ifndef NDEBUG
    const QuadEdgeType * quadEdge1c = quadEdge1;

    // testing first fail case
    if( quadEdge1->GetRnext() || quadEdge1c->GetRnext( ) )
      {
      std::cerr << "Error in GetRnext()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    //
    //        quadEdge1
    //   --------------------->O
    //                        /
    //                       /
    //          Face        /
    //                     /quadEdgeA
    //                    /
    //

    quadEdge1->SetRot( quadEdge2 );
    quadEdge2->SetRot( quadEdge3 );
    quadEdge3->SetRot( quadEdge4 );
    quadEdge4->SetRot( quadEdge1 );

#ifndef NDEBUG
    quadEdge2->SetOnext( NULL );
    if( quadEdge1->GetRnext() || quadEdge1c->GetRnext( ) )
      {
      std::cerr << "Error in GetRnext()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    quadEdge2->SetOnext( quadEdgeB );
    quadEdgeB->SetOnext( quadEdge2 );
#ifndef NDEBUG
    if( quadEdge1->GetRnext() || quadEdge1c->GetRnext( ) )
      {
      std::cerr << "Error in GetRnext()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    quadEdgeA->SetRot( quadEdgeB );

    if( quadEdgeA->GetRnext() != quadEdge1 )
      {
      std::cerr << "Error in GetRnext()" << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdgeAc->GetRnext() != quadEdge1 )
      {
      std::cerr << "Error in const GetRnext()" << std::endl;
      return EXIT_FAILURE;
      }

    delete quadEdge1;
    delete quadEdge2;
    delete quadEdge3;
    delete quadEdge4;
    delete quadEdgeA;
    delete quadEdgeB;

    std::cout << "GetRnext() Test passed ! " << std::endl;
    }

    // Tests for the GetDnext() methods
    // returns the next edge with same right face
    // and same destination
    { // create a local scope for these tests
    QuadEdgeType * quadEdge1 = new QuadEdgeType;
    QuadEdgeType * quadEdge2 = new QuadEdgeType;
    QuadEdgeType * quadEdge3 = new QuadEdgeType;
    QuadEdgeType * quadEdge4 = new QuadEdgeType;

    QuadEdgeType * quadEdgeA = new QuadEdgeType;
    QuadEdgeType * quadEdgeB = new QuadEdgeType;
    QuadEdgeType * quadEdgeC = new QuadEdgeType;
    QuadEdgeType * quadEdgeD = new QuadEdgeType;

    const QuadEdgeType * quadEdge1c = quadEdge1;

#ifndef NDEBUG
    if( quadEdge1->GetDnext() || quadEdge1c->GetDnext( ) )
      {
      std::cerr << "Error 1 in GetDnext()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    //
    //        quadEdge1
    //   -------------------->-O
    //                         ^
    //                         |
    //          Face           |
    //                         |  quadEdgeC
    //                         |
    //

    quadEdge1->SetRot( quadEdge2 );
    quadEdge2->SetRot( quadEdge3 );
    quadEdge3->SetRot( quadEdge4 );
    quadEdge4->SetRot( quadEdge1 );

#ifndef NDEBUG
    quadEdge3->SetOnext( NULL );
    if( quadEdge1->GetDnext() || quadEdge1c->GetDnext( ) )
      {
      std::cerr << "Error 2 in GetDnext()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    quadEdge3->SetOnext( quadEdgeA );
#ifndef NDEBUG
    if( quadEdge1->GetDnext() || quadEdge1c->GetDnext( ) )
      {
      std::cerr << "Error 3 in GetDnext()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    quadEdgeA->SetRot( quadEdgeB );
    quadEdgeB->SetRot( quadEdgeC );
    quadEdgeC->SetRot( quadEdgeD );
    quadEdgeD->SetRot( quadEdgeA );

    if( quadEdge1->GetDnext() != quadEdgeC )
      {
      std::cerr << "Error 4 in GetDnext()" << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdge1c->GetDnext() != quadEdgeC )
      {
      std::cerr << "Error 5 in const GetDnext()" << std::endl;
      return EXIT_FAILURE;
      }

    delete quadEdge1;
    delete quadEdge2;
    delete quadEdge3;
    delete quadEdge4;

    delete quadEdgeA;
    delete quadEdgeB;
    delete quadEdgeC;
    delete quadEdgeD;

    std::cout << "GetDnext() Test passed ! " << std::endl;
    }


    // Tests for the GetOprev() methods
    // returns the previous edge with same origin
    // and same destination
    { // create a local scope for these tests
    QuadEdgeType * quadEdge1 = new QuadEdgeType;
    QuadEdgeType * quadEdge2 = new QuadEdgeType;
    QuadEdgeType * quadEdge3 = new QuadEdgeType;
    QuadEdgeType * quadEdge4 = new QuadEdgeType;

    QuadEdgeType * quadEdgeA = new QuadEdgeType;
    QuadEdgeType * quadEdgeB = new QuadEdgeType;
    QuadEdgeType * quadEdgeC = new QuadEdgeType;
    QuadEdgeType * quadEdgeD = new QuadEdgeType;

    const QuadEdgeType * quadEdge1c = quadEdge1;

#ifndef NDEBUG
    if( quadEdge1->GetOprev() || quadEdge1c->GetOprev( ) )
      {
      std::cerr << "Error in GetOprev()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    //
    //                        ^/^
    //                        /
    //                       / quadEdgeA
    //          Face        /
    //                     /
    //                    /
    //   <---------------O
    //       quadEdge1
    //

    quadEdge1->SetRot( quadEdge2 );
    quadEdge2->SetRot( quadEdge3 );
    quadEdge3->SetRot( quadEdge4 );
    quadEdge4->SetRot( quadEdge1 );

#ifndef NDEBUG
    quadEdge2->SetOnext( NULL );
    if( quadEdge1->GetOprev() || quadEdge1c->GetOprev( ) )
      {
      std::cerr << "Error in GetOprev()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    quadEdge2->SetOnext( quadEdgeD );
#ifndef NDEBUG
    if( quadEdge1->GetOprev() || quadEdge1c->GetOprev( ) )
      {
      std::cerr << "Error in GetOprev()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    quadEdgeA->SetRot( quadEdgeB );
    quadEdgeB->SetRot( quadEdgeC );
    quadEdgeC->SetRot( quadEdgeD );
    quadEdgeD->SetRot( quadEdgeA );

    if( quadEdge1->GetOprev() != quadEdgeA )
      {
      std::cerr << "Error in GetOprev()" << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdge1c->GetOprev() != quadEdgeA )
      {
      std::cerr << "Error in const GetOprev()" << std::endl;
      return EXIT_FAILURE;
      }

    delete quadEdge1;
    delete quadEdge2;
    delete quadEdge3;
    delete quadEdge4;

    delete quadEdgeA;
    delete quadEdgeB;
    delete quadEdgeC;
    delete quadEdgeD;

    std::cout << "GetOprev() Test passed ! " << std::endl;
    }


  // Tests for the GetLprev() methods
  // returns the previous edge with same left face
    { // create a local scope for these tests
    QuadEdgeType * quadEdge1 = new QuadEdgeType;
    QuadEdgeType * quadEdge2 = new QuadEdgeType;
    QuadEdgeType * quadEdge3 = new QuadEdgeType;
    QuadEdgeType * quadEdge4 = new QuadEdgeType;

    QuadEdgeType * quadEdgeA = new QuadEdgeType;
    QuadEdgeType * quadEdgeB = new QuadEdgeType;
    QuadEdgeType * quadEdgeC = new QuadEdgeType;
    QuadEdgeType * quadEdgeD = new QuadEdgeType;

    const QuadEdgeType * quadEdge1c = quadEdge1;

#ifndef NDEBUG
    quadEdge1->SetOnext( NULL );
    if( quadEdge1->GetLprev() || quadEdge1c->GetLprev( ) )
      {
      std::cerr << "Error in GetLprev()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    //
    //                        ^/^
    //                        /
    //                       / quadEdge1
    //          Face        /
    //                     /
    //                    /
    //   --------------->O
    //       quadEdgeA
    //

    quadEdge1->SetOnext( quadEdgeC );
#ifndef NDEBUG
    if( quadEdge1->GetLprev() || quadEdge1c->GetLprev( ) )
      {
      std::cerr << "Error in GetLprev()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    quadEdgeA->SetRot( quadEdgeB );
    quadEdgeB->SetRot( quadEdgeC );
    quadEdgeC->SetRot( quadEdgeD );
    quadEdgeD->SetRot( quadEdgeA );

    quadEdge1->SetRot( quadEdge2 );
    quadEdge2->SetRot( quadEdge3 );
    quadEdge3->SetRot( quadEdge4 );
    quadEdge4->SetRot( quadEdge1 );

    if( quadEdge1->GetLprev() != quadEdgeA )
      {
      std::cerr << "Error in GetLprev()" << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdge1c->GetLprev() != quadEdgeA )
      {
      std::cerr << "Error in const GetLprev()" << std::endl;
      return EXIT_FAILURE;
      }

    delete quadEdge1;
    delete quadEdge2;
    delete quadEdge3;
    delete quadEdge4;

    delete quadEdgeA;
    delete quadEdgeB;
    delete quadEdgeC;
    delete quadEdgeD;

    std::cout << "GetLprev() Test passed ! " << std::endl;
    }


    // Tests for the GetRprev() methods
    // returns the previous edge with same right face
    { // create a local scope for these tests
    QuadEdgeType * quadEdge1 = new QuadEdgeType;
    QuadEdgeType * quadEdge2 = new QuadEdgeType;
    QuadEdgeType * quadEdge3 = new QuadEdgeType;
    QuadEdgeType * quadEdge4 = new QuadEdgeType;

    QuadEdgeType * quadEdgeA = new QuadEdgeType;
    QuadEdgeType * quadEdgeB = new QuadEdgeType;
    QuadEdgeType * quadEdgeC = new QuadEdgeType;
    QuadEdgeType * quadEdgeD = new QuadEdgeType;

    const QuadEdgeType * quadEdge1c = quadEdge1;

#ifndef NDEBUG
    if( quadEdge1->GetRprev() || quadEdge1c->GetRprev( ) )
      {
      std::cerr << "Error in GetRprev()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    //
    //
    //
    //
    //     ???
    //
    //
    //
    //
    //

    quadEdge1->SetRot( quadEdge2 );
    quadEdge2->SetRot( quadEdge3 );
    quadEdge3->SetRot( quadEdge4 );
    quadEdge4->SetRot( quadEdge1 );

#ifndef NDEBUG
    quadEdge3->SetOnext( NULL );
    if( quadEdge1->GetRprev() || quadEdge1c->GetRprev( ) )
      {
      std::cerr << "Error in GetRprev()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    quadEdgeA->SetRot( quadEdgeB );
    quadEdgeB->SetRot( quadEdgeC );
    quadEdgeC->SetRot( quadEdgeD );
    quadEdgeD->SetRot( quadEdgeA );

    quadEdge3->SetOnext( quadEdgeA );

    if( quadEdge1->GetRprev() != quadEdgeA )
      {
      std::cerr << "Error in GetRprev()" << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdge1c->GetRprev() != quadEdgeA )
      {
      std::cerr << "Error in const GetRprev()" << std::endl;
      return EXIT_FAILURE;
      }

    delete quadEdge1;
    delete quadEdge2;
    delete quadEdge3;
    delete quadEdge4;

    delete quadEdgeA;
    delete quadEdgeB;
    delete quadEdgeC;
    delete quadEdgeD;

    std::cout << "GetRprev() Test passed ! " << std::endl;
    }


    // Tests for the GetDprev() methods
    // returns the previous edge with same right face
    // and same destination
    { // create a local scope for these tests
    QuadEdgeType * quadEdge1 = new QuadEdgeType;
    QuadEdgeType * quadEdge2 = new QuadEdgeType;
    QuadEdgeType * quadEdge3 = new QuadEdgeType;
    QuadEdgeType * quadEdge4 = new QuadEdgeType;

    QuadEdgeType * quadEdgeA = new QuadEdgeType;
    QuadEdgeType * quadEdgeB = new QuadEdgeType;
    QuadEdgeType * quadEdgeC = new QuadEdgeType;
    QuadEdgeType * quadEdgeD = new QuadEdgeType;

    const QuadEdgeType * quadEdge1c = quadEdge1;

#ifndef NDEBUG
    if( quadEdge1->GetDprev() || quadEdge1c->GetDprev( ) )
      {
      std::cerr << "Error in GetDprev()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    //                       |
    //                       |
    //                       |
    //                       | quadEdgeA
    //                       |
    //                       |
    //                       V
    //  -------------------> 0
    //      quadEdge1
    //

    quadEdge1->SetRot( quadEdge2 );
    quadEdge2->SetRot( quadEdge3 );
    quadEdge3->SetRot( quadEdge4 );
    quadEdge4->SetRot( quadEdge1 );

#ifndef NDEBUG
    quadEdge4->SetOnext( NULL );
    if( quadEdge1->GetDprev() || quadEdge1c->GetDprev( ) )
      {
      std::cerr << "Error in GetDprev()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    quadEdge4->SetOnext( quadEdgeB );
#ifndef NDEBUG
    if( quadEdge1->GetDprev() || quadEdge1c->GetDprev( ) )
      {
      std::cerr << "Error in GetDprev()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    quadEdgeA->SetRot( quadEdgeB );
    quadEdgeB->SetRot( quadEdgeC );
    quadEdgeC->SetRot( quadEdgeD );
    quadEdgeD->SetRot( quadEdgeA );

    if( quadEdge1->GetDprev() != quadEdgeA )
      {
      std::cerr << "Error in GetDprev()" << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdge1c->GetDprev() != quadEdgeA )
      {
      std::cerr << "Error in const GetDprev()" << std::endl;
      return EXIT_FAILURE;
      }

    delete quadEdge1;
    delete quadEdge2;
    delete quadEdge3;
    delete quadEdge4;

    delete quadEdgeA;
    delete quadEdgeB;
    delete quadEdgeC;
    delete quadEdgeD;

    std::cout << "GetDprev() Test passed ! " << std::endl;
    }

    // Tests for the GetInvRot() methods
    { // create a local scope for these tests
    QuadEdgeType * quadEdge1 = new QuadEdgeType;
    QuadEdgeType * quadEdge2 = new QuadEdgeType;
    QuadEdgeType * quadEdge3 = new QuadEdgeType;
    QuadEdgeType * quadEdge4 = new QuadEdgeType;

    const QuadEdgeType * quadEdge1c = quadEdge1;

#ifndef NDEBUG
    // Testing incomplete connections.
    if( quadEdge1->GetInvRot() || quadEdge1c->GetInvRot( ) )
      {
      std::cerr << "Error in GetInvRot()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    quadEdge1->SetRot( quadEdge2 );
#ifndef NDEBUG
    if( quadEdge1->GetInvRot() || quadEdge1c->GetInvRot( ) )
      {
      std::cerr << "Error in GetInvRot()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    quadEdge2->SetRot( quadEdge3 );
#ifndef NDEBUG
    if( quadEdge1->GetInvRot() || quadEdge1c->GetInvRot( ) )
      {
      std::cerr << "Error in GetInvRot()" << std::endl;
      return EXIT_FAILURE;
      }
#endif

    quadEdge3->SetRot( quadEdge4 );

    // Finally, the well constructed case
    quadEdge1->SetRot( quadEdge2 );
    quadEdge2->SetRot( quadEdge3 );
    quadEdge3->SetRot( quadEdge4 );
    quadEdge4->SetRot( quadEdge1 );

    if( quadEdge1->GetInvRot() != quadEdge4 )
      {
      std::cerr << "Error in GetInvRot()" << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdge1c->GetInvRot() != quadEdge4 )
      {
      std::cerr << "Error in const GetInvRot()" << std::endl;
      return EXIT_FAILURE;
      }

    delete quadEdge1;
    delete quadEdge2;
    delete quadEdge3;
    delete quadEdge4;

    std::cout << "GetInvRot() Test passed ! " << std::endl;
    }

    // Tests for the GetInvOnext() methods
    // returns the previous edge with same origin
    // and same destination
    { // create a local scope for these tests
    QuadEdgeType * quadEdge1 = new QuadEdgeType;
    QuadEdgeType * quadEdge2 = new QuadEdgeType;
    QuadEdgeType * quadEdge3 = new QuadEdgeType;
    QuadEdgeType * quadEdge4 = new QuadEdgeType;

    QuadEdgeType * quadEdgeA = new QuadEdgeType;
    QuadEdgeType * quadEdgeB = new QuadEdgeType;
    QuadEdgeType * quadEdgeC = new QuadEdgeType;
    QuadEdgeType * quadEdgeD = new QuadEdgeType;

    const QuadEdgeType * quadEdge1c = quadEdge1;

#ifndef NDEBUG
    quadEdge1->GetInvOnext(); // testing null case
#endif

    //
    //                        ^/^
    //                        /
    //                       / quadEdgeA
    //          Face        /
    //                     /
    //                    /
    //   <---------------O
    //       quadEdge1
    //

    quadEdgeA->SetRot( quadEdgeB );
    quadEdgeB->SetRot( quadEdgeC );
    quadEdgeC->SetRot( quadEdgeD );
    quadEdgeD->SetRot( quadEdgeA );

    quadEdge1->SetRot( quadEdge2 );
    quadEdge2->SetRot( quadEdge3 );
    quadEdge3->SetRot( quadEdge4 );
    quadEdge4->SetRot( quadEdge1 );

    quadEdge2->SetOnext( quadEdgeD ); // rely on this one
    quadEdgeA->SetOnext( quadEdge1 );

    if( quadEdge1->GetInvOnext() != quadEdgeA )
      {
      std::cerr << "Error in GetInvOnext()" << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdge1c->GetInvOnext() != quadEdgeA )
      {
      std::cerr << "Error in const GetInvOnext()" << std::endl;
      return EXIT_FAILURE;
      }

    delete quadEdge1;
    delete quadEdge2;
    delete quadEdge3;
    delete quadEdge4;

    delete quadEdgeA;
    delete quadEdgeB;
    delete quadEdgeC;
    delete quadEdgeD;

    std::cout << "GetInvOnext() Test passed ! " << std::endl;
    }

    // Tests for the GetInvLnext() methods
    // returns the previous edge with same left face
    { // create a local scope for these tests
    QuadEdgeType * quadEdge1 = new QuadEdgeType;
    QuadEdgeType * quadEdge2 = new QuadEdgeType;
    QuadEdgeType * quadEdge3 = new QuadEdgeType;
    QuadEdgeType * quadEdge4 = new QuadEdgeType;

    QuadEdgeType * quadEdgeA = new QuadEdgeType;
    QuadEdgeType * quadEdgeB = new QuadEdgeType;
    QuadEdgeType * quadEdgeC = new QuadEdgeType;
    QuadEdgeType * quadEdgeD = new QuadEdgeType;

    const QuadEdgeType * quadEdge1c = quadEdge1;

#ifndef NDEBUG
    quadEdge1->GetInvLnext(); // testing null case
#endif

    //
    //                        ^/^
    //                        /
    //                       / quadEdge1
    //          Face        /
    //                     /
    //                    /
    //   --------------->O
    //       quadEdgeA
    //

    quadEdgeA->SetRot( quadEdgeB );
    quadEdgeB->SetRot( quadEdgeC );
    quadEdgeC->SetRot( quadEdgeD );
    quadEdgeD->SetRot( quadEdgeA );

    quadEdge1->SetRot( quadEdge2 );
    quadEdge2->SetRot( quadEdge3 );
    quadEdge3->SetRot( quadEdge4 );
    quadEdge4->SetRot( quadEdge1 );

    quadEdge1->SetOnext( quadEdgeC );

    if( quadEdge1->GetInvLnext() != quadEdgeA )
      {
      std::cerr << "Error in GetInvLnext()" << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdge1c->GetInvLnext() != quadEdgeA )
      {
      std::cerr << "Error in const GetInvLnext()" << std::endl;
      return EXIT_FAILURE;
      }

    delete quadEdge1;
    delete quadEdge2;
    delete quadEdge3;
    delete quadEdge4;

    delete quadEdgeA;
    delete quadEdgeB;
    delete quadEdgeC;
    delete quadEdgeD;

    std::cout << "GetInvLnext() Test passed ! " << std::endl;
    }

    // Tests for the GetInvRnext() methods
    // returns the previous edge with same right face
    { // create a local scope for these tests
    QuadEdgeType * quadEdge1 = new QuadEdgeType;
    QuadEdgeType * quadEdge2 = new QuadEdgeType;
    QuadEdgeType * quadEdge3 = new QuadEdgeType;
    QuadEdgeType * quadEdge4 = new QuadEdgeType;

    QuadEdgeType * quadEdgeA = new QuadEdgeType;
    QuadEdgeType * quadEdgeB = new QuadEdgeType;
    QuadEdgeType * quadEdgeC = new QuadEdgeType;
    QuadEdgeType * quadEdgeD = new QuadEdgeType;

    const QuadEdgeType * quadEdge1c = quadEdge1;

#ifndef NDEBUG
    quadEdge1->GetInvRnext(); // testing null case
#endif

    //
    //
    //
    //
    //     ???
    //
    //
    //
    //
    //

    quadEdgeA->SetRot( quadEdgeB );
    quadEdgeB->SetRot( quadEdgeC );
    quadEdgeC->SetRot( quadEdgeD );
    quadEdgeD->SetRot( quadEdgeA );

    quadEdge1->SetRot( quadEdge2 );
    quadEdge2->SetRot( quadEdge3 );
    quadEdge3->SetRot( quadEdge4 );
    quadEdge4->SetRot( quadEdge1 );

    quadEdge3->SetOnext( quadEdgeA );

    if( quadEdge1->GetInvRnext() != quadEdgeA )
      {
      std::cerr << "Error in GetInvRnext()" << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdge1c->GetInvRnext() != quadEdgeA )
      {
      std::cerr << "Error in const GetInvRnext()" << std::endl;
      return EXIT_FAILURE;
      }

    delete quadEdge1;
    delete quadEdge2;
    delete quadEdge3;
    delete quadEdge4;

    delete quadEdgeA;
    delete quadEdgeB;
    delete quadEdgeC;
    delete quadEdgeD;

    std::cout << "GetInvRnext() Test passed ! " << std::endl;
    }

    // Tests for the GetInvDnext() methods
    // returns the previous edge with same right face
    // and same destination
    { // create a local scope for these tests
    QuadEdgeType * quadEdge1 = new QuadEdgeType;
    QuadEdgeType * quadEdge2 = new QuadEdgeType;
    QuadEdgeType * quadEdge3 = new QuadEdgeType;
    QuadEdgeType * quadEdge4 = new QuadEdgeType;

    QuadEdgeType * quadEdgeA = new QuadEdgeType;
    QuadEdgeType * quadEdgeB = new QuadEdgeType;
    QuadEdgeType * quadEdgeC = new QuadEdgeType;
    QuadEdgeType * quadEdgeD = new QuadEdgeType;

    const QuadEdgeType * quadEdge1c = quadEdge1;

#ifndef NDEBUG
    quadEdge1->GetInvDnext(); // testing null case
#endif

    //                       |
    //                       |
    //                       |
    //                       | quadEdgeA
    //                       |
    //                       |
    //                       V
    //  -------------------> 0
    //      quadEdge1
    //

    quadEdgeA->SetRot( quadEdgeB );
    quadEdgeB->SetRot( quadEdgeC );
    quadEdgeC->SetRot( quadEdgeD );
    quadEdgeD->SetRot( quadEdgeA );

    quadEdge1->SetRot( quadEdge2 );
    quadEdge2->SetRot( quadEdge3 );
    quadEdge3->SetRot( quadEdge4 );
    quadEdge4->SetRot( quadEdge1 );

    quadEdge4->SetOnext( quadEdgeB );

    if( quadEdge1->GetInvDnext() != quadEdgeA )
      {
      std::cerr << "Error in GetInvDnext()" << std::endl;
      return EXIT_FAILURE;
      }

    if( quadEdge1c->GetInvDnext() != quadEdgeA )
      {
      std::cerr << "Error in const GetInvDnext()" << std::endl;
      return EXIT_FAILURE;
      }

    delete quadEdge1;
    delete quadEdge2;
    delete quadEdge3;
    delete quadEdge4;

    delete quadEdgeA;
    delete quadEdgeB;
    delete quadEdgeC;
    delete quadEdgeD;

    std::cout << "GetInvDnext() Test passed ! " << std::endl;
    }


    // Tests for the IsHalfEdge() method
    { // create a local scope for these tests
    QuadEdgeType * quadEdge1 = new QuadEdgeType;
    QuadEdgeType * quadEdge2 = new QuadEdgeType;
    QuadEdgeType * quadEdgeA = new QuadEdgeType;

    const QuadEdgeType * quadEdge1c = quadEdge1;

    if( quadEdge1c->IsHalfEdge() != true )
      {
      std::cerr << "Error in IsHalfEdge() A" << std::endl;
      return EXIT_FAILURE;
      }

    quadEdge1->SetRot( quadEdge2 );

    if( quadEdge1c->IsHalfEdge() != true )
      {
      std::cerr << "Error in IsHalfEdge() B" << std::endl;
      return EXIT_FAILURE;
      }

    quadEdge1->SetOnext( quadEdgeA );

    if( quadEdge1c->IsHalfEdge() != false )
      {
      std::cerr << "Error in IsHalfEdge() C" << std::endl;
      return EXIT_FAILURE;
      }

    quadEdge1->SetRot( NULL );

    if( quadEdge1c->IsHalfEdge() != true )
      {
      std::cerr << "Error in IsHalfEdge() D" << std::endl;
      return EXIT_FAILURE;
      }

    delete quadEdge1;
    delete quadEdge2;
    delete quadEdgeA;

    std::cout << "IsHalfEdge() Test passed ! " << std::endl;
    }

    // Tests for the IsIsolated() method
    { // create a local scope for these tests
    QuadEdgeType * quadEdge1 = new QuadEdgeType;
    QuadEdgeType * quadEdge2 = new QuadEdgeType;

    const QuadEdgeType * quadEdge1c = quadEdge1;

    if( quadEdge1c->IsIsolated() != true )
      {
      std::cerr << "Error in IsIsolated() A" << std::endl;
      return EXIT_FAILURE;
      }

    quadEdge1->SetOnext( quadEdge2 );

    if( quadEdge1c->IsIsolated() != false )
      {
      std::cerr << "Error in IsIsolated() B" << std::endl;
      return EXIT_FAILURE;
      }

    quadEdge1->SetOnext( quadEdge1 );

    if( quadEdge1c->IsIsolated() != true )
      {
      std::cerr << "Error in IsIsolated() C" << std::endl;
      return EXIT_FAILURE;
      }

    delete quadEdge1;
    delete quadEdge2;

    std::cout << "IsIsolated() Test passed ! " << std::endl;
    }

    // Tests for the IsEdgeInOnextRing() method
    { // create a local scope for these tests
    QuadEdgeType * quadEdge1 = new QuadEdgeType;
    QuadEdgeType * quadEdge2 = new QuadEdgeType;
    QuadEdgeType * quadEdge3 = new QuadEdgeType;
    QuadEdgeType * quadEdge4 = new QuadEdgeType;
    QuadEdgeType * quadEdge5 = new QuadEdgeType;
    QuadEdgeType * quadEdge6 = new QuadEdgeType;

    const QuadEdgeType * quadEdge1c = quadEdge1;

    quadEdge1->SetOnext( NULL );
    quadEdge1c->IsEdgeInOnextRing( NULL );

    if( quadEdge1c->IsEdgeInOnextRing( quadEdge6 ) == true )
      {
      std::cerr << "Error in IsEdgeInOnextRing() A" << std::endl;
      return EXIT_FAILURE;
      }

    // Create a ring
    quadEdge1->SetOnext( quadEdge2 );
    quadEdge2->SetOnext( quadEdge3 );
    quadEdge3->SetOnext( quadEdge4 );
    quadEdge4->SetOnext( quadEdge5 );
    quadEdge5->SetOnext( quadEdge1 );

    if( quadEdge1c->IsEdgeInOnextRing( quadEdge6 ) == true )
      {
      std::cerr << "Error in IsEdgeInOnextRing() B" << std::endl;
      return EXIT_FAILURE;
      }

    // Close the ring by adding
    quadEdge5->SetOnext( quadEdge6 );
    quadEdge6->SetOnext( quadEdge1 );

    if( quadEdge1c->IsEdgeInOnextRing( quadEdge6 ) == false )
      {
      std::cerr << "Error in IsEdgeInOnextRing() C" << std::endl;
      return EXIT_FAILURE;
      }

    delete quadEdge1;
    delete quadEdge2;
    delete quadEdge3;
    delete quadEdge4;
    delete quadEdge5;
    delete quadEdge6;

    std::cout << "IsEdgeInOnextRing() Test passed ! " << std::endl;
    } // end of local scope for tests

    // Tests for the IsLnextGivenSizeCyclic() method
    { // create a local scope for these tests
    //                                           //
    //                                           //
    // Create quad-edges on the three physical   //
    // edges (A,B,C) of a triangular face        //
    //                                           //
    //                                           //
    //                   /\                      //
    //                  /  \                     //
    //                 /    \                    //
    //                /      \                   //
    //           B   /        \  A               //
    //              /          \                 //
    //             /            \                //
    //            /              \               //
    //           /                \              //
    //           ------------------              //
    //                   C   quadEdgeC1-->       //
    //                                           //
    //                                           //
    QuadEdgeType * quadEdgeA1 = new QuadEdgeType;
    QuadEdgeType * quadEdgeA2 = new QuadEdgeType;
    QuadEdgeType * quadEdgeA3 = new QuadEdgeType;
    QuadEdgeType * quadEdgeA4 = new QuadEdgeType;

    QuadEdgeType * quadEdgeB1 = new QuadEdgeType;
    QuadEdgeType * quadEdgeB2 = new QuadEdgeType;
    QuadEdgeType * quadEdgeB3 = new QuadEdgeType;
    QuadEdgeType * quadEdgeB4 = new QuadEdgeType;

    QuadEdgeType * quadEdgeC1 = new QuadEdgeType;
    QuadEdgeType * quadEdgeC2 = new QuadEdgeType;
    QuadEdgeType * quadEdgeC3 = new QuadEdgeType;
    QuadEdgeType * quadEdgeC4 = new QuadEdgeType;

    const QuadEdgeType * quadEdgeA1c = quadEdgeA1;
    const QuadEdgeType * quadEdgeB1c = quadEdgeB1;
    const QuadEdgeType * quadEdgeC1c = quadEdgeC1;
    const QuadEdgeType * quadEdgeA4c = quadEdgeA4;

#ifndef NDEBUG
    quadEdgeA1c->IsLnextGivenSizeCyclic( 3 ); // testing null case

    if( quadEdgeA1c->IsLnextGivenSizeCyclic( 3 ) == true )
      {
      std::cerr << "Error in IsLnextGivenSizeCyclic() A" << std::endl;
      return EXIT_FAILURE;
      }
#endif


    // Connect quad-edges inside physical edge A
    quadEdgeA1->SetRot( quadEdgeA2 );
    quadEdgeA2->SetRot( quadEdgeA3 );
    quadEdgeA3->SetRot( quadEdgeA4 );
    quadEdgeA4->SetRot( quadEdgeA1 );

    // Connect quad-edges inside physical edge B
    quadEdgeB1->SetRot( quadEdgeB2 );
    quadEdgeB2->SetRot( quadEdgeB3 );
    quadEdgeB3->SetRot( quadEdgeB4 );
    quadEdgeB4->SetRot( quadEdgeB1 );

    // Connect quad-edges inside physical edge C
    quadEdgeC1->SetRot( quadEdgeC2 );
    quadEdgeC2->SetRot( quadEdgeC3 );
    quadEdgeC3->SetRot( quadEdgeC4 );
    quadEdgeC4->SetRot( quadEdgeC1 );

    // PRIMAL ORING
    // connect Orings of Top point
    quadEdgeA3->SetOnext( quadEdgeB1 );
    quadEdgeB1->SetOnext( quadEdgeA3 );

    // connect Oring of bottom left point
    quadEdgeB3->SetOnext( quadEdgeC1 );
    quadEdgeC1->SetOnext( quadEdgeB3 );

    // connect Oring of bottom right point
    quadEdgeC3->SetOnext( quadEdgeA1 );
    quadEdgeA1->SetOnext( quadEdgeC3 );

    // DUAL ORING (FACE)
    // triangle
    quadEdgeA4->SetOnext( quadEdgeB4 );
    quadEdgeB4->SetOnext( quadEdgeC4 );
    quadEdgeC4->SetOnext( quadEdgeA4 );

    // outside
    quadEdgeA2->SetOnext( quadEdgeC2 );
    quadEdgeC2->SetOnext( quadEdgeB2 );
    quadEdgeB2->SetOnext( quadEdgeA2 );

    const unsigned int quadEdgeA1Order = quadEdgeA1c->GetOrder();
    const unsigned int quadEdgeA1ExpectedOrder = 2;
    if( quadEdgeA1Order  != quadEdgeA1ExpectedOrder )
      {
      std::cerr << "Error in GetOrder() A" << std::endl;
      std::cerr << "Expected " << quadEdgeA1ExpectedOrder;
      std::cerr << ", but got " << quadEdgeA1Order << std::endl;
      return EXIT_FAILURE;
      }

    const unsigned int quadEdgeB1Order = quadEdgeB1c->GetOrder();
    const unsigned int quadEdgeB1ExpectedOrder = 2;
    if( quadEdgeB1Order  != quadEdgeB1ExpectedOrder )
      {
      std::cerr << "Error in GetOrder() B" << std::endl;
      std::cerr << "Expected " << quadEdgeB1ExpectedOrder;
      std::cerr << ", but got " << quadEdgeB1Order << std::endl;
      return EXIT_FAILURE;
      }

    const unsigned int quadEdgeC1Order = quadEdgeC1c->GetOrder();
    const unsigned int quadEdgeC1ExpectedOrder = 2;
    if( quadEdgeC1Order  != quadEdgeC1ExpectedOrder )
      {
      std::cerr << "Error in GetOrder() C" << std::endl;
      std::cerr << "Expected " << quadEdgeC1ExpectedOrder;
      std::cerr << ", but got " << quadEdgeC1Order << std::endl;
      return EXIT_FAILURE;
      }

    const unsigned int quadEdgeA4Order = quadEdgeA4c->GetOrder();
    const unsigned int quadEdgeA4ExpectedOrder = 3;
    if( quadEdgeA4Order  != quadEdgeA4ExpectedOrder )
      {
      std::cerr << "Error in GetOrder() D" << std::endl;
      std::cerr << "Expected " << quadEdgeA4ExpectedOrder;
      std::cerr << ", but got " << quadEdgeA4Order << std::endl;
      return EXIT_FAILURE;
      }

    // Check with the right period
    if( quadEdgeA1c->IsLnextGivenSizeCyclic( 3 ) == false )
      {
      std::cerr << "Error in IsLnextGivenSizeCyclic() B" << std::endl;
      return EXIT_FAILURE;
      }

    // Check a wrong period on purpose
    if( quadEdgeA1c->IsLnextGivenSizeCyclic( 4 ) == true )
      {
      std::cerr << "Error in IsLnextGivenSizeCyclic() C" << std::endl;
      return EXIT_FAILURE;
      }

    delete quadEdgeA1;
    delete quadEdgeA2;
    delete quadEdgeA3;
    delete quadEdgeA4;

    delete quadEdgeB1;
    delete quadEdgeB2;
    delete quadEdgeB3;
    delete quadEdgeB4;

    delete quadEdgeC1;
    delete quadEdgeC2;
    delete quadEdgeC3;
    delete quadEdgeC4;

    std::cout << "IsLnextGivenSizeCyclic() Test passed ! " << std::endl;
    } // end of local scope for tests

  std::cout << "QuadEdge Test Passed !" << std::endl;

  return EXIT_SUCCESS;
}
