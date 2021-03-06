IF( NOT ITK_DISABLE_CXX_TESTING )
IF(ITK_BINARY_DIR)
  IF(TCL_TCLSH)
    ADD_TEST(PrintSelf-FEM ${TCL_TCLSH}
             ${ITK_SOURCE_DIR}/Utilities/Dart/PrintSelfCheck.tcl  
             ${ITK_SOURCE_DIR}/Code/Numerics/FEM)
  ENDIF(TCL_TCLSH)
ENDIF(ITK_BINARY_DIR)



SET(FEM_TESTS ${CXX_TEST_PATH}/itkFEMTests)
SET(FEM_TESTS2 ${CXX_TEST_PATH}/itkFEMTests2)

SET(FEM_SRCS
itkFEMElementTest.cxx
itkFEMExceptionTest.cxx
itkFEMGenerateMeshTest.cxx
itkFEMElement2DMembraneTest.cxx
itkFEMElement3DMembraneTest.cxx
itkFEMElement2DStrainTest.cxx
)
SET(FEM_SRCS2
itkFEMElement2DQuadraticTriangularTest.cxx
itkFEMLinearSystemWrapperItpackTest.cxx
itkFEMLinearSystemWrapperItpackTest2.cxx
itkFEMLinearSystemWrapperVNLTest.cxx
itkFEMLinearSystemWrapperDenseVNLTest.cxx
itkFEMPArrayTest.cxx
)

ADD_TEST(itkFEMC0HexahedralElement-NodalLoads-BCs ${FEM_TESTS} itkFEMElementTest ${ITK_DATA_ROOT}/Input/FEM/hexa2.fem)
ADD_TEST(itkFEMC0HexahedralElement-NoLoads ${FEM_TESTS} itkFEMElementTest ${ITK_DATA_ROOT}/Input/FEM/hexa3.fem)
ADD_TEST(itkFEMC0HexahedralElement-GravityLoad-BCs ${FEM_TESTS} itkFEMElementTest ${ITK_DATA_ROOT}/Input/FEM/hexa4-grav.fem)
ADD_TEST(itkFEMC0QuadElement-NodalLoads-BCs ${FEM_TESTS} itkFEMElementTest ${ITK_DATA_ROOT}/Input/FEM/quad2-small.fem)
ADD_TEST(itkFEMC0QuadElement-Strain ${FEM_TESTS} itkFEMElementTest ${ITK_DATA_ROOT}/Input/FEM/quad2-strain.fem)
ADD_TEST(itkFEMC0QuadElement-NoLoads ${FEM_TESTS} itkFEMElementTest ${ITK_DATA_ROOT}/Input/FEM/quad4.fem)
ADD_TEST(itkFEMC0QuadElement-GravityLoad-BCs ${FEM_TESTS} itkFEMElementTest ${ITK_DATA_ROOT}/Input/FEM/quad6-grav.fem)
ADD_TEST(itkFEMLoadLandmarkImplementation ${FEM_TESTS} itkFEMElementTest ${ITK_DATA_ROOT}/Input/FEM/quad-lm.fem)

# Edge loads are not re-implemented yet
#ADD_TEST(itkFEMC0QuadElement-EdgeLoad-BCs ${FEM_TESTS} itkFEMElementTest ${ITK_DATA_ROOT}/Input/FEM/quad_1_edge.fem)

ADD_TEST(itkFEMC0TetrahedralElement-NodalLoads-BCs ${FEM_TESTS} itkFEMElementTest ${ITK_DATA_ROOT}/Input/FEM/tetra2.fem)
ADD_TEST(itkFEMC0TetrahedralElement-NoLoads ${FEM_TESTS} itkFEMElementTest ${ITK_DATA_ROOT}/Input/FEM/tetra3.fem)
ADD_TEST(itkFEMC0TetrahedralElement-GravityLoad-BCs ${FEM_TESTS} itkFEMElementTest ${ITK_DATA_ROOT}/Input/FEM/tetra4-grav.fem)
ADD_TEST(itkFEMC0QuadElementTrapezoidalGeometry-NoLoads ${FEM_TESTS} itkFEMElementTest ${ITK_DATA_ROOT}/Input/FEM/trapezoid.fem)
ADD_TEST(itkFEMC0TriangularElement-NodalLoads-BCs ${FEM_TESTS} itkFEMElementTest ${ITK_DATA_ROOT}/Input/FEM/tri2.fem)
ADD_TEST(itkFEMC0TriangularElement-NoLoads ${FEM_TESTS} itkFEMElementTest ${ITK_DATA_ROOT}/Input/FEM/tri3.fem)
ADD_TEST(itkFEMC0TriangularElement-Strain ${FEM_TESTS} itkFEMElementTest ${ITK_DATA_ROOT}/Input/FEM/tri3-e.fem)
ADD_TEST(itkFEMC0TriangularElement-Quadratic ${FEM_TESTS} itkFEMElementTest ${ITK_DATA_ROOT}/Input/FEM/tri3-q.fem)
ADD_TEST(itkFEMTruss ${FEM_TESTS} itkFEMElementTest ${ITK_DATA_ROOT}/Input/FEM/truss.fem)

ADD_TEST(itkFEMLinearSystemWrapperItpackTest  ${FEM_TESTS2} itkFEMLinearSystemWrapperItpackTest)

