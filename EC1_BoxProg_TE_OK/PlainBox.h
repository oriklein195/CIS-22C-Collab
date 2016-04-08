/** @file PlainBox.h */
#ifndef _PLAIN_BOX
#define _PLAIN_BOX
#include "BoxInterface.h"

// Indicates this is a template defi nition // Declaration for the class PlainBox
template <class ItemType> class PlainBox : public BoxInterface<ItemType>{
private:

public:
	// Default constructor
	PlainBox();

	// Parameterized constructor
	PlainBox(const ItemType & theItem);

	// Mutator method that can change the value of the data fi eld
	void setItem(const ItemType & theItem);

	// Accessor method to get the value of the data fi eld
	ItemType getItem() const;

};  // end PlainBox

	// Include the implementation fi le
#endif