//
// Created by ruansheng on 17/12/22.
//

#ifdef HAVE_PMC_UTIL_H
#include "pmc_util.h"
#endif

zend_class_entry *pmc_util_ce;

/** {{{ yaf_config_methods
*/
zend_function_entry pmc_util_methods[] = {
        PHP_ME(pmc_util, get, NULL)
        {NULL, NULL, NULL}
};
/* }}} */

/** {{{ proto public Yaf_Config_Ini::valid(void)
*/
PHP_METHOD(util) {
    php_printf("hello util!");
}
/* }}} */

PMC_STARTUP_FUNCTION(util){
        zend_class_entry ce;

        INIT_CLASS_ENTRY(ce, "PmcUtil", pmc_util_methods);
        pmc_util_ce = zend_register_internal_class(&ce);

        return SUCCESS;
}