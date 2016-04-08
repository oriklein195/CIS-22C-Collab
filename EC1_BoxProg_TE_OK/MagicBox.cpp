/** @file MagicBox.cpp */
#include "MagicBox.h"

template < class ItemType >
MagicBox < ItemType >::MagicBox()
{
	PlainBox < ItemType >();
	firstItemStored = false;	// Box has no magic initially
}   // end default constructor

template < class ItemType >
MagicBox < ItemType >::MagicBox(const ItemType & theItem)
{
	firstItemStored = false;	// Box has no magic initially

	setItem(theItem);
	// Box has magic now
}   // end constructor

template < class ItemType >
void MagicBox < ItemType >::setItem(const ItemType & theItem)
{
	if (!firstItemStored)
	{
		PlainBox < ItemType >::setItem(theItem);
		fi rstItemStored = true;	// Box now has magic
	}	// end if
}   // end setItem