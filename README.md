*Zadatak 1*.
Konstruirati paralelnu YaspGrid mrežu. Paralelna mreža se 
razlikuje od serijske po tome što uzima komunikator kao argument 
(proučite konstruktore u dokumentaciji YaspGrid klase). 

Izvršite program na dva procesora (naredbom `mpirun -np 2 par`). 
Kakva je razlika u ispisu? Promijenite dimenziju mreže sa 2 na 3 i 
izvršite program. Proučite ispis programa. Izvedite zatim programa 
na 4 procesora. Svaki procesor treba dobiti podjednak komad mreže. 
Uočite razliku u VTK zapisu paralelne mreže. Paralelna mreža se zapisuje
 "po procesorima".

*Zadatak 2*. 
Konstruirajte neuniformnu YaspGrid mrežu na kvadratu (-1,1)x(-1,1).
Korak mreže mora biti za x = -1 jednak h=0.01, a za x=0 imamo h=0.1.
Između -1 i 0 korak mreže linearno raste. Od nule do 1 korak linearno
pada tako da je za x=1, h=0.01.

Korak mreže se jednako ponaša i u y smjeru. Koristiti odgovarajući 
konstruktor YaspGrid klase. 

