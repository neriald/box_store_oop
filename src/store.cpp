#include "store.h"
#include <sstream>
store::store(string _desc, double _cap)
{
    description = _desc;
    capacity= _cap;
    sumVol=0;
}
void store::add(Box* b)
{
    if(sumVol+b->getVolume()<=capacity)
    {
        boxes.push_back(b);
        sumVol+= b->getVolume();
    }
    else
    {
        ostringstream s;
        s << b->getLabel() << " too large - only " << capacity-sumVol << " free space." << endl;
        delete b;
        throw CapacityError(s.str());
    }

}

void store::clear()
{
    for(vector<Box*>::iterator it=boxes.begin(); it !=boxes.end(); it++)
        delete (*it);
    boxes.clear();
    sumVol=0;
}

void store::remove(string name)
{
    for(vector<Box*>::iterator it=boxes.begin(); it!=boxes.end(); it++)
    {
        if((*it)->getLabel() == name)
        {
            sumVol-= (*it)->getVolume();
            delete *it;
            boxes.erase(it);
            return;
        }
    }

}

Box& store::operator[](unsigned i)
{
    ostringstream s;
     s << i;
     if(i==0 || i>boxes.size())
        throw IndexError("item no." + s.str() +" not found");
     return *boxes[i-1];
}



ostream& operator << (ostream &out, const store &s)
{
    out<< s.getDesc() << ", Total Capacity= " << s.getCapacity() << ", Free Space= " << s.capacity-s.sumVol << ":" << endl;

    int i=1;
    for(vector<Box*>::const_iterator it=s.boxes.begin(); it!=s.boxes.end(); it++, i++)
    {
        out << i << ". " << (*it)->getLabel() << ", Volume= " << (*it)->getVolume() << endl;
    }
    return out;
}
