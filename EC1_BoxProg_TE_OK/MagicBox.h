/** @file MagicBox.h */
#ifndef _MAGIC_BOX
#define _MAGIC_BOX
#include "PlainBox.h"

template < class ItemType >
class MagicBox :public PlainBox < ItemType >
{
private:
	bool firstItemStored;

public:
	MagicBox();
	MagicBox(const ItemType & theItem);

	void setItem(const ItemType & theItem);

};  // end MagicBox


#endif