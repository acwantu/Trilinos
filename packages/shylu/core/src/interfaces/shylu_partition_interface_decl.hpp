#ifndef SHYLU_PARTITION_INTERFACE_DECL_HPP
#define SHYLU_PARTITION_INTERFACE_DECL_HPP

#include "ShyLUCore_config.h"

//shylu
#include <shylu.h>
#include <shylu_util.h>

//Epetra
#include <Epetra_CrsMatrix.h>
#include <Epetra_MultiVector.h>
#include <Epetra_Vector.h>
#include <Epetra_Map.h>

//Isorropia
#include <Isorropia_config.h>
#include <Isorropia_Epetra.hpp>
#include <Isorropia_EpetraProber.hpp>
#include <Isorropia_EpetraPartitioner.hpp>
#include <Isorropia_EpetraRedistributor.hpp>

//Tperta
#ifdef HAVE_SHYLU_TPETRA
#include <Tpetra_CrsMatrix_decl.hpp>
#include <Tpetra_CrsMatrix_def.hpp>
#endif

//#include <Zoltan2_config.h>
#ifdef HAVE_SHYLU_ZOLTAN2
#include <Zoltan2_XpetraCrsMatrixAdapter.hpp>
#include <Zoltan2_XpetraMultiVectorAdapter.hpp>
#include <Zoltan2_PartitioningProblem.hpp>
#endif

#include <Teuchos_XMLParameterListHelpers.hpp>


namespace ShyLU{

template <class Matrix, class Vector>
class PartitionInterface
{

public:
  ~PartitionInterface();
  PartitionInterface(Matrix* inA, Teuchos::ParameterList* pList);
  int partition();
  Matrix* reorderMatrix();
  Vector* reorderVector(Vector* x);

private:
  int partitionIsorropia();
  Teuchos::ParameterList* pList;
  Matrix* A;
  ///other handlers needed by zoltan2 and isorropia
#ifdef HAVE_SHYLU_ZOLTAN2
  int partitionZoltan2();
  Zoltan2::XpetraCrsMatrixAdapter<Matrix,Vector> *zadapter;
  Zoltan2::PartitioningProblem<Zoltan2::XpetraCrsMatrixAdapter<Matrix,Vector> > *zproblem;
#endif
  Isorropia::Epetra::Partitioner *ipart;
  Isorropia::Epetra::Redistributor *ird;


};

}// end namespace ShyLU

#endif



