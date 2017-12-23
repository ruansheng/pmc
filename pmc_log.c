//
// Created by ruansheng on 17/12/22.
//

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "php_pmc.h"
#include "pmc_log.h"

zend_class_entry *pmc_log_ce;

PHP_METHOD(pmc_log, write);

/** {{{ pmc_log_methods
*/
zend_function_entry pmc_log_methods[] = {
        PHP_ME(pmc_log, write, NULL, ZEND_ACC_PUBLIC)
        {NULL, NULL, NULL}
};
/* }}} */

/** {{{ proto public PmcLog::write()
*/
PHP_METHOD(pmc_log, write) {
    php_printf("hello log!");
}
/* }}} */

PMC_STARTUP_FUNCTION(log){
        zend_class_entry ce;

        INIT_CLASS_ENTRY(ce, "PmcLog", pmc_log_methods);
        pmc_log_ce = zend_register_internal_class(&ce);

        return SUCCESS;
}