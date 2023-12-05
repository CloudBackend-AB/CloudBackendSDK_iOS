/*
     Copyright © CloudBackend AB 2020 - 2022.
*/

#ifndef INCLUDE_CBE_OBJECT_H_
#define INCLUDE_CBE_OBJECT_H_
#import "CBEIOS/Item.h"

// #include <string>
// #include <vector>

// #include "CBE/Item.h"
#include "CBEIOS/Stream.h"
// #include "CBE/Types.h"
 #include "CBEIOS/delegate/object/MoveDelegate.h"
 #include "CBEIOS/delegate/object/RenameDelegate.h"
 #include "CBEIOS/delegate/object/RemoveDelegate.h"

#include "CBEIOS/delegate/AclDelegate.h"
#include "CBEIOS/delegate/DownloadDelegate.h"
#include "CBEIOS/delegate/DownloadBinaryDelegate.h"
#include "CBEIOS/delegate/DownloadStreamDelegate.h"
#include "CBEIOS/delegate/UploadStreamDelegate.h"
#include "CBEIOS/delegate/UpdateKeyValuesDelegate.h"
#include "CBEIOS/delegate/GetStreamsDelegate.h"
#include "CBEIOS/delegate/ShareDelegate.h"
#include "CBEIOS/delegate/UnShareDelegate.h"
#include "CBEIOS/delegate/PublishDelegate.h"
#include "CBEIOS/delegate/UnpublishDelegate.h"
#include "CBEIOS/delegate/UnsubscribeDelegate.h"
// #include "CBE/delegate/Error.h"
// #include "CBE/delegate/object/MoveDelegate.h"
// #include "CBE/delegate/object/RenameDelegate.h"
// #include "CBE/delegate/object/RemoveDelegate.h"

// #include "CBE/util/ErrorInfo.h"
// #include "CBE/util/Exception.h"

// namespace CBI {
// class Object;
// using ObjectPtr = std::shared_ptr<CBI::Object>;
// class ItemEventProtocol;
// using ItemDelegatePtr = std::shared_ptr<ItemEventProtocol>;
// class TransferDownloadEventProtocol;
// using TransferDownloadDelegatePtr =
//                                 std::shared_ptr<TransferDownloadEventProtocol>;
// class TransferUploadEventProtocol;
// using TransferUploadDelegatePtr = std::shared_ptr<TransferUploadEventProtocol>;
// } // namespace CBI

// namespace cbe
// {

@protocol GetAclObjectDelegatePtr <AclDelegatePtr>
@end
@protocol SetAclObjectDelegatePtr <AclDelegatePtr>
@end
 @interface CBEObject : CBEItem {
  }
// /**
//  * @brief holder of a set of data, can represent a table row.
//  *
//  */
// class Object : public cbe::Item
// {
// public:
//   using MoveDelegatePtr = delegate::object::MoveDelegatePtr;
//   /**
//    * to relocate an object to a different container.
//    *
//    * @param destinationContainerId the id number of the container moving to.
//    * @param delegate  Pointer to a delegate::object::MoveDelegate instance
//    *                  that is implemented by the user.
//    */
//   void move(cbe::ContainerId      destinationContainerId,
//             MoveDelegatePtr       delegate);
-(void) move:(CBEObjectId) destinationContainerId
        delegate:(id<MoveObjectDelegatePtr>) delegate;

//   using RenameDelegatePtr = delegate::object::RenameDelegatePtr;
//   /**
//    * Rename object:
//    * @param name string name of the object.
//    * @param delegate  Pointer to a delegate::object::RenameDelegate instance
//    *                  that is implemented by the user.
//    */
//   void rename(const std::string &name, RenameDelegatePtr delegate);
-(void) rename:   (NSString*)                   name
        delegate: (id<RenameObjectDelegatePtr>) delegate;

//   using RemoveDelegatePtr = delegate::object::RemoveDelegatePtr;
//   /**
//    * Remove the object from cloud and locally
//    * @param delegate  Pointer to a delegate::object::RemoveDelegate instance
//    *                  that is implemented by the user.
//    */
//   void remove(RemoveDelegatePtr delegate);
-(void) remove:(id<RemoveObjectDelegatePtr>) delegate;

