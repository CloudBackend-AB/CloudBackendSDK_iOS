/*
     Copyright © CloudBackend AB 2020 - 2022.
*/

#ifndef INCLUDE_CBE_ITEM_H_
#define INCLUDE_CBE_ITEM_H_
#import <Foundation/Foundation.h>

// #include <thread>
// #include <mutex>
// #include <map>
// #include <string>
// #include <vector>
 #include "CBEIOS/Types.h"
// #include "CBE/Utility.h"

// namespace CBI {
// class Item;
// using ItemPtr = std::shared_ptr<CBI::Item>;
// class ItemEventProtocol;
// using ItemDelegatePtr = std::shared_ptr<ItemEventProtocol>;
// class PublishEventProtocol;
// using PublishDelegatePtr = std::shared_ptr<PublishEventProtocol>;
// class SubscribeEventProtocol;
// using SubscribeDelegatePtr = std::shared_ptr<SubscribeEventProtocol>;
// } // namespace CBI

// namespace cbe
// {

/**
 * @brief set made up of Container and Object
 *
 * Class for an Item.
 * This is class is the base class of Objects and Containers.
 */
@interface CBEItem : NSObject {
}
//class Item {
 //public:

  /** a map of share ids for this item */
  //CBEShareIds getShareIds  ;

  /** Get the shareId by reference of userId */
//  CBEShareId getShareFromUserId(CBEUserId userId);

  /** Get the userId reference of shareId */
//  - (CBEUserId) getUserFromShareId:(CBEUserId) shareId;

  /** the ACL of the item */
  - (NSString*) aclTag;

//wrapcbe this was causing memory issues.  Why?
  /** A item text description where applicable */
 // - (NSString*) description;

  /** Returns an Items id. */
  - (CBEItemId) id  ;

  /** Returns the id of the Items parent container id. */
  - (CBEContainerId)    parentId  ;

  /** Returns the id of the Items old parent container id
   * in cases where the item has just been moved. */
  - (CBEContainerId)    oldParentId  ;

  /** Returns the name of the item. */
  - (NSString*) name  ;

  /** Returns the path if applicable. */
   - (NSString*) path  ;

  /** Returns the owner id number. */
  - (CBEUserId) ownerId  ;

  /** Returns which drive number the container resides on. */
  - (CBEContainerId)    driveId  ;

  /** Returns the username of the owner if applicable. */
   - (NSString*) username  ;

  /** if the query did get a resultset. */
  - (bool) idLoaded  ;

  /** if data was loaded */
  - (bool) dataLoaded  ;

  /** Returns the creation date in Unix epoch time. */
  - (CBEDate) created  ;

  /**Returns the updated date/time in Unix epoch time*/
  - (CBEDate) updated  ;

  /** Returns the deleted date, if applicable (i.e. is in the bin), in Unix epoch time*/
  - (CBEDate) deleted  ;

  /** Container or Object, see enum in Types.h */
  - (CBEItemType) type  ;

  /**
   * Checks if it has published info and if @c getPublished returns a valid object.
   */
//  - (bool) hasPublished  ;

  /**
   * Gets the publish information
   * @sa hasPublished
   */
 // - (Publish) getPublished  ;

  /**
   * Checks if it has subscribe info and if @c getSubscribe returns a valid object.
   */
//  - (bool) hasSubscribe  ;

  /**
   * Gets the subscribe information
   * @sa hasSubscribe
   */
//  - (Subscribe) getSubscribe  ;

 // bool operator<(  CBEItem& rh)  ;

  /**
   * Retrieve the map of the permissions the users and groups for this item.
   */
//  - (AclMap) aclMap  ; 

  //! @cond Doxygen_Suppress
  //Item(CBEDefaultCtor);
  /// This function should not be called as it will not continue to be public
  /// and any call made on the item will fail.
  //~Item();
  //! @endcond

  //explicit operator bool()  ;

  - (id) initWith:(void*) cbiPeerPtr;

//   friend std::ostream& operator<<(std::ostream& os,   Item& item);
// private:
//   struct Impl;
//   std::shared_ptr<Impl> pImpl{};

//   friend class CloudBackend;
//   friend class Container;
//   friend class Object;
//   friend class PublishManager;
//   friend class QueryResult;
//   friend class SubscribeManager;
//  Item(CBI::ItemPtr cbiPeerPtr);
//  CBI::Item&  getCbiPeer()  ;

// protected:
//   Item(std::shared_ptr<Impl> pImpl);

//   template <class ImplT>
//   ImplT& castImpl()  ;
// private:
//   CBI::ItemPtr&       getCbiPeerPtr();
//     CBI::ItemPtr& getCbiPeerPtr()  ;

//   friend std::ostream& operator<<(std::ostream& os,   Item& item);
// }; // class Item

// CBEItemType operator|(CBEItemType lh, CBEItemType rh);

// std::ostream& operator<<(std::ostream& os, ItemType itemType);


// } // namespace cbe
// namespace XAPI
@end
#endif // INCLUDE_XAPI_ITEM_H_
