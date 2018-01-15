_add_test(noncopyable_test)
_add_test(ignore_unused_test)
target_compile_options(ignore_unused_test PRIVATE -Werror=unused-variable)
