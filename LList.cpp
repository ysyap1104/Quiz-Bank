/***************************************************

Name: Yap Yung Seng

ID: 1141128589

Email: yungseng1314@hotmail.com; Phone: 0102032628

***************************************************/


#include "LList.h"  // Header file
#include <cassert>
#include <cstdlib>
#include <ctime>

template<class ItemType>
LList<ItemType>::LList() : headPtr(NULL), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LList<ItemType>::LList(const LList<ItemType>& aList) : itemCount(aList.itemCount)
{
   Node<ItemType>* origChainPtr = aList.headPtr;

   if (origChainPtr == NULL)
      headPtr = NULL;
   else
   {
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      Node<ItemType>* newChainPtr = headPtr;
      origChainPtr = origChainPtr->getNext();
      while (origChainPtr != NULL)
      {
         ItemType nextItem = origChainPtr->getItem();
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         newChainPtr->setNext(newNodePtr);
         newChainPtr = newChainPtr->getNext();
         origChainPtr = origChainPtr->getNext();
      }

      newChainPtr->setNext(NULL);
   }
}

template<class ItemType>
LList<ItemType>::~LList()
{
   clear();
}  // end destructor

template<class ItemType>
bool LList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
bool LList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert)
   {
      // Create a new node containing the new entry
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

      // Attach new node to chain
      if (newPosition == 1)
      {
         // Insert new node at beginning of chain
         newNodePtr->setNext(headPtr);
         headPtr = newNodePtr;
      }
      else
      {
         // Find node that will be before new node
         Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);

         // Insert new node after node to which prevPtr points
         newNodePtr->setNext(prevPtr->getNext());
         prevPtr->setNext(newNodePtr);
      }  // end if

      itemCount++;  // Increase count of entries
   }  // end if

   return ableToInsert;
}  // end insert

template<class ItemType>
bool LList<ItemType>::erase(int position)
{
   bool ableToerase = (position >= 1) && (position <= itemCount);
   if (ableToerase)
   {
      Node<ItemType>* curPtr = NULL;
      if (position == 1)
      {
         // erase the first node in the chain
         curPtr = headPtr; // Save pointer to node
         headPtr = headPtr->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         Node<ItemType>* prevPtr = getNodeAt(position - 1);

         // Point to node to delete
         curPtr = prevPtr->getNext();

         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prevPtr->setNext(curPtr->getNext());
      }  // end if

      // Return node to system
      curPtr->setNext(NULL);
      delete curPtr;
      curPtr = NULL;

      itemCount--;  // Decrease count of entries
   }  // end if

   return ableToerase;
}  // end erase

template<class ItemType>
void LList<ItemType>::clear()
{
   while (!isEmpty())
      erase(1);
}  // end clear

template<class ItemType>
ItemType LList<ItemType>::retrieve(int position) const throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      string message = "retrieve() called with an empty list or ";
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message));
   }  // end if
}  // end retrieve


template<class ItemType>
Node<ItemType>* LList<ItemType>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= itemCount) );

   // Count from the beginning of the chain
   Node<ItemType>* curPtr = headPtr;
   for (int skip = 1; skip < position; skip++)
      curPtr = curPtr->getNext();

   return curPtr;
}  // end getNodeAt

template<class ItemType>
void LList<ItemType>::randomize()
{
    for (int i=1;i<=itemCount;i++)
    {
        int random=(rand()%itemCount)+1;
        Node<ItemType>* curPtr = NULL;
        if (random == 1)
        {
            curPtr = getNodeAt(random); // Save pointer to node
            headPtr = headPtr->getNext();
            itemCount--;
            insert(itemCount+1,curPtr->getItem());
        }
        else{
            Node<ItemType>* prevPtr = getNodeAt(random - 1);
            curPtr = prevPtr->getNext();
            prevPtr->setNext(curPtr->getNext());
            itemCount--;
            insert(itemCount+1,curPtr->getItem());
        }
        curPtr->setNext(NULL);
        delete curPtr;
        curPtr = NULL;
    }
}

template<class ItemType>
void LList<ItemType>::setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      nodePtr->setItem(newEntry);
   }
   else
   {
      string message = "setEntry() called with an invalid position.";
      throw(PrecondViolatedExcep(message));
   }  // end if
}  // end setEntry

template<typename ItemType>
bool LList<ItemType>::sortInsertDesc(const ItemType& newEntry)
{
    if(isEmpty())
    {
        insert(1,newEntry);
    }else{
        if(newEntry>retrieve(1))
        {
            insert(1,newEntry);
        }else{
            int i=1;
            while(i<getLength())
            {
                if(newEntry<=retrieve(i) && (newEntry>=retrieve(i+1)) )
                {
                    insert(i+1,newEntry);
                    return true;
                }
                i=i+1;
            }
            insert(i+1,newEntry);
        }
    }
    return true;
}
