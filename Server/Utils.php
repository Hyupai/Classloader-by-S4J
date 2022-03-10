<?php

function profileEncrypt($data, $hash){
    $in = myexplode($data);
    $key = myexplode($hash);
    $out = array();
    for ($i = 0; $i < count($in); $i++) {
        $out[$i] = $in[$i] ^ $key[$i % count($key)];
    }
    $out = implode($out);
    return toBase64($out);
}

function profileDecrypt($data, $hash){
    $in = myexplode(fromBase64($data));
    $key = myexplode($hash);
    $out = array();
    for ($i = 0; $i < count($in); $i++) {
        $out[$i] = $in[$i] ^ $key[$i % count($key)];
    }
    return implode($out);
}

function genUname(){
    $seed = myexplode("ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
    $uname = array();
    $size = 0;
    while($size != 18){
        $uname[$size] = $seed[mt_rand(0,count($seed)-1)];
        $size++;
    }
    return implode($uname);
}

function genKeyAES(){
    $seed = myexplode("ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
    $uname = array();
    $size = 0;
    while($size != 16){
        $uname[$size] = $seed[mt_rand(0,count($seed)-1)];
        $size++;
    }
    return implode($uname);
}

function EncryptByS4J($toEnc) {
    
    $sj4classloader1 = str_replace('a', '+', $toEnc); // string velha, string novo
    $sj4classloader2 = str_replace('d', '[', $sj4classloader1); // string velha, string novo
     $sj4classloader25 = str_replace('e', ']', $sj4classloader2); // string velha, string novo
    $sj4classloader3 = str_replace('h', ';', $sj4classloader25); // string velha, string novo
    $sj4classloader4 = str_replace('i', '>', $sj4classloader3); // string velha, string novo
    $sj4classloader5 = str_replace('j', '<', $sj4classloader4); // string velha, string novo
    $sj4classloader6 = str_replace('m', '?', $sj4classloader5); // string velha, string novo
    $sj4classloader7 = str_replace('o', '|', $sj4classloader6); // string velha, string novo
    $sj4classloader8 = str_replace('g', ',', $sj4classloader7); // string velha, string novo
    $sj4classloader9 = str_replace('g', ',', $sj4classloader8); // string velha, string novo
    $sj4classloader10 = str_replace('g', ',', $sj4classloader9); // string velha, string novo

    $sj4classloader11 = str_replace('p', '!', $sj4classloader10); // string velha, string novo
    $sj4classloader12 = str_replace('r', '@', $sj4classloader11); // string velha, string novo
    $sj4classloader13 = str_replace('u', '#', $sj4classloader12); // string velha, string novo
    $sj4classloader14 = str_replace('b', '$', $sj4classloader13); // string velha, string novo
    $sj4classloader15 = str_replace('x', '%', $sj4classloader14); // string velha, string novo

    $sj4classloader16 = str_replace('L', '&', $sj4classloader15); // string velha, string novo
    $sj4classloader17 = str_replace('W', '*', $sj4classloader16); // string velha, string novo
    $sj4classloader18 = str_replace('R', '(', $sj4classloader17); // string velha, string novo
    $sj4classloader19 = str_replace('S', ')', $sj4classloader18); // string velha, string novo
    $sj4classloader20 = str_replace('H', '-', $sj4classloader19); // string velha, string novo

    $sj4classloader21 = str_replace('.', '_', $sj4classloader20); // string velha, string novo
    $sj4classloader22 = str_replace('/', '=', $sj4classloader21); // string velha, string novo
    $sj4classloader23 = str_replace('t', '{', $sj4classloader22); // string velha, string novo
    $sj4classloader24 = str_replace('s', '}', $sj4classloader23); // string velha, string novo

    return $sj4classloader24;

}


function EncryptMyEggs($toEnc, $key) {
    
    return $encrypted = openssl_encrypt($toEnc, 'aes-128-ecb', $key);

}

function genPass(){
    $seed = myexplode("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890");
    $pass = array();
    $size = 0;
    while($size != 8){
        $pass[$size] = $seed[mt_rand(0,count($seed)-1)];
        $size++;
    }
    return implode($pass);
}

function myexplode($str){
    $out = array();
    for ($i = 0; $i < strlen($str); $i++) {
        $out[$i] = substr($str, $i, 1);
    }
    return $out;
}

function getMicro(){
    return explode(' ', microtime())[1];
}

function readFileData($path){
    $file = fopen($path,"r") or die();
    $data = fread($file,filesize($path));
    fclose($file);
    return $data;
}

function isFileExist($path){
    if (file_exists($path)) {
        return 1;
    }
    return 0;
}

function toBase64($data){
    return base64_encode($data);
}

function fromBase64($data){
    return base64_decode($data);
}

function urlsafe_b64encode($string) {
    $data = base64_encode($string);
    $data = $sj4classloader = str_replace(array('+','/','='),array('-','_',''),$data);
    return $data;
}

function urlsafe_b64decode($string) {
    $data = $sj4classloader = str_replace(array('-','_'),array('+','/'),$string);
    $mod4 = strlen($data) % 4;
    if ($mod4) {
        $data .= substr('====', $mod4);
    }
    return base64_decode($data);
}

function toJson($data){
    return json_encode($data);
}

function fromJson($data){
    return json_decode($data, true);
}

function PlainDie($status = ""){
    header('Content-type: text/plain');
    die($status);
}

function sha256($data){
    return strtoupper(hash('sha256', $data));
}

function PublicKeyToBinary($publickey){
    $publickey = $sj4classloader = str_replace("-----BEGIN PUBLIC KEY-----","", $publickey);
    $publickey = $sj4classloader = str_replace("-----END PUBLIC KEY-----","", $publickey);
    $publickey = trim($publickey);
    return fromBase64($publickey);
}

function PrivateKeyToBinary($privatekey){
    $privatekey = $sj4classloader = str_replace("-----BEGIN RSA PRIVATE KEY-----","", $privatekey);
    $privatekey = $sj4classloader = str_replace("-----END RSA PRIVATE KEY-----","", $privatekey);
    $privatekey = trim($privatekey);
    return fromBase64($privatekey);
}

//api url filter
if(strpos($_SERVER['REQUEST_URI'],"Utils.php")){
    PlainDie();
}