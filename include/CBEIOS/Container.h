/*
     Copyright © CloudBackend AB 2020 - 2022.
*/

#ifndef INCLUDE_CBE_CONTAINER_H_
#define INCLUDE_CBE_CONTAINER_H_

//#import <Foundation/Foundation.h>
#import "CBEIOS/Item.h"
#import "CBEIOS/QueryChain.h"

#import "CBEIOS/delegate/QueryDelegate.h"
#import "CBEIOS/delegate/QueryJoinDelegate.h"
//#import "CBEIOS/Filter.h"

// #include "CBE/Types.h"
 #include "CBEIOS/delegate/container/MoveDelegate.h"
 #include "CBEIOS/delegate/container/RenameDelegate.h"
 #include "CBEIOS/delegate/container/RemoveDelegate.h"
 #include "CBEIOS/delegate/AclDelegate.h"
 #include "CBEIOS/delegate/CreateContainerDelegate.h"
 #include "CBEIOS/delegate/CreateObjectDelegate.h"
// #include "CBE/delegate/Error.h"
 #include "CBEIOS/delegate/PublishDelegate.h"
 #include "CBEIOS/delegate/ShareDelegate.h"
 #include "CBEIOS/delegate/UnpublishDelegate.h"
 #include "CBEIOS/delegate/UnShareDelegate.h"
 #include "CBEIOS/delegate/UnsubscribeDelegate.h"
 #include "CBEIOS/delegate/UploadDelegate.h"

// #include "CBE/util/Context.h"
// #include "CBE/util/ErrorInfo.h"
// #include "CBE/util/Exception.h"

// #include "CBE/Item.h"
// #include "CBE/Object.h"
// #include "CBE/Types.h"
/*
namespace CBI {
class Container;
using ContainerPtr = std::shared_ptr<CBI::Container>;
class ItemEventProtocol;
using ItemDelegatePtr = std::shared_ptr<ItemEventProtocol>;
} // namespace CBI

namespace cbe
{
class QueryChainExt;
class QueryChainSync;

namespace delegate {
  class AclDelegate;
  class ShareDelegate;
  class UnShareDelegate;
}

class Filter;
*/

@protocol GetAclDelegatePtr <AclDelegatePtr>
@end
@protocol SetAclDelegatePtr <AclDelegatePtr>
@end

/**
 * @brief collection of Item, can represent a table.
 *
 */
//class Container : public cbe::Item
//{
  @interface CBEContainer : CBEItem {
  }
//public:
  //using CreateContainerDelegatePtr = delegate::CreateContainerDelegatePtr;
  /**
   * Creates a container inside this container to be used for adding objects.
   * @param name Name of the container to be created.
   * @param delegate Pointer to a delegate::CreateContainerDelegate instance that is
   *                 implemented by the user.
   */
   -(CBEContainer*) createContainer:(NSString*) name
                                  delegate:(id<CreateContainerDelegatePtr>) delegate;

  // using MoveDelegatePtr = delegate::container::MoveDelegatePtr;
  /**
   * Move is used to move container with its content to user specified location
   * e.g. other container or to root container.
   * @param destinationId: id of the container to which it should be moved to.
   * @param delegate Pointer to a delegate::container::MoveDelegate instance
   *                 that is implemented by the user.
   */
