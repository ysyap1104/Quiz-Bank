/***************************************************

Name: Yap Yung Seng

ID: 1141128589

Email: yungseng1314@hotmail.com; Phone: 0102032628

***************************************************/



#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LList : public ListInterface<ItemType>
{
private:
   Node<ItemType>* headPtr;

   int itemCount;
   Node<ItemType>* getNodeAt(int position) const;

public:
   LList();
   LList(const LList<ItemType>& aList);
   virtual ~LList();

   bool isEmpty() const;
   int getLength() const;
   bool insert(int newPosition, const ItemType& newEntry);
   bool erase(int position);
   void clear();
   ItemType retrieve(int position) const throw(PrecondViolatedExcep);
   void randomize();
   void setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep);
   bool sortInsertDesc(const ItemType& newEntry);

}; // end LList

#include "LList.cpp"
#endif
