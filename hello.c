#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#define PHP_MY_EXTENSION_VERSION "1.0"
#define PHP_MY_EXTENSION_EXTNAME "hello"

PHP_FUNCTION(hello_world);
PHP_FUNCTION(hello);

extern zend_module_entry hello_module_entry;
#define phpext_my_extension_ptr &hello_module_entry

static zend_function_entry hello_functions[] = {
    PHP_FE(hello_world, NULL)
    PHP_FE(hello, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry hello_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_MY_EXTENSION_EXTNAME,
    hello_functions,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_MY_EXTENSION_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

ZEND_GET_MODULE(hello)

PHP_FUNCTION(hello_world)
{
    RETURN_STRING("Hello, World!", 1);
}

PHP_FUNCTION(hello)
{
    char *name;
    size_t name_len;
    zend_bool *format = 1;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s|b", &name, &name_len, &format) == FAILURE) {
        RETURN_NULL();
    }

    if (format && name_len) {
        name = estrndup(name, name_len);
        php_strtolower(name, name_len);
        *name = toupper(*name);
    }

    char *out;
    size_t out_len = spprintf(&out, 0, "Hello, %s!", name);

    RETVAL_STRINGL(out, out_len, 0);

    if (format && name_len) {
        efree(name);
    }

    return;
}