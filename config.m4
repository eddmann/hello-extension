PHP_ARG_ENABLE(hello, whether to enable hello support,
[ --enable-hello   Enable hello support])

if test "$PHP_HELLO" = "yes"; then
    AC_DEFINE(HAVE_HELLO, 1, [Whether you have hello])
    PHP_NEW_EXTENSION(hello, hello.c, $ext_shared)
fi