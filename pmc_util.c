//
// Created by ruansheng on 17/12/22.
//

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "standard/php_string.h" /* for php_basename */
#include "Zend/zend_exceptions.h" /* for zend_exception_get_default */

#include "php_pmc.h"
#include "pmc_util.h"

zend_class_entry *pmc_util_ce;

PMC_STARTUP_FUNCTION(util);
PHP_METHOD(pmc_util, show);

/** {{{ yaf_config_methods
*/
zend_function_entry pmc_util_methods[] = {
        PHP_ME(pmc_util, show, NULL, ZEND_ACC_PUBLIC)
        {NULL, NULL, NULL}
};
/* }}} */

/** {{{ proto public Yaf_Config_Ini::valid(void)
*/
PHP_METHOD(pmc_util, show) {
    php_printf("hello util!");
}
/* }}} */

PMC_STARTUP_FUNCTION(util){
        zend_class_entry ce;

        INIT_CLASS_ENTRY(ce, "PmcUtil", pmc_util_methods);
        pmc_util_ce = zend_register_internal_class(&ce);

        return SUCCESS;
}