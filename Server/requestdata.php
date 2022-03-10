<?php

include 'init.php';

//initialization
$crypter = Crypter::init();
$privatekey = readFileData("Keys/PrivateKey.prk");

function tokenResponse($data){
    global $crypter, $privatekey;
    $data = toJson($data);
    $datahash = sha256($data);
    $acktoken = array(
        "Data" => profileEncrypt($data, $datahash),
        "Sign" => toBase64($crypter->signByPrivate($privatekey, $data)),
        "Hash" => $datahash
    );
    $antvoid = toBase64(toJson($acktoken));
    return EncryptMyEggs(toBase64(toJson($acktoken)), "SAMUELFORJULIANA");
}

//token data
$token = fromBase64($_POST['token']);
$tokarr = fromJson($token, true);

//Data section decrypter
$encdata = $tokarr['Data'];
$decdata = trim($crypter->decryptByPrivate($privatekey, fromBase64($encdata)));
$data = fromJson($decdata);

//Hash Validator
$tokhash = $tokarr['Hash'];
$newhash = sha256($encdata);

if (strcmp($tokhash, $newhash) == 0) {
    PlainDie();
}



//Username Validator
$uname = $data["key"];
if($uname == null || preg_match("([A-Z0-9]+)", $uname) === 0){
    $ackdata = array(
        "Status" => "Failed",
        "MessageString" => "Invalid Main Parameter",
        "SubscriptionLeft" => "0"
    );
    PlainDie(tokenResponse($ackdata));
}



if($uname != "LPNGuhasd654823nskmfdsdoijdskajsdh7248739486"){
    $ackdata = array(
        "Status" => "Failed",
        "MessageString" => "Invalid Main Value",
        "SubscriptionLeft" => "0"
    );
    PlainDie(tokenResponse($ackdata));
}


$ackdata = array(
    "SamuelForJuliana" => "Success",
    "url1" => EncryptByS4J("https://hyupaimods.net/server/login.php"),
    "MessageString" => "",

  
);

echo tokenResponse($ackdata);
