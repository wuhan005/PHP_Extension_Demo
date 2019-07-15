/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2018 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_Eggplant.h"

/* If you declare any globals in php_Eggplant.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(Eggplant)
*/

/* True global resources - no need for thread safety here */
static int le_Eggplant;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("Eggplant.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_Eggplant_globals, Eggplant_globals)
    STD_PHP_INI_ENTRY("Eggplant.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_Eggplant_globals, Eggplant_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_Eggplant_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_Eggplant_compiled)
{
	char *arg = NULL;
	size_t arg_len, len;
	zend_string *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS(), "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	strg = strpprintf(0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "Eggplant", arg);

	RETURN_STR(strg);
}

PHP_FUNCTION(get_eggplant)
{	
	long times;
	zend_bool backValue;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l|b", &times, &backValue) == FAILURE) {
        RETURN_NULL();
    }

	zend_string *backStr = zend_string_init("", 0, 0);

	zend_string *eggplant = zend_string_init("Eggplant! ", strlen("Eggplant! "), 0);

	for(long i = 0; i < times; i++){
		 backStr = strpprintf(0, "%s%s", ZSTR_VAL(backStr), ZSTR_VAL(eggplant));
	}
	if(backValue == 1){
		php_printf("%s", ZSTR_VAL(backStr));
		RETURN_TRUE;
	}else{
		RETURN_STR(backStr);
	}
	
}
ZEND_BEGIN_ARG_INFO(arginfo_get_eggplant, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(get_any)
{
	long times;
	zend_string *repeatStr;
	zend_bool backValue;


	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "Sl|b", &repeatStr, &times, &backValue) == FAILURE) {
        RETURN_NULL();
    }

	zend_string *backStr = zend_string_init("", 0, 0);

	for(long i = 0; i < times; i++){
		 backStr = strpprintf(0, "%s%s", ZSTR_VAL(backStr), ZSTR_VAL(repeatStr));
	}
	if(backValue == 1){
		php_printf("%s", ZSTR_VAL(backStr));
		RETURN_TRUE;
	}else{
		RETURN_STR(backStr);
	}
}
ZEND_BEGIN_ARG_INFO(arginfo_get_any, 0)
ZEND_END_ARG_INFO()

PHP_FUNCTION(get_eggplant_emoji){
	RETURN_STR(zend_string_init("🍆", strlen("🍆"), 0))
}

PHP_FUNCTION(eggplant_info){
	RETURN_STR()
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/



/* {{{ php_Eggplant_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_Eggplant_init_globals(zend_Eggplant_globals *Eggplant_globals)
{
	Eggplant_globals->global_value = 0;
	Eggplant_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(Eggplant)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(Eggplant)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(Eggplant)
{
#if defined(COMPILE_DL_EGGPLANT) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(Eggplant)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(Eggplant)
{
	php_info_print_table_start();
	//php_info_print_table_header(2, "Eggplant support", "enabled");
	php_info_print_table_row(2, "Eggplant support", "enabled");
	php_info_print_table_row(2, "这是一个并没有什么卵用的 PHP 扩展。", "但是你已经安装好了！！");
	php_info_print_table_row(2, "Author", "E99p1ant");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ Eggplant_functions[]
 *
 * Every user visible function must have an entry in Eggplant_functions[].
 */
const zend_function_entry Eggplant_functions[] = {
	PHP_FE(confirm_Eggplant_compiled, NULL)		/* For testing, remove later. */
	PHP_FE(get_eggplant, arginfo_get_eggplant)
	PHP_FE(get_any, arginfo_get_any)
	PHP_FE(get_eggplant_emoji, NULL)
	PHP_FE_END	/* Must be the last line in Eggplant_functions[] */
};
/* }}} */

/* {{{ Eggplant_module_entry
 */
zend_module_entry Eggplant_module_entry = {
	STANDARD_MODULE_HEADER,
	"Eggplant",
	Eggplant_functions,
	PHP_MINIT(Eggplant),
	PHP_MSHUTDOWN(Eggplant),
	PHP_RINIT(Eggplant),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(Eggplant),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(Eggplant),
	PHP_EGGPLANT_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_EGGPLANT
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(Eggplant)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
