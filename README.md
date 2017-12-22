# php7 more class
php7 ext

# Support
php7+

# Install
```
// shell command line
# /usr/local/php/bin/phpize
# ./configure -with-php-config=/usr/local/php/bin/php-config
# make
# make install
```
```
// edit php.ini file
add 'extension=pmc.so'
```

# Documentation
```
class PmcUtil
```

# Example
```
php -r 'var_dump(new PmcUtil());'
```