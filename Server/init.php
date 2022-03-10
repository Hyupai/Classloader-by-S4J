<?php
//api url filter
if(strpos($_SERVER['REQUEST_URI'],"init.php")){
    require_once 'Utils.php';
    PlainDie();
}

set_include_path(get_include_path() . PATH_SEPARATOR . 'phpseclib');


include 'DB.php';
include 'Utils.php';
include 'Crypter.php';