//   using DownloadDelegatePtr = delegate::DownloadDelegatePtr;
//   /**
//    * Download the object to local path of a directory
//    *
//    * @param path to where it will be downloaded. String to end with "/".
//    * @param delegate  Pointer to a delegate::DownloadDelegate instance
//    *                  that is implemented by the user.
//    */
//   void download(const std::string&   path,
//                 DownloadDelegatePtr  delegate);
/* SDKCBE-288 */
// -(void) downloadWithPath:(NSString*) path
//         delegate:(id<DownloadObjectDelegatePtr>) delegate;
//   using DownloadBinaryDelegatePtr = delegate::DownloadBinaryDelegatePtr;
//   /**
//    * Download object with binary data and passes it to the delegate.
//    * This data will be loaded on the memory heap.
//    * \note You are responsible for calling delete on it on the heap,
//    * though this may change in the future.
//    *
//    * @param delegate  Pointer to a delegate::DownloadBinaryDelegate instance
//    *                  that is implemented by the user.
//    */
//   void download(DownloadBinaryDelegatePtr delegate);

// -(void) download: (id<DownloadBinaryObjectDelegatePtr>) delegate;

//   using DownloadStreamDelegatePtr = delegate::DownloadStreamDelegatePtr;
//   /**
//    * Download a stream of an Object to local filesystem.
//    *
//    * @param path path to folder you want to download the stream to.
//    * String to end with "/".
//    * @param stream Get which stream you want by first calling getStream and
//    * then choose which one to download.
//    * @param delegate  Pointer to a delegate::DownloadStreamDelegate instance
//    *                  that is implemented by the user.
//    */
//   void downloadStream(const std::string&          path,
//                       cbe::Stream                 stream,
//                       DownloadStreamDelegatePtr   delegate);
// -(void) downloadStream: (NSString*)                     path
//         stream:         (CBEStream*)                    stream
//         delegate:       (id<DownloadStreamObjectDelegatePtr>) delegate;
//   using UploadStreamDelegatePtr = delegate::UploadStreamDelegatePtr;
//   /**
//    * Uploads a file to a new or existing stream attached to this object.
//    * You will need to call getStreams() again to identify all streams.
//    *
//    * @param path local path of file to upload.
//    * @param streamId If the stream id already exists, it will be
//    * overwritten.
//    * @param delegate Gets called when the upload is complete
//    * or if there was an error.
//    */
//   void uploadStream(const std::string&        path,
//                     cbe::StreamId             streamId,
//                     UploadStreamDelegatePtr   delegate);
// -(void) uploadStream: (NSString*)                         path
//         streamId:     (uint64_t)                          streamId
//         delegate:     (id<UploadStreamObjectDelegatePtr>) delegate;

//   using UpdateKeyValuesDelegatePtr = delegate::UpdateKeyValuesDelegatePtr;
//   /**
//    * Adds key/value pair data to the object.
//    * \note Existing key will be overwritten, otherwise created.
//    *
//    * @param delegate  Pointer to a delegate::UpdateKeyValuesDelegate instance
//    *                  that is implemented by the user.
//    * @param keyValues Optional map of key/value pairs (metadata).
//    */
//   void updateKeyValues(UpdateKeyValuesDelegatePtr delegate,
//                        KeyValues                  keyValues = KeyValues{});
-(void) updateKeyValues: (id<UpdateKeyValuesObjectDelegatePtr>) delegate
        keyValues: (NSDictionary*)                        keyValues;
//   using GetStreamsDelegatePtr = delegate::GetStreamsDelegatePtr;
//   /**
//    * Returns the streams attached to the Object.
//    * Use <code>object.streams()</code> after this
//    * call to use the streams e.g. in downloadStream.
//    * This method must be re-called if you upload more streams,
//    * see @c uploadStream()
//    * @param delegate  Pointer to a delegate::GetStreamsDelegate instance
//    *                  that is implemented by the user.
//    */
//   void getStreams(GetStreamsDelegatePtr delegate);
-(void) getStreams: (id<GetStreamsDelegatePtr>) delegate;

//   using Streams = std::vector<cbe::Stream>;
//   /**
//    * @brief Returns the currently loaded stream / streams attached to the
//    *        object.
//    * If you upload a new stream with @c uploadStream(),
//    * you must call getStreams() again to get the new/updated streams.
//    * \note If @c getStreams() has not been called, then @c streams() returns an
//    * empty Streams object.
//    */
//   Streams streams() const;
- (NSArray*) streams;
//   /**
//    * Returns the mime type of the object. \n
//    * E.g.  application/pdf, audio/wav, image/jpg, text/xml, video/mp4 etc.
//    */
//   std::string getMimeType() const;
- (NSString*) getMimeType;
//   /**
//    * Returns the binary length/size of the object in Bytes.
//    */
//   uint64_t length() const;
- (uint64_t) length;
//   /**
//    * Returns the Object type currently: Other | GroupInvite | ShareInvite
//    */
//   cbe::object_t getObjectType() const;
- (CBEObjectType) getObjectType;
//   /**
//    * Returns all the key/values in a map.
//    */
//   cbe::KeyValues keyValues();
- (NSDictionary*) keyValues;