ADD_TEST(itkFEMLinearSystemWrapperItpackTest1  ${FEM_TESTS2} itkFEMLinearSystemWrapperItpackTest 0 )
ADD_TEST(itkFEMLinearSystemWrapperItpackTest2  ${FEM_TESTS2} itkFEMLinearSystemWrapperItpackTest 1 )
ADD_TEST(itkFEMLinearSystemWrapperItpackTest3  ${FEM_TESTS2} itkFEMLinearSystemWrapperItpackTest 2 )
ADD_TEST(itkFEMLinearSystemWrapperItpackTest4  ${FEM_TESTS2} itkFEMLinearSystemWrapperItpackTest 3 )
ADD_TEST(itkFEMLinearSystemWrapperItpackTest5  ${FEM_TESTS2} itkFEMLinearSystemWrapperItpackTest 4 )
ADD_TEST(itkFEMLinearSystemWrapperItpackTest6  ${FEM_TESTS2} itkFEMLinearSystemWrapperItpackTest 5 )
ADD_TEST(itkFEMLinearSystemWrapperItpackTest7  ${FEM_TESTS2} itkFEMLinearSystemWrapperItpackTest 6 )

ADD_TEST(itkFEMLinearSystemWrapperItpackTest8   ${FEM_TESTS2} itkFEMLinearSystemWrapperItpackTest2 0 )
ADD_TEST(itkFEMLinearSystemWrapperItpackTest9   ${FEM_TESTS2} itkFEMLinearSystemWrapperItpackTest2 1 )
ADD_TEST(itkFEMLinearSystemWrapperItpackTest10  ${FEM_TESTS2} itkFEMLinearSystemWrapperItpackTest2 2 )
ADD_TEST(itkFEMLinearSystemWrapperItpackTest11  ${FEM_TESTS2} itkFEMLinearSystemWrapperItpackTest2 3 )
ADD_TEST(itkFEMLinearSystemWrapperItpackTest12  ${FEM_TESTS2} itkFEMLinearSystemWrapperItpackTest2 4 )
ADD_TEST(itkFEMLinearSystemWrapperItpackTest13  ${FEM_TESTS2} itkFEMLinearSystemWrapperItpackTest2 5 )
ADD_TEST(itkFEMLinearSystemWrapperItpackTest14  ${FEM_TESTS2} itkFEMLinearSystemWrapperItpackTest2 6 )

ADD_TEST(itkFEMLinearSystemWrapperVNLTest  ${FEM_TESTS2} itkFEMLinearSystemWrapperVNLTest)
ADD_TEST(itkFEMLinearSystemWrapperDenseVNLTest  ${FEM_TESTS2} itkFEMLinearSystemWrapperDenseVNLTest)
ADD_TEST(itkFEMPArrayTest  ${FEM_TESTS2} itkFEMPArrayTest)

ADD_TEST(itkFEMExceptionTest ${FEM_TESTS} itkFEMExceptionTest)
ADD_TEST(itkFEMGenerateMeshTest ${FEM_TESTS} itkFEMGenerateMeshTest)
ADD_TEST(itkFEMElement2DMembraneTest ${FEM_TESTS} itkFEMElement2DMembraneTest)
ADD_TEST(itkFEMElement3DMembraneTest ${FEM_TESTS} itkFEMElement3DMembraneTest)
ADD_TEST(itkFEMElement2DStrainTest ${FEM_TESTS} itkFEMElement2DStrainTest)
ADD_TEST(itkFEMElement2DQuadraticTriangularTest ${FEM_TESTS2} itkFEMElement2DQuadraticTriangularTest)

#ADD_TEST(itkFEMBar2DTest ${FEM_TESTS} itkFEMBar2DTest)

# NOTE: the two commands below are mutually exclusive!  Do not
# uncomment both at the same time!

# To run the FEM input menu-based test locally, uncomment the line below
#ADD_EXECUTABLE(itkFEMElementTestMenu itkFEMElementTest.cxx)
#TARGET_LINK_LIBRARIES(itkFEMElementTestMenu ITKNumerics ITKFEM)
#ADD_EXECUTABLE(itkFEMExceptionTest itkFEMExceptionTest.cxx)
#TARGET_LINK_LIBRARIES(itkFEMExceptionTest ITKFEM)
#ADD_EXECUTABLE(itkFEMGenerateMeshTest itkFEMGenerateMeshTest.cxx)
#TARGET_LINK_LIBRARIES(itkFEMGenerateMeshTest ITKNumerics ITKFEM)
#ADD_EXECUTABLE(itkFEMElement2DQuadraticTriangularTest itkFEMElement2DQuadraticTriangularTest.cxx)
#TARGET_LINK_LIBRARIES(itkFEMElement2DQuadraticTriangularTest ITKNumerics ITKFEM)

# To create the standard ITK test program, uncomment the line below
ADD_EXECUTABLE(itkFEMTests itkFEMTests.cxx ${FEM_SRCS})
IF(UNIX)
  TARGET_LINK_LIBRARIES (itkFEMTests -lm )
ENDIF(UNIX)
TARGET_LINK_LIBRARIES(itkFEMTests ITKNumerics ITKFEM)

ADD_EXECUTABLE(itkFEMTests2 itkFEMTests2.cxx ${FEM_SRCS2})
IF(UNIX)
  TARGET_LINK_LIBRARIES (itkFEMTests2 -lm )
ENDIF(UNIX)
TARGET_LINK_LIBRARIES(itkFEMTests2 ITKNumerics ITKFEM)




ENDIF( NOT ITK_DISABLE_CXX_TESTING )



