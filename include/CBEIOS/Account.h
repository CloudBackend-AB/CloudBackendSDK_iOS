/*
      Copyright © CloudBackend AB 2020 - 2022.
 */

#ifndef INCLUDE_CBEIOS_ACCOUNT_H_
#define INCLUDE_CBEIOS_ACCOUNT_H_
#import <Foundation/Foundation.h>

//#include <string>
//#include <vector>
//#include <map>

//#include "CBE/Types.h"
 #include "CBEIOS/Container.h"
// #include "CBE/Database.h"

// namespace CBI {
// class Account;
// using AccountPtr = std::shared_ptr<CBI::Account>;
// } // namespace CBI

// namespace cbe
// {
/**
 * @brief login account information
 * 
 */
@interface CBEAccount : NSObject {

}
//TODO add back in missing functons.  Hide init on AccountHidden
  /** Returns the account id of the user. */
  - (uint64_t) userId;

  /** Returns the username of the account. */
  - (NSString*) username ;

  /** Returns the password of the account. */
   - (NSString*) password ;

  /** Returns the tenant admin of the account 
   * and owner of the tenant group database. */
   - (NSString*) source ;

  /** Returns the given name of the user. */
   - (NSString*) firstName ;

  /** Returns the surname of the user. */
   - (NSString*) lastName ;

//  - (void) setCBIPeer:(void*) cbiPeerPtr;
  - (id) initWith:(void*) cbiPeerPtr;
//- (instancetype)init NS_UNAVAILABLE;

  /** Returns the rootContainer for the account. */
  -(CBEContainer*) rootContainer;
//   cbe::Container rootContainer() ;

//   /** Returns the libContainerId for the account. For more information about
//    * libContainers see documentation. */
//   cbe::ContainerId    libContainerId() ;

//   /** Returns the rootContainerId for the account. */
//   cbe::ContainerId    rootDriveId() ;

//   /** Returns a std::map of databases available for the account. */
//   cbe::DataBases databases() ;


//   explicit operator bool() ;
// private:
//   struct Impl;
//   std::shared_ptr<Impl> pImpl{};


//   friend class CloudBackend;
//   Account(CBI::AccountPtr cbiPeerPtr);
//   /**
//    * Provides a reference to the peer object.
//    */
//   CBI::Account& getCbiPeer() ;
//} // class Account

//} // namespace cbe
@end
#endif // INCLUDE_CBE_ACCOUNT_H_
