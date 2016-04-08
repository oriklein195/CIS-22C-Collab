/** @file PlainBox.cpp */
#include "PlainBox.h"

template < class ItemType > PlainBox<ItemType>::PlainBox()
{
	item = null;
}   // end default constructor

template < class ItemType > PlainBox < ItemType >::PlainBox(const ItemType &theItem)
{
	item = theItem;
}   // end constructor

template < class ItemType> void PlainBox < ItemType >::setItem(const ItemType &theItem)
{
	item = theItem;
}   // end setItem

template < class ItemType > ItemType PlainBox < ItemType >::getItem() const
{
	return item;
}   // end getItem