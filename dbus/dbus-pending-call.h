/* -*- mode: C; c-file-style: "gnu" -*- */
/* dbus-pending-call.h Object representing a call in progress.
 *
 * Copyright (C) 2002, 2003 Red Hat Inc.
 *
 * Licensed under the Academic Free License version 1.2
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
#if !defined (DBUS_INSIDE_DBUS_H) && !defined (DBUS_COMPILATION)
#error "Only <dbus/dbus.h> can be included directly, this file may disappear or change contents."
#endif

#ifndef DBUS_PENDING_CALL_H
#define DBUS_PENDING_CALL_H

#include <dbus/dbus-macros.h>
#include <dbus/dbus-types.h>
#include <dbus/dbus-connection.h>

DBUS_BEGIN_DECLS;

typedef void (* DBusPendingCallNotifyFunction) (DBusPendingCall *pending,
                                                void            *user_data);

DBusPendingCall* _dbus_pending_call_new          (DBusConnection   *connection,
                                                  dbus_uint32_t     reply_serial);

void         dbus_pending_call_ref           (DBusPendingCall               *pending);
void         dbus_pending_call_unref         (DBusPendingCall               *pending);
void         dbus_pending_call_set_notify    (DBusPendingCall               *pending,
                                              DBusPendingCallNotifyFunction  function,
                                              void                          *user_data,
                                              DBusFreeFunction               free_user_data);
dbus_bool_t  dbus_pending_call_get_completed (DBusPendingCall               *pending);
DBusMessage* dbus_pending_call_get_reply     (DBusPendingCall               *pending);



DBUS_END_DECLS;

#endif /* DBUS_PENDING_CALL_H */
