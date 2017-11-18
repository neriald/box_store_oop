#include <iostream>
#include "Box.h"
#include "store.h"

using namespace std;
int main()
{
    store store("my home store", 100);
    cout << Box::count()<< endl;

    try
    {
        store.add(new BrickBox("books", "0x000000", 5, 3.5, 4)); //5 x 3.5 x 4
        store.add(new TubeBox("maps", "0x00ff00", 1, 3)); //radius=1, height=3
        store.add(new BubbleBox("moneybox", "0x800080", 1)); //radius=1
        store.add(new BrickBox("jewels", "0xffff00", 2, 2, 2)); //2 x 2 x 2
        store.add(new BrickBox("trinkets", "0x000080", 5, 2, 1)); //5 x 2 x 1
    }
    catch(store::CapacityError &e)
    {
    cout << e.what(); //trinkets too large - only 8.4 free space
    }

    cout << store;

    cout << store[4].getLabel();
    store.remove("moneybox");
    cout << store;
    store.clear();
    cout << store;
    cout << Box::count();



    return 0;
}
