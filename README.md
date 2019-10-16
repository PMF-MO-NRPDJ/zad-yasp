**Zadatak 1**.
Konstruirati paralelnu YaspGrid mrežu. Paralelna mreža se 
razlikuje od serijske po tome što uzima *komunikator* kao argument 
(proučite konstruktore u dokumentaciji YaspGrid klase). 

Izvršite program na dva procesora (naredbom `mpirun -np 2 par`). 
Kakva je razlika u ispisu? Promijenite dimenziju mreže sa 2 na 3 i 
izvršite program. Proučite ispis programa. Izvedite zatim programa 
na 4 procesora. Svaki procesor treba dobiti podjednak komad mreže. 
Uočite razliku u VTK zapisu paralelne mreže. Paralelna se mreža zapisuje
"po procesorima".

*Uputa*. Mi smo do sada koristili konstruktor `YaspGrid` klase koji uzima 
4 parametra ([konstruktor](https://dune-project.org/doxygen/2.6.0/classDune_1_1YaspGrid.html#ac82601a2bb3342dc2890c0ca81f97534)). 
Kada se pogleda taj konstruktor vidi se da on uzima 6 parametara, ali da su obavezna
samo prva dva dok svi ostali imaju dodijeljene vrijednosti. Ako želimo paralelnu mrežu 
trebamo eksplicitno zadati peti parametar -- komuniktor. Komunikator dobivamo kao 
povratnu vrijednost metode `Dune::MPIHelper::instance(argc, argv)` koju uvijek pozivamo
na početku programa,
ali ponekad zanemarujemo njenu povratnu vrijednost. Kada konstruiramo paralelnu mrežu
moramo uzeti referencu na povratnu vrijednost, a to je traženi komunikator koji predajemo
konstruktoru. 

Program se izvršava paralelno pomoću skripte `mpirun`. S opcijom `-np` zadajemo broj 
procesa koji želimo koristiti. 


**Zadatak 2**. 
Konstruirajte neuniformnu YaspGrid mrežu na kvadratu (-1,1)x(-1,1).
Korak mreže u x-smjeru mora biti za x = -1 jednak h=0.01, a za x=0 mora približno iznositi  h=0.1.
Između x=-1 i x=0 korak mreže linearno raste. Od x=0 do x=1 korak linearno
pada tako da za x=1 ponovo iznosi h=0.01.
Korak mreže se jednako ponaša i u y-smjeru. Koristiti odgovarajući 
konstruktor YaspGrid klase. 

*Uputa*. Vidjeli smo da `YaspGrid` uzima samo jedan template parametar i to je
dimenzija mreže. Ustvari, mreža uzima dva template parametra, ali drugi parametar ima 
dodijeljenu vrijednost. Taj se drugi parametar naziva 
`Coordinates` i njemu je pridružena vrijednost `Dune::EquidistantCoordinates<double, dim>`.
Mreža konstruirana s dodijeljenim parametrom je ekvidistantna, odnosno prostorni 
korak u svakom koordinatnom smjeru je konstantan. Ako želimo da raspored točaka 
u smjeru koordinatnih osi ne bude konstantan trebamo  umesto dodijeljenog 
parametra koristiti `Dune::TensorProductCoordinates<double, dim>`. Tada se može 
koristiti 
[konstruktor](https://dune-project.org/doxygen/2.6.0/classDune_1_1YaspGrid.html#a1944d699ac40a2246b2a8a787181d4c6)
koji uzima kao prvi argument `std::array< std::vector<double>, dim > coords`, 
u kojem se za svaku koordinatnu os zadaje niz točaka mreže. 
 

