//
// Created by ruansheng on 17/12/22.
//

#ifndef PHP7_PMC_UTIL_H
#define PHP7_PMC_UTIL_H

extern zend_class_entry *pmc_util_ce;

PMC_STARTUP_FUNCTION(util);

PHP_METHOD(util);

#endif //PHP7_PMC_UTIL_H