//   void move(cbe::ContainerId    destinationId, MoveDelegatePtr delegate);
   -(void) move:(CBEContainerId) destinationId  delegate:(id<MoveContainerDelegatePtr>) delegate;

  // using RenameDelegatePtr = delegate::container::RenameDelegatePtr;
  /**
   * Rename the container.
   * @param name New name of the container.
   * @param delegate Pointer to a delegate::container::RenameDelegate instance
   *                 that is implemented by the user.
   */
   -(void) rename:(NSString*) name  delegate:(id<RenameContainerDelegatePtr>) delegate;

  // using RemoveDelegatePtr = delegate::container::RemoveDelegatePtr;
  /**
   * Removes/deletes the container and all its content.
   * @param delegate Pointer to a delegate::container::RemoveDelegate instance
   *                 that is implemented by the user.
   */
   -(void) remove:(id<RemoveContainerDelegatePtr>) delegate;

  // using CreateObjectDelegatePtr = delegate::CreateObjectDelegatePtr;
  /**
   * Creates an object with indexed tags or indexed tags + non indexed tags.
   * @param name      Name of the object.
   * @param delegate  Pointer to a delegate::CreateObjectDelegate instance
   *                  that is implemented by the user.
   * @param keyValues Optional map of key/value pairs (metadata).
   */
     -(CBEObject*) createObject:(NSString*)name delegate:(id<CreateObjectDelegatePtr>)delegate keyValues:(NSDictionary*)keyValues;

  // cbe::Object createObject(std::string              name,
  //                          CreateObjectDelegatePtr  delegate,
  //                          cbe::KeyValues           keyValues =
  //                                                     cbe::KeyValues{});

  // using UploadDelegatePtr = delegate::UploadDelegatePtr;
  /**
   * Upload object to container with path, the object is instantly returned with
   * a temp. id. Once the respons from the server is called back the object gets
   * updated with the correct unique object id:
   * @param name    local file name; the uploaded object will get the same name
   * @param path    local path to upload from
   * @param delegate  Pointer to a delegate::UploadDelegate instance
   *                  that is implemented by the user.
   */
  // cbe::Object upload(const std::string& name,
  //                    const std::string& path,
  //                    UploadDelegatePtr  delegate);

  /**
   * @param name   name that the uploaded object will get
   * @param length size of file in Bytes
   * @param byteData (char pointer to an array containing the data).
   * @param delegate  Pointer to a delegate::UploadDelegate instance
   *                  that is implemented by the user.
   */
  -(CBEObject*) upload:(NSString*)name
                     length:(uint64_t)length
                     data:(NSData*)data
                     delegate:(id<UploadDelegatePtr>)  delegate;

  // using QueryDelegatePtr = delegate::QueryDelegatePtr;
  /**
   * In line with function
   * CloudBackend::query(ContainerId,QueryDelegatePtr), but with
   * its \p ContainerId parameter excluded.
   * \see CloudBackend::query(ContainerId,QueryDelegatePtr)
   */
  -(CBEQueryChain*) query:(id<QueryDelegatePtr>)  queryDelegate;
  /**
   * In line with function
   * CloudBackend::query(ContainerId,Filter,QueryDelegatePtr), but
   * with its \p ContainerId parameter excluded.
   * \see CloudBackend::query(ContainerId,Filter,QueryDelegatePtr)
   */
  // QueryChain query(Filter           filter,
  //                  QueryDelegatePtr delegate);
  -(CBEQueryChain*) query: (CBEFilter*)           filter
                 delegate: (id<QueryDelegatePtr>) queryDelegate;
 // using QueryJoinDelegatePtr = std::shared_ptr<delegate::QueryJoinDelegate>;
  /**
   * In line with function
   * CloudBackend::query(ContainerId,delegate::QueryJoinDelegatePtr), but with
   * its \p ContainerId parameter excluded.
   * \see CloudBackend::query(ContainerId,delegate::QueryJoinDelegatePtr)
   */
//  QueryChainExt query(delegate::QueryJoinDelegatePtr delegate);
  /**
   * In line with function
   * CloudBackend::query(ContainerId,Filter,delegate::QueryJoinDelegatePtr),
   * but with its \p ContainerId parameter excluded.
   * \see CloudBackend::query(ContainerId,Filter,delegate::QueryJoinDelegatePtr)
   */
  // QueryChainExt query(Filter                          filter,
  //                     delegate::QueryJoinDelegatePtr  delegate);

  /**
   * Queries the container with a given relative path, returns container with
   * objects. \n
   * E.g. /Documents/Pictures will return objects and subContainers for
   * Pictures. \n
   * N.B.: .. or . path options are not available,
   * top down Paths in the container tree are available.
   * @param path container path, e.g. /Documents/Pictures
   * @param delegate  Pointer to a delegate::QueryDelegate instance
   *                  that is implemented by the user.
   */
  // cbe::QueryChain queryWithPath(std::string       relativePath,
  //                               QueryDelegatePtr  delegate);

  /**
   * Search the whole container for tags related to Objects in the container
   * structure. \n
   * E.g. Key = Name, Value Contract/Object/Song => Name:Contract1.
   *
   * Search handles tags in combination of conjunctions of keys and/or key
   * values separated by |. \n
   * E.g. Name:*|Country:Sweden|Country:Norway, this would search for objects
   * with key Name but any value and where key Country is either Sweden or
   * Norway.
   * @param tags is a string of key tags or key:value pairs
   *             that are separated by |.
   * @param delegate  Pointer to a delegate::QueryDelegate instance
   *                  that is implemented by the user.
  */
  // cbe::QueryResult search(std::string tags, QueryDelegatePtr delegate);

  /**
   * Search the whole container for tags related to Objects in the container
   * structure. \n
   * E.g. Key = Name, Value Contract/Object/Song => Name:Contract1.
   *
   * Search handles tags in combination / conjunction of keys and/or key values
   * separated by |. \n
   * E.g. Name:*|Country:Sweden|Country:Norway, this would search for objects
   * with key Name but any value and where key Country is either Sweden or
   * Norway.
   * @param filter is a cbe::Filter on which you can set
   * how you want data to be ordered when searching. \n
   * Remember to set the queryString to be keys/tags
   * or key:value pairs that are separated by |.
   * @param delegate  Pointer to a delegate::QueryDelegate instance
   *                  that is implemented by the user.
  */
  // cbe::QueryResult search(cbe::Filter filter, QueryDelegatePtr delegate);

  
  // using SetAclDelegatePtr = delegate::AclDelegatePtr;
  /**
   * Set the Access Control List \c ACL for the container.
   * For containers set does set the whole container tree,
   * so all its sub items as well.
   * Remember this is  set and not update so every time you set
   * all ids that should be there should be added.
   * @param aclMap    The desired @ref cbe::Permission "permission" for current
   *                  container.
   * @param delegate  Pointer to a delegate::AclDelegate instance
   *                  that is implemented by the user.
   */
  // void setAcl(cbe::AclMap       aclMap,
  //             SetAclDelegatePtr delegate);
