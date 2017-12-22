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
define("ES_EXT_BUILD_ID", "100");
function showEsDocument();
class ElasticSearchClient
    const VERSION = "1.0.0";
    public static $connect_timeout = 1;  // unit:s  default:1s
    public static $request_timeout = 2;  // unit:s  default:2s
    private $host = "";
    private $port = "";
    public $message = "";
    public function __construct(string $host, int $port)
    public function add($params) : mixed
    public function remove($params) : mixed
    public function update($params) : mixed
    public function get($params) : mixed
    public function search($params) : mixed
    public function getMessage() : string
    public static function setConnectTimeout($seconds) : bool
    public static function setRequestTimeout($seconds) : bool

```

# Example
```
var_dump(ES_EXT_BUILD_ID);

// echo this extension Documentation
showEsDocument();

var_dump(ElasticSearchClient::VERSION);

$client = new ElasticSearchClient("demo.es.com", 9023);

var_dump($client);

// setConnectTimeout static method example
ElasticSearchClient::setConnectTimeout(3);

// setRequestTimeout static method example
ElasticSearchClient::setRequestTimeout(4);

// add method example
$params = [    // es server auto create id
   'index' => 'estest',
   'type' => 'demo1',
   'body' => ['a' => '1', 'b'=> 2]
];
$params = [    // user defined id
   'index' => 'estest',
   'type' => 'demo1',
   'id' => 123,  // 'id' => '123',  id type is int or string
   'body' => ['a' => '1', 'b'=> 2]
];
$ret = $client->add($params);
if(!$ret) {
    $message = $client->getMessage();
}

// remove method example
$params = [
   'index' => 'estest',
   'type' => 'demo1',
   'id' => 123,  // 'id' => '123',  id type is int or string
];
$ret = $client->remove($params);
if(!$ret) {
    $message = $client->getMessage();
}

// update method example
$params = [
   'index' => 'estest',
   'type' => 'demo1',
   'id' => 123,  // 'id' => '123',  id type is int or string
   'body' => [   // body is elasticsearch update api identical
       "doc" => [
            "name" : "new_name"
        ],
        "doc_as_upsert" => true
   ]
];

$params['body'] = [
    "script" => [
        "inline" => "ctx._source.counter += count",
        "params" => [
            "count" => 4
        ]
     ]
];

/*
$params['body'] = [
    "script" => [
        "inline" => "ctx._source.counter += count",
        "params" => [
            "count" => 4
        ]
     ]
];
*/

$ret = $client->update($params);
if(!$ret) {
    $message = $client->getMessage();
}

// get method example
$params = [
   'index' => 'estest',
   'type' => 'demo1',
   'id' => 123,  // 'id' => '123',  id type is int or string
];
$ret = $client->get($params);
if(!$ret) {
    $message = $client->getMessage();
}

// search method example
$params = [
   'index' => 'estest',
   'type' => 'demo1',
    'body' => [
        'query' => [
            'match_all' => []
        ],
        'from' => 2,
        'size' => 10,
        'sort' => [
            'price' => [
            'order' => 'asc'
            ]
    	]
    ]
];
$ret = $client->search($params);
if(!$ret) {
    $message = $client->getMessage();
}
```