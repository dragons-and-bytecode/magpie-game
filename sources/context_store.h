#pragma once

/**
 * @file
 *
 * A context store is a very simple indexed store, that allows for library
 * functions, to keep context in relation to a given context object, which
 * should not need to hold the data, the function uses in conjunction with
 * it.
 *
 * In other words, the context store is a simple way for functions, to remember
 * secondary data for a given context.
 *
 * > Unfortunatelly, there is no elegant way (I know of), that allows for
 * > arbirary types, to be compared in equality of data in C.
 * >
 * > This implies, that the context type itself can not be used as a key to
 * > the context store, since it can never been proven to be exact.
 * >
 * > Given this, the user of the context store needs to hold an identifier,
 * > created by the store itself, to retreave the desired context from the
 * > store again.
 * >
 * > The advise is, to attach this id to the context object given, or pre-create
 * > this id, when the context key is created.
 *
 *
 */

typedef unsigned int context_id;
typedef void* context_value;
typedef char* context_key;

/**
 * initializes the context store and key generation.
 *
 * This should be called, before any other context method is called, and
 * ideally be called only once in the applications lifecycle.
 *
 * A second call to ``context_init()`` would effectively void all context keys
 * generated before.
 *
 */
void context_init();

/**
 * creates a new unique id, and reserves it on the context store, to be used
 * later.
 *
 * All ids are guaranteed to be unique since the last call to
 * ``context_init()``.
 *
 * @return a newly created key
 */
context_id create_context();

/**
 * Stores the given value at the given key for the context, referenced via the
 * given context id.
 *
 * @param context the context to use
 * @param key     the key at which to store the value
 * @param value   the value to store
 */
void context_write(context_id context, context_key key, context_value value);

/**
 * Reads the value at the given key from the given context and tries to return
 * it. If the value cannot be found, the given default_value is returned
 * instead.
 *
 *
 * @param  context       the context to use
 * @param  key           the key at which to read data from the context
 * @param  default_value the value to return, if the given key could not be
 *                       found.
 * @return               the value found in the context at the goven key, or the
 *                       default value.
 */
context_value context_read( context_id context,
                            context_key key,
                            context_value default_value);
