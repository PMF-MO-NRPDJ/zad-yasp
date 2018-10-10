#ifdef HAVE_CONFIG_H
# include "config.h"
#endif
#include <iostream>
#include <dune/common/parallel/mpihelper.hh> 

#include <dune/grid/yaspgrid.hh>         // Koristimo YaspGrid
#include <dune/grid/common/gridinfo.hh>  // za funkciju gridinfo()
#include <dune/grid/io/file/vtk.hh>      // za VTKWriter

#include <array>
#include <bitset>

int main(int argc, char** argv)
{
    // Inicijalizacija MPI podsistema je obavezna.  Uzimamo referencu na helper.
    Dune::MPIHelper& helper = Dune::MPIHelper::instance(argc, argv);
    if(Dune::MPIHelper::isFake)
      std::cout<< "This is a sequential program." << std::endl;
    else
      std::cout<<"I am rank "<<helper.rank()<<" of "<<helper.size()
        <<" processes!"<<std::endl;


    // MPI komunikator. Potreban je u pralelnim programima
    Dune::MPIHelper::MPICommunicator const &  comm = helper.getCommunicator();

    const int dim = 2;  // dimenzija mreže
    using GridType = Dune::YaspGrid<dim>;
    using GridView = GridType::LeafGridView;

//  Ovdje treba konstruirati paralelnu mrežu... 
//  GridType grid(...);

    Dune::gridinfo(grid);
    Dune::VTKWriter<GridView> writer(grid.leafGridView()); // Ispis mreže u
    writer.write("par_yasp");                              // datoteku 

    return 0;
}
