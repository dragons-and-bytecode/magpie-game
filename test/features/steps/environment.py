import ctypes
target = ctypes.cdll.LoadLibrary(".build/magpie_test.dylib")

def after_scenario(context, scenario):
    print("Quack\n")
    target.context_teardown();
