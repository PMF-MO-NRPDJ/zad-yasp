#ifdef HAVE_CONFIG_H
# include "config.h"
#endif
#include <iostream>
#include <dune/common/parallel/mpihelper.hh> 
#include <dune/common/exceptions.hh> 

#include <dune/grid/yaspgrid.hh>         // Koristimo YaspGrid
#include <dune/grid/common/gridinfo.hh>  // za funkciju gridinfo()
#include <dune/grid/io/file/vtk.hh>      // za VTKWriter

#include <array>
#include <bitset>
#include <vector>
#include <cassert>



int main(int argc, char** argv)
{
    // Inicijalizacija MPI podsistema je obavezna. 
    Dune::MPIHelper& helper = Dune::MPIHelper::instance(argc, argv);
    if(Dune::MPIHelper::isFake)
      std::cout<< "This is a sequential program." << std::endl;
    else
      std::cout<<"I am rank "<<helper.rank()<<" of "<<helper.size()
        <<" processes!"<<std::endl;


    const int dim = 2;
    // Na neuniformnoj mreži YaspGrid ima dodatni parametar TensorProductCoordinates
    using GridType = Dune::YaspGrid<dim, Dune::TensorProductCoordinates<double,dim> >;
    using GridView = GridType::LeafGridView;

    std::array<std::vector<double>,dim> coords;
    // Ovdje konstruiraj koordinate koje ćeš predati konstruktoru
    // YaspGrid-a
    
    // Konstrukcija grida 
    GridType grid(coords);

    Dune::gridinfo(grid);
    Dune::VTKWriter<GridView> writer(grid.leafGridView()); // Ispis mreže u
    writer.write("nonu_yasp");                             // datoteku 

    return 0;
}
