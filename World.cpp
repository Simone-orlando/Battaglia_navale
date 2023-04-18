#include "World.h"
#include<iostream>
using namespace std;

World::World()
{
    set_world();
}

Point& World::get_point(int raw, int col)
{
	return *world[raw][col];
}




const void World::display()
{
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            world[i][j]->print(); /*Mi permette di usare le navi come punti
                                    ma comunque di usare le funzioni sovrascritte
                                    della classe nave*/
            cout << "|";
        }
        cout << endl;
    }
    cout << endl;
}

const void World::set_world()
{
    //Crea il mondo, uso new perchè world 
    // è una matrice di pointer.
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            world[i][j] = new Point();
        }
    }
}
const bool World::put_ship(int raw, int col, int length, int dir, Ship& ship)
{
    /*dir =0 va a destra (aumenta le colonne) dir = 1 va in basso(aumenta le righe
    si puo aggiungere sinistra e in alto.*/
    /*inserisce un punto-nave in (raw, col) e occupa le caselle adiacenti*/
    int occ_cells = world[raw][col]->is_occupied();
    for (int i = 1; i < length; i++)
    {
        occ_cells += world[raw + (i * dir)][col + (i * (1 - dir))]->is_occupied();
        /*Rimane falso (=0) sse tutte le celle analizzate sono false, ovvero nessuna 
        è occupata*/
    }
    if (occ_cells == 0)
    {
        for (int i = 0; i < length; i++)
        {
            delete world[raw + (i * dir)][col + (i * (1 - dir))];
            world[raw + (i * dir)][col + (i * (1 - dir))] = new Ship_point(); 
            /*trasforma i punti in punti-nave*/

            ship.insert_point(*world[raw + (i * dir)][col + (i * (1 - dir))]);
        }
        return true;
    }
    if (occ_cells != 0)
    {
        cout << "Impossibile piazzare la nave, le celle sono occupate \n";
        return false;
    }
    else
        return false;

    /*bisogna ancora implementare il fatto che occupi le celle adiacenti a una nave
    in modo che non si possano mettere navi a fianco.*/
}