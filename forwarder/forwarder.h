/*
 * Copyright (C) 2018-2019 Xinyu Ma, Zhiyi Zhang
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v3.0. See the file LICENSE in the top level
 * directory for more details.
 */

// NOTES: Any other modules except face should ONLY include this file.

#ifndef FORWARDER_FORWARDER_H
#define FORWARDER_FORWARDER_H

#include "face.h"

#ifdef __cplusplus
extern "C" {
#endif

/**@defgroup NDNFwd Forwarder
 * @brief A lite forwarder.
 */

/** @defgroup NDNFwdForwarder Forwarder Core
 * @ingroup NDNFwd
 * @{
 */

void
ndn_forwarder_init(void);

//add a face into face table
int
ndn_forwarder_register_face(ndn_face_intf_t* face);

//remove a face from face table, pit and fib
int
ndn_forwarder_unregister_face(ndn_face_intf_t* face);

//add a route into fib
int
ndn_forwarder_add_route(ndn_face_intf_t* face, uint8_t* prefix, size_t length);

//remove a route from fib
int
ndn_forwarder_remove_route(ndn_face_intf_t* face, uint8_t* prefix, size_t length);

//remove all routes of a fib entry.
int
ndn_forwarder_remove_all_routes(uint8_t* prefix, size_t length);

//receive a packet from face
int
ndn_forwarder_receive(ndn_face_intf_t* face, const uint8_t* packet, size_t length);

//register a prefix
int
ndn_forwarder_register_prefix(uint8_t* prefix,
                              size_t length,
                              ndn_on_data_func on_data,
                              ndn_on_timeout_func on_timeout,
                              void* userdata);

//unregister a prefix
int
ndn_forwarder_unregister_prefix(uint8_t* prefix, size_t length);

//express an interest
int
ndn_forwarder_express_interest(const uint8_t* interest,
                               size_t length,
                               ndn_on_interest_func on_interest,
                               void* userdata);

//produce a data
int
ndn_forwarder_put_data(const uint8_t* data, size_t length);

/*@}*/

#ifdef __cplusplus
}
#endif

#endif // FORWARDER_FORWARDER_H