- (void) setAcl:(NSDictionary*)aclMap delegate:(id<SetAclDelegatePtr>) delegate;

  // using GetAclDelegatePtr = delegate::AclDelegatePtr;
  
  
  /**
   * get the Access Control List \c ACL of the Container.
   * @param delegate  Pointer to a delegate::AclDelegate instance
   *                  that is implemented by the user.
   */
   -(void) getAcl:(id<GetAclDelegatePtr>) delegate;

  // using ShareDelegatePtr = delegate::ShareDelegatePtr;
  /**
   * Shares a container and its content to a user.  This provides the user the
   * ability to access what has been shared to them via the listAvailableShares
   * command.  To allow users to view and change shared information see \c ACL .
   * \note At present Sharing the container gives the user read permissions for
   * the container and all its sub-items, this might change in the future.
   * @param toUserGroup takes a user id or group id to share to.
   * @param description names the specific share between you and the user/group.
   * @param delegate  Pointer to a delegate::ShareDelegate instance
   *                  that is implemented by the user.
   */
  -(void) share:(CBEUserId)toUserGroup description:(NSString*)description delegate:(id<ShareDelegatePtr>) delegate;
  // void share(cbe::UserId      toUserGroup,
  //            std::string      description,
  //            ShareDelegatePtr delegate);

  // using UnShareDelegatePtr = std::shared_ptr<delegate::UnShareDelegate>;
  /**
   * unShare the container to a specific shareId created when sharing. Each
   * share is unique between user/group and the one sharing. This is represented
   * with a unique share id.
   * @param shareId is as mentioned the unique id for a share between the owner
   * and other user/group.
   * @param delegate  Pointer to a delegate::UnShareDelegate instance
   *                  that is implemented by the user.
   */
    -(void) unShare:(CBEShareId)shareId  delegate:(id<UnShareDelegatePtr>) delegate;

  // void unShare(cbe::ShareId shareId, UnShareDelegatePtr delegate);

  // using PublishDelegatePtr = delegate::PublishDelegatePtr;
  /**
   * Publishes a container and its content to a user.
   * @param security A cbe::Access enum
   * @param privacy A cbe::PublishVisibility enum
   * @param description Description
   * @param password Password
   * @param delegate  Pointer to a delegate::PublishDelegate instance
   *                  that is implemented by the user.
   */
  // void publish(cbe::PublishAccess      security,
  //              cbe::PublishVisibility  privacy,
  //              std::string             description,
  //              std::string             password,
  //              PublishDelegatePtr      delegate);
  -(void) publish:(CBEPublishAccess)security privacy:(CBEPublishVisibility)privacy description:(NSString*)description password:(NSString*)password delegate:(id<PublishDelegatePtr>)delegate;

//  using UnpublishDelegatePtr = delegate::UnpublishDelegatePtr;
  /**
   * Unpublishes this container.
   * @param delegate Gets notified when the container has been
   * unpublished (or if there was an error)
   */
  -(void) unpublish:(id<UnpublishDelegatePtr>) delegate;

//  using UnsubscribeDelegatePtr = delegate::UnsubscribeDelegatePtr;
  /**
   * Unsubscribes from this container.
   * @param delegate Gets notified when the container has been
   * unsubscribed (or if there was an error)
   */
  -(void) unsubscribe:(id<UnsubscribeDelegatePtr>) delegate;

//  Container(cbe::DefaultCtor);
//private:
// wrapcbe Moved internal
  // struct Impl;
  // Impl& getImpl() const;

//wrapcbe todo use hidden in these
  // friend class Account;
  // friend class CloudBackend;
  // friend class Database;
  // friend class Filter;
  // friend class Group;
  // friend class QueryChain;

//wrapcbe replace construct move hidden
  - (id) initWith:(void*) cbiPeerPtr;
  - (void*) getCBIPeerPtrVoid;
//  Container(CBI::ContainerPtr cbiPeerPtr);

 // CBI::Container&   getCbiPeer() const;
//  CBI::ContainerPtr getCbiPeerPtr() const;
//}; // class Container

//} // namespace cbe
@end

#endif // INCLUDE_CBE_CONTAINER_H_
