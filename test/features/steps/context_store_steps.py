from should_dsl import *
import ctypes
target = ctypes.cdll.LoadLibrary(".build/magpie_test.dylib")
target.context_read.restype = ctypes.c_char_p

default_key   = 'specific_key'
default_value = 'an entry'
default_default_value = 'This is a default value'



@given(u'the context_store is initialized')
def step_impl(context):
    if not target.context_is_initialized():
        target.context_init();

    target.context_is_initialized() |should| be(1)


@given(u'I know the context_id for my argument data')
def step_impl(context):
    context_id = target.create_context();

    context_id |should_not| be(0)
    context_id |should_not| be(None)

    context.context_id = context_id


@given(u'my context is empty')
def step_impl(context):
    target.context_clear(context.context_id)
    target.context_size(context.context_id) |should| be(0)


@given(u'an entry is stored at a specific key in my context')
def step_impl(context):
    target.context_write(context.context_id, default_key, default_value)


@given(u'no entry is stored in the context for a specific key')
def step_impl(context):
    target.context_read(
            context.context_id,
            default_key,
            'EMPTY') |should| equal_to('EMPTY')




@when(u'I store a value at a specific key to my context')
def step_impl(context):
    target.context_write(context.context_id, default_key, default_value)


@when(u'I read that key from my context')
def step_impl(context):
    context.value_from_target = target.context_read(
            context.context_id,
            default_key,
            default_default_value
    )


@when(u'I remove that key from the context')
def step_impl(context):
    target.context_remove(context.context_id, default_key)


@when(u'I create the first context')
def step_impl(context):
    context.context_id = target.create_context();




@then(u'the context_id should be 1')
def step_impl(context):
    context.context_id |should| equal_to(1)


@then(u'my context should contain a single entry')
def step_impl(context):
    target.context_size(context.context_id) |should| be(1)


@then(u'I should get the stored value')
def step_impl(context):
    context.value_from_target |should| equal_to(default_value)


@then(u'I should get the default value')
def step_impl(context):
    context.value_from_target |should| equal_to(default_default_value)
