/***************************************************

Name: Yap Yung Seng

ID: 1141128589

Email: yungseng1314@hotmail.com; Phone: 0102032628

***************************************************/

#ifndef _LIST_INTERFACE
#define _LIST_INTERFACE

template<class ItemType>
class ListInterface
{
public:
   virtual bool isEmpty() const = 0;
   virtual int getLength() const = 0;
   virtual bool insert(int newPosition, const ItemType& newEntry) = 0;
   virtual bool erase(int position) = 0;
   virtual void clear() = 0;
   virtual ItemType retrieve(int position) const = 0;
   virtual void randomize()=0;
   virtual void setEntry(int position, const ItemType& newEntry) = 0;
   virtual bool sortInsertDesc(const ItemType& newEntry)=0;

}; // end ListInterface
#endif
