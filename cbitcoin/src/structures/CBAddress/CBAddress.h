//
//  CBAddress.h
//  cbitcoin
//
//  Created by Matthew Mitchell on 03/05/2012.
//  Copyright (c) 2012 Matthew Mitchell
//  
//  This file is part of cbitcoin.
//
//  cbitcoin is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  cbitcoin is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//  
//  You should have received a copy of the GNU General Public License
//  along with cbitcoin.  If not, see <http://www.gnu.org/licenses/>.

/**
 @file
 @brief Based upon an ECDSA public key and a network version code. Used for receiving bitcoins. Inherits CBVersionChecksumBytes.
 @details Here is a diagram of how a bitcoin address is structured created by Alan Reiner, developer of Bitcoin Armory (http://bitcoinarmory.com/):
 \image html CBAddress.png
*/

#ifndef CBADDRESSH
#define CBADDRESSH

//  Includes

#include "CBVersionChecksumBytes.h"
#include "CBNetworkParameters.h"

/**
 @brief Virtual function table for CBAddress.
*/
typedef struct{
	CBVersionChecksumBytesVT base; /**< CBVersionChecksumBytesVT base structure */
}CBAddressVT;

/**
 @brief Structure for CBAddress objects. @see CBAddress.h
*/
typedef struct{
	CBVersionChecksumBytes base; /**< CBVersionChecksumBytes base structure */
} CBAddress;

/**
 @brief Creates a new CBAddress object from a RIPEMD-160 hash.
 @param network A CBNetworkParameters object with the network information.
 @param hash The RIPEMD-160 hash. Must be 20 bytes.
 @param cacheString If true, the bitcoin string for this object will be cached in memory.
 @param events Events for errors.
 @param dependencies Takes the SHA-256 function for the checksum.
 @returns A new CBAddress object.
 */
CBAddress * CBNewAddressFromRIPEMD160Hash(CBNetworkParameters * network,u_int8_t * hash,bool cacheString,CBEvents * events,CBDependencies * dependencies);
/**
 @brief Creates a new CBAddress object from a base-58 encoded string.
 @param self The CBAddress object to initialise.
 @param string The base-58 encoded CBString.
 @param cacheString If true, the bitcoin string for this object will be cached in memory.
 @param events Events for errors.
 @param dependencies Takes the SHA-256 function for the checksum.
 @returns A new CBAddress object. Returns NULL on failure such as an invalid bitcoin address.
 */
CBAddress * CBNewAddressFromString(CBString * string,bool cacheString,CBEvents * events,CBDependencies * dependencies);

/**
 @brief Creates a new CBAddressVT.
 @returns A new CBAddressVT.
 */
CBAddressVT * CBCreateAddressVT(void);
/**
 @brief Sets the CBAddressVT function pointers.
 @param VT The CBAddressVT to set.
 */
void CBSetAddressVT(CBAddressVT * VT);

/**
 @brief Gets the CBAddressVT. Use this to avoid casts.
 @param self The object to obtain the CBAddressVT from.
 @returns The CBAddressVT.
 */
CBAddressVT * CBGetAddressVT(void * self);

/**
 @brief Gets a CBAddress from another object. Use this to avoid casts.
 @param self The object to obtain the CBAddress from.
 @returns The CBAddress object.
 */
CBAddress * CBGetAddress(void * self);

/**
 @brief Initialises a CBAddress object from a RIPEMD-160 hash.
 @param self The CBAddress object to initialise.
 @param network A CBNetworkParameters object with the network information.
 @param hash The RIPEMD-160 hash. Must be 20 bytes.
 @param cacheString If true, the bitcoin string for this object will be cached in memory.
 @param events Events for errors.
 @param dependencies Takes the SHA-256 function for the checksum.
 @returns true on success, false on failure.
 */
bool CBInitAddressFromRIPEMD160Hash(CBAddress * self,CBNetworkParameters * network,u_int8_t * hash,bool cacheString,CBEvents * events,CBDependencies * dependencies);
/**
 @brief Initialises a CBAddress object from a base-58 encoded string.
 @param self The CBAddress object to initialise.
 @param string The base-58 encoded CBString.
 @param cacheString If true, the bitcoin string for this object will be cached in memory.
 @param events Events for errors.
 @param dependencies Takes the SHA-256 function for the checksum.
 @returns true on success, false on failure.
 */
bool CBInitAddressFromString(CBAddress * self,CBString * string,bool cacheString,CBEvents * events,CBDependencies * dependencies);

/**
 @brief Frees a CBAddress object.
 @param self The CBAddress object to free.
 */
void CBFreeAddress(CBAddress * self);

/**
 @brief Does the processing to free a CBAddress object. Should be called by the children when freeing objects.
 @param self The CBAddress object to free.
 */
void CBFreeProcessAddress(CBAddress * self);
 
//  Functions

#endif