//   using SetAclDelegatePtr = delegate::AclDelegatePtr;
//   /**
//    * Set the Access control list for the object.
//    * @param aclMap  The desired @ref cbe::Permission "permission" for current
//    *                object.
//    * @param delegate  Pointer to a delegate::AclDelegate instance that is
//    *                  implemented by the user.
//    */
//   void setAcl(cbe::AclMap       aclMap,
//               SetAclDelegatePtr delegate);
- (void) setAcl:(NSDictionary*)aclMap delegate:(id<SetAclObjectDelegatePtr>) delegate;

//   using GetAclDelegatePtr = delegate::AclDelegatePtr;
//   /**
//    * get the Access Control List for the Object.
//    * @param delegate  Pointer to a delegate::AclDelegate instance
//    *                  that is implemented by the user.
//    */
//   void getAcl(GetAclDelegatePtr delegate);
-(void) getAcl:(id<GetAclObjectDelegatePtr>) delegate;

//   using ShareDelegatePtr = delegate::ShareDelegatePtr;
//   /**
//    * Share Object to a user. Notifies the user that a share has occured so that
//    * the user can check what permissions the have been given. Sharing gives read
//    * permissions as of right now but might change in the future.
//    * @param toUserGroup takes a user id or group id (lastly named is for the
//    * future) and share to.
//    * @param description names the specific share between you and the user/group.
//    * @param delegate  Pointer to a delegate::ShareDelegatePtr instance
//    *                  that is implemented by the user.
//    */
//   void share(cbe::UserId       toUserGroup,
//              std::string       description,
//              ShareDelegatePtr  delegate);
-(void) share:       (CBEUserId)            toUserGroup
        description: (NSString*)            description
        delegate:    (id<ShareDelegatePtr>) delegate;

//   using UnShareDelegatePtr = delegate::UnShareDelegatePtr;
//   /**
//    * unShare the object to a specific shareId created when sharing. Each share
//    * is unique between user/group and the one sharing. This is represented with
//    * a unique share id.
//    * @param shareId is as mentioned the unique id for a share between the owner
//    * and other user/group.
//    * @param delegate  Pointer to a delegate::UnShareDelegate instance
//    *                  that is implemented by the user.
//    */
//   void unShare(cbe::ShareId shareId, UnShareDelegatePtr delegate);
-(void) unShare:        (CBEUserId)              toUserGroup
        delegate:       (id<UnShareDelegatePtr>) delegate;
//   using PublishDelegatePtr = delegate::PublishDelegatePtr;
//   /**
//    * Publishes an object to a user.
//    * @param security A cbe::Access enum
//    * @param privacy A cbe::WebShareVisibility enum
//    * @param description Description
//    * @param password Password
//    * @param publishDelegate Gets notified when the object has been published
//    * (or if there was an error)
//    */
//   void publish(cbe::PublishAccess      security,
//                cbe::PublishVisibility  privacy,
//                std::string             description,
//                std::string             password,
//                PublishDelegatePtr      publishDelegate);
-(void) publish:     (CBEPublishAccess)       security
        privacy:     (CBEPublishVisibility)   privacy
        description: (NSString*)              description
        password:    (NSString*)              password
        delegate:    (id<PublishDelegatePtr>) delegate;

//   using UnpublishDelegatePtr = delegate::UnpublishDelegatePtr;
//   /**
//    * Unpublishes this object.
//    * @param publishDelegate Gets notified when the object has been unpublished
//    * (or if there was an error)
//    */
//   void unpublish(UnpublishDelegatePtr publishDelegate);
-(void) unpublish:(id<UnpublishDelegatePtr>) delegate;

//   using UnsubscribeDelegatePtr = delegate::UnsubscribeDelegatePtr;
//   /**
//    * Unsubscribes from this object.
//    * @param subscribeDelegate Gets notified when the object has been
//    * unsubscribed (or if there was an error)
//    */
//   void unsubscribe(UnsubscribeDelegatePtr subscribeDelegate);
-(void) unsubscribe:(id<UnsubscribeDelegatePtr>) delegate;
//   //url to item
//   std::string url();
//   Object(cbe::DefaultCtor);

 - (id) initWith:(void*) cbiPeerPtr;
  - (void*) getCBIPeerPtrVoid;
// private:
//   struct Impl;
//   Impl& getImpl() const;

//   friend class CloudBackend;
//   friend class Container;
//   Object(CBI::ObjectPtr cbiPeerPtr);
//   CBI::Object& getCbiPeer() const;
// }; // class Object

// } // namespace cbe
@end
#endif // INCLUDE_CBE_OBJECT_H_
