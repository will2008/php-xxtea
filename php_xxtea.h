
#ifndef PHP_XXTEA_H
#define PHP_XXTEA_H

extern zend_module_entry xxtea_module_entry;
#define phpext_xxtea_ptr &xxtea_module_entry

#define PHP_XXTEA_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_XXTEA_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_XXTEA_API __attribute__ ((visibility("default")))
#else
#	define PHP_XXTEA_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(xxtea)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(xxtea)
*/

/* In every utility function you add that needs to use variables 
   in php_xxtea_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as XXTEA_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define XXTEA_G(v) TSRMG(xxtea_globals_id, zend_xxtea_globals *, v)
#else
#define XXTEA_G(v) (xxtea_globals.v)
#endif

#endif	/* PHP_XXTEA_H */

