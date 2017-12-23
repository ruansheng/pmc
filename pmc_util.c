//
// Created by ruansheng on 17/12/22.
//

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "php_pmc.h"
#include "pmc_util.h"

zend_class_entry *pmc_util_ce;

PHP_METHOD(pmc_util, show);

/** {{{ pmc_util_methods
*/
zend_function_entry pmc_util_methods[] = {
        PHP_ME(pmc_util, show, NULL, ZEND_ACC_PUBLIC)
        {NULL, NULL, NULL}
};
/* }}} */

/** {{{ proto public PmcUtil::show()
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