#include "context_store.h"
#include <stdlib.h>
#include <string.h>

typedef struct {
    context_key key;
    context_value value;
} context_entry;

static const context_entry DELETED_ENTRY = {
    .key="THIS ENTRY DOES NO LONGER EXIST",
    .value=""
};

typedef struct {
    context_id id;
    unsigned int size;
    unsigned int memsize;
    context_entry* entries;
} context_bag;

const static unsigned int bags_growth    = 8;
const static unsigned int context_growth = 16;

static context_id next_context_id = 0;
static bool context_initialized = false;

static context_bag* my_bags;
static unsigned int number_of_bags;
static unsigned int memsize_of_bags;

#define index(id) id - 1

static void grow_bags(){
    unsigned int growth = sizeof(context_bag) * bags_growth;
    my_bags = realloc(my_bags, memsize_of_bags + growth);
    memsize_of_bags += growth;
}

static void grow_context(context_bag* context){
    unsigned int growth = sizeof(context_entry*) * context_growth;
    context->entries = realloc(context->entries, context->memsize + growth);
    context->memsize += growth;
}

static void grow_context_if_needed(context_bag* context){
    if (context->size >= context->memsize){
        grow_context(context);
    }
}


void context_init(){
    next_context_id = 1;

    number_of_bags = 0;
    my_bags = NULL;
    grow_bags();

    context_initialized = true;
}

void context_teardown(){

    for (size_t i = 0; i < number_of_bags; i++) {
        free(my_bags[i].entries);
    }

    free(my_bags);
    my_bags = NULL;
    number_of_bags = 0;
    memsize_of_bags = 0;
    next_context_id = 0;
    context_initialized = false;
}

bool context_is_initialized(){
    return context_initialized;
}

context_id create_context() {
    context_id id = next_context_id++;

    if (1 + number_of_bags >= memsize_of_bags)
        grow_bags();

    my_bags[index(id)].id = id;
    my_bags[index(id)].size = 0;
    my_bags[index(id)].memsize = 0;
    my_bags[index(id)].entries = NULL;

    grow_context(&my_bags[index(id)]);

    return id;
}

unsigned int context_size(context_id context){
    return my_bags[index(context)].size;
}

void context_clear(context_id context){
    if (0 < my_bags[index(context)].size){
        free(my_bags[index(context)].entries);
        my_bags[index(context)].size = 0;
        my_bags[index(context)].memsize = 0;
        my_bags[index(context)].entries = NULL;
    }
}

void context_write(context_id context, context_key key, context_value value){
    context_remove(context, key);
    grow_context_if_needed(&my_bags[index(context)]);

    my_bags[index(context)].entries[my_bags[index(context)].size++] =
        (context_entry) {
        .key   = key,
        .value = value
    };
}

context_value context_read( context_id context,
                            context_key key,
                            context_value default_value){


    for (size_t i = 0; i < my_bags[index(context)].size; i++) {
        if (0 == strcmp(key, my_bags[index(context)].entries[i].key)){
            return my_bags[index(context)].entries[i].value;
        }
    }
    return default_value;
}

void context_remove(context_id context, context_key key){
    for (size_t i = 0; i < my_bags[index(context)].size; i++) {
        if (0 == strcmp(key, my_bags[index(context)].entries[i].key)){
            my_bags[index(context)].entries[i] = DELETED_ENTRY;
        }
    }
}
