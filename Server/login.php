<?php

include 'init.php';

//initialization
$crypter = Crypter::init();
$privatekey = readFileData("Keys/PrivateKey.prk");

function tokenResponse($data, $keyaes){
    
     global $crypter, $privatekey;
    if($keyaes == "" || $keyaes == NULL) {
        
    $keyaes = "SAMUELFORJULIANA";
    $data = toJson($data);
    $datahash = sha256($data);
    $acktoken = array(
        "Data" => profileEncrypt($data, $datahash),
        "Sign" => toBase64($crypter->signByPrivate($privatekey, $data)),
        "Hash" => $datahash
    );
   
    return EncryptMyEggs(toBase64(toJson($acktoken)), $keyaes);
    
    } else {
        
        if($keyaes == "original") {
            
            // original return
            
             $data = toJson($data);
    $datahash = sha256($data);
    $acktoken = array(
        "Data" => profileEncrypt($data, $datahash),
        "Sign" => toBase64($crypter->signByPrivate($privatekey, $data)),
        "Hash" => $datahash
    );
    return toBase64(toJson($acktoken));
        
         } else {
        
    $data = toJson($data);
    $datahash = sha256($data);
    $acktoken = array(
        "Data" => profileEncrypt($data, $datahash),
        "Sign" => toBase64($crypter->signByPrivate($privatekey, $data)),
        "Hash" => $datahash
    );
    
    
    $semireturn = EncryptMyEggs(toJson($acktoken), "SAMUELFORJULIANA");
    $return2 = EncryptMyEggs($semireturn, $keyaes);
    $return = toBase64($return2);
    return $return;
   
     }
    }
   
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
$uname = mysqli_real_escape_string($conn, $data["pop"]);
if($uname == null || preg_match("([a-zA-Z0-9]+)", $uname) === 0){
    $ackdata = array(
        "SamuelForJuliana" => "Failed",
        "MessageString" => "Invalid Username",
        "SubscriptionLeft" => "0"
    );
    PlainDie(tokenResponse($ackdata, ""));
}

//Password Validator
$pass = mysqli_real_escape_string($conn, $data["pap"]);
if($pass == null || !preg_match("([a-zA-Z0-9]+)", $pass) === 0){
    $ackdata = array(
        "SamuelForJuliana" => "Failed",
        "MessageString" => "Invalid Password",
        "SubscriptionLeft" => "0"
    );
    PlainDie(tokenResponse($ackdata, ""));
}


$query = $conn->query("SELECT * FROM `clientes` WHERE `Username` = '".$uname."' AND `Password` = '".$pass."'");
if($query->num_rows < 1){
    $ackdata = array(
        "SamuelForJuliana" => "Failed",
        "MessageString" => "Username or Password are Incorrects!",
        "SubscriptionLeft" => "0"
    );
    PlainDie(tokenResponse($ackdata, ""));
}

$res = $query->fetch_assoc();

$uidup = $data["pup"];

if($res["UID"] == NULL){
    $query = $conn->query("UPDATE `clientes` SET `UID` = '$uidup' WHERE `Username` = '".$uname."' AND `Password` = '".$pass."'");
}

if($res["UID"] != $uidup) {
    $ackdata = array(
        "SamuelForJuliana" => "Failed",
        "MessageString" => "Your Device was changed!",
        "SubscriptionLeft" => "0"
    );
    PlainDie(tokenResponse($ackdata, ""));
}


/// --- no classloader ---- ///

if($data["c"] == "no") {
    
$generateaeskey = genKeyAES();
$query = $conn->query("UPDATE `clientes` SET `tempaeskey` = '$generateaeskey' WHERE `Username` = '".$uname."' AND `Password` = '".$pass."'");
    
$ackdata = array(
    
    "SamuelForJuliana" => "Success",
    "MessageString" => "",
    "myaeskey" => EncryptByS4J($generateaeskey),
);

echo tokenResponse($ackdata, "");


/// -------------------------------------------------------------/////
} else if($data["c"] == "yes"){
    
   //// ---- verify the AES key ------ //// 
    $aeskeyfromuser = $data["k"];
    if($aeskeyfromuser != $res["tempaeskey"]) {
         $ackdata = array(
        "SamuelForJuliana" => "Failed",
        "MessageString" => "Invalid AES Key",
        "SubscriptionLeft" => "0"
    );
    PlainDie(tokenResponse($ackdata, ""));
    }
    
    $loader = readFileData("Classloader.apk");
    $lib32 = readFileData("libMyLibName32.so");
    $lib64 = readFileData("libMyLibName64.so");
    $lib8664 = readFileData("libMyLibName86_64.so");
    
    $ackdata = array(
    
    "SamuelForJuliana" => "Success",
    "MessageString" => "",
    "Classloader" => toBase64($loader),
    "ClassloaderName" => genKeyAES() . ".apk",
    "Lib1" => toBase64($lib32),
    "Lib2" => toBase64($lib64),
    "Lib3" => toBase64($lib8664),
    "Vencimento" => "2022-03-14 00:15",
    "Usuario" => $res["Username"],
    "Senhaa" => EncryptByS4J($res["Password"]),
    
);

echo tokenResponse($ackdata, $res["tempaeskey"]);

/// -------------------------------------------------------------/////
    
} else if($data["c"] == "old") {
  
    //// ---- verify the AES key ------ //// 
    $aeskeyfromuser = $data["k"];
    if($aeskeyfromuser != $res["tempaeskey"]) {
         $ackdata = array(
        "SamuelForJuliana" => "Failed",
        "MessageString" => "Invalid AES Key",
        "SubscriptionLeft" => "0"
    );
    PlainDie(tokenResponse($ackdata, $res["tempaeskey"]));
    }
    

    
    $ackdata = array(
    
    "SamuelForJuliana" => "Success",
    "MessageString" => "",
 
    
);

echo tokenResponse($ackdata, $res["tempaeskey"]);
  
    
/// -------------------------------------------------------------/////   
} else {
    
    
     $ackdata = array(
    
    "SamuelForJuliana" => "Failed",
    "MessageString" => "Invalid classloader parameter",

);

echo tokenResponse($ackdata, "");


}


