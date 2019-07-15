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

#ifndef PHP_EGGPLANT_H
#define PHP_EGGPLANT_H

extern zend_module_entry Eggplant_module_entry;
#define phpext_Eggplant_ptr &Eggplant_module_entry

#define PHP_EGGPLANT_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_EGGPLANT_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_EGGPLANT_API __attribute__ ((visibility("default")))
#else
#	define PHP_EGGPLANT_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/*
  	Declare any global variables you may need between the BEGIN
	and END macros here:

ZEND_BEGIN_MODULE_GLOBALS(Eggplant)
	zend_long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(Eggplant)
*/

/* Always refer to the globals in your function as EGGPLANT_G(variable).
   You are encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/
#define EGGPLANT_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(Eggplant, v)

#if defined(ZTS) && defined(COMPILE_DL_EGGPLANT)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif	/* PHP_EGGPLANT_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

PHP_FUNCTION(get_eggplant);
