/*
  Copyright © CloudBackend AB 2022.
 */

#ifndef INCLUDE_CBE_SUBSCRIBE_H_
#define INCLUDE_CBE_SUBSCRIBE_H_
#import <Foundation/Foundation.h>
#include "CBEIOS/Types.h"
// #include <string>

// #include "CBE/Types.h"

// namespace CBI {
// class Subscribe;
// using SubscribePtr = std::shared_ptr<CBI::Subscribe>;
// } // namespace CBI
@interface CBESubscribe : NSObject {
// @private
  // void * pImpl;
}


// namespace cbe {

// /**
//  * @brief to subscribe to a \c published Item.
//  * 
//  */
// class Subscribe {
// public:
//   /**
//    * Gets the date as unix epoch number
//    */
//   cbe::Date getDate() const;
-(CBEDate) getDate;
//   /**
//    * Gets the title
//    */
//   std::string getTitle() const;
-(NSString*) getTitle;
//   /**
//    * Gets the description
//    */
//   std::string getDescription() const;
-(NSString*) getDescription;
//   /**
//    * Gets the password
//    */
//   std::string getPassword() const;
-(NSString*) getPassword;
//   /**
//    * Gets the security 
//    * \see Types.h for cbe::PublishAccess enum
//    */
//   cbe::PublishAccess getSecurity() const;
-(CBEPublishAccess) getSecurity;
//   /**
//    * Gets the privacy 
//    * \see Types.h for cbe::PublishVisibility
//    */
//   cbe::PublishVisibility getPrivacy() const;
-(CBEPublishVisibility) getPrivacy;
//   /**
//    * Gets the subscribe id number
//    */
//   cbe::SubscribeId getSubscribeId() const;
-(CBESubscribeId) getSubscribeId;
//   /**
//    * Gets the publish id number
//    */
//   cbe::PublishId getPublishId() const;
-(CBEPublishId) getPublishId;
//   /**
//    * Gets the owner id number
//    */
//   cbe::UserId getOwner() const;
-(CBEUserId) getOwner;
//   /**
//    * Unsubscribe
//    */
//   void unsubscribe();
-(void) unsubscribe;

//   Subscribe(cbe::DefaultCtor);
//   ~Subscribe();

//   explicit operator bool() const;
// private:
//   struct Impl;
//   std::shared_ptr<Impl> pImpl{};

//   friend class CloudBackend;
//   friend class Item;
//   Subscribe(CBI::SubscribePtr cbiSubscribePtr);
//   CBI::Subscribe& getCbiPeer() const;
// }; // class Subscribe
// } // namespace cbe
- (id) initWith:(void*) cbiPeerPtr;
@end
#endif  // INCLUDE_CBE_SUBSCRIBE_H_
