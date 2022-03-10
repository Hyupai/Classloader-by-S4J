<?php

if(strpos($_SERVER['REQUEST_URI'],"DB.php")){
    require_once 'Utils.php';
    PlainDie();
}

$conn = new mysqli("localhost", "u634180599_hyupai", "t?QacQo6d3", "u634180599_server");
if($conn->connect_error != null){
    die($conn->connect_error);